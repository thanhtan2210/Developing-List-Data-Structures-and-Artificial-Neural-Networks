/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/*
 * File:   dataloader.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 4:01 PM
 */

#ifndef DATALOADER_H
#define DATALOADER_H
#include "ann/xtensor_lib.h"
#include "ann/dataset.h"

using namespace std;

template <typename DType, typename LType>
class DataLoader
{
public:
  class Iterator;

private:
  Dataset<DType, LType> *ptr_dataset;
  int batch_size;
  bool shuffle;
  bool drop_last;
  /*TODO: add more member variables to support the iteration*/
  int num_batch;
  xt::xarray<int> index;
  xt::svector<Batch<DType, LType>, sizeof(Batch<DType, LType>)> batch;
  int num_samples;
  int m_seed;

public:
  Batch<DType, LType> return_batch(int index) { return this->batch.at(index); }
  DataLoader(Dataset<DType, LType> *ptr_dataset,
             int batch_size, bool shuffle = true,
             bool drop_last = false, int seed = -1) : ptr_dataset(ptr_dataset), batch_size(batch_size), shuffle(shuffle), drop_last(drop_last), m_seed(seed)
  {
    /*TODO: Add your code to do the initialization */

    num_samples = ptr_dataset->len();
    if (batch_size <= num_samples)
    {
      if (shuffle)
      {
        if (m_seed >= 0)
        {
          index = xt::arange<unsigned long>(ptr_dataset->len());
          xt::random::seed(m_seed);
          xt::random::shuffle(index);
        }
        else
        {
          index = xt::arange<unsigned long>(ptr_dataset->len());
          xt::random::shuffle(index);
        }
      }
      else
        index = xt::arange<unsigned long>(ptr_dataset->len());
      // xu li droplas
      num_batch = num_samples / batch_size;
      TensorDataset<DType, LType> *tensor_data = dynamic_cast<TensorDataset<DType, LType> *>(ptr_dataset);
      for (int batch_idx = 0; batch_idx < num_batch; batch_idx++)
      {
        xt::svector<unsigned long> data_shape = tensor_data->get_data_shape();
        xt::svector<unsigned long> label_shape = tensor_data->get_label_shape();
        int index_start_batch = batch_idx * batch_size;
        int index_end_batch;
        if (!drop_last && batch_idx == num_batch - 1)
        {
          index_end_batch = num_samples;
          data_shape[0] = batch_size + num_samples % batch_size;
          label_shape[0] = batch_size + num_samples % batch_size;
        }
        else
        {
          index_end_batch = min((batch_idx + 1) * batch_size, num_samples);
          data_shape[0] = min(batch_size, num_samples - index_start_batch + 1);
          label_shape[0] = min(batch_size, num_samples - index_start_batch + 1);
        }

        xt::xarray<DType> batch_data = xt::zeros<DType>(data_shape);
        xt::xarray<LType> batch_label = xt::zeros<LType>(label_shape);
        for (int i = index_start_batch; i < index_end_batch; i++)
        {
          int shuffle_index = index[i];
          DataLabel<DType, LType> data_label = tensor_data->getitem(shuffle_index);
          if (tensor_data->get_label_shape().size() != 0)
          {
            xt::view(batch_label, i - index_start_batch) = data_label.getLabel();
          }
          xt::view(batch_data, i - index_start_batch) = data_label.getData();
        }
        batch.push_back(Batch<DType, LType>(batch_data, batch_label));
      }
      xt::xarray<DType> data;
      xt::xarray<LType> label;
      batch.push_back(Batch<DType, LType>(data, label));
    }
    else
      num_batch = 0;
  }

  DataLoader<DType, LType> *return_ptrdata()
  {
    return ptr_dataset;
  }

  int get_num_batch() { return num_batch; }
  int get_num_samples() { return num_samples; }
  int get_batch_size() { return batch_size; }

  virtual ~DataLoader() {}

  /////////////////////////////////////////////////////////////////////////
  // The section for supporting the iteration and for-each to DataLoader //
  // START: Section                                                     //
  /////////////////////////////////////////////////////////////////////////

  /*TODO: Add your code here to support iteration on batch*/
  Iterator begin()
  {
    // TODO implement
    return Iterator(this, 0);
  }
  Iterator end()
  {
    // TODO implement
    return Iterator(this, num_batch);
  }

public:
  // TODO implement forech
  class Iterator
  {
  private:
    // TODO implement
    DataLoader<DType, LType> *loader;
    int current_idx;

  public:
    // TODO implement contructor
    Iterator(DataLoader<DType, LType> *loader, int current_idx) : loader{loader}, current_idx(current_idx) {}

    Iterator &operator=(const Iterator &iterator)
    {
      // TODO implement
      this->loader = iterator.loader;
      this->current_idx = iterator.current_idx;
      return *this;
    }

    Iterator &operator++()
    {
      // TODO implement
      this->current_idx++;
      return *this;
    }

    Iterator operator++(int)
    {
      // TODO implement
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }

    bool operator!=(const Iterator &other) const
    {
      // TODO implement
      return this->current_idx != other.current_idx && this->current_idx < loader->get_num_batch();
    }

    Batch<DType, LType> operator*() const
    {
      // TODO implement
      if (loader->get_batch_size() <= loader->get_num_samples())
      {
        return loader->batch.at(current_idx);
      }
      else
      {
        xt::xarray<DType> data;
        xt::xarray<LType> label;
        return Batch<DType, LType>(data, label);
      }
    }
  };
  /////////////////////////////////////////////////////////////////////////
  // The section for supporting the iteration and for-each to DataLoader //
  // END: Section                                                       //
  /////////////////////////////////////////////////////////////////////////
};

#endif /* DATALOADER_H */
