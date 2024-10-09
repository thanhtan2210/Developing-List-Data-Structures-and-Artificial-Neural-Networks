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
    xt::svector<Batch<DType, LType>, sizeof(Batch<DType, LType>) + 1> batch;
    int num_samples;
    int m_seed;

public:
    DataLoader(Dataset<DType, LType> *ptr_dataset,
               int batch_size, bool shuffle = true,
               bool drop_last = false, int seed = -1) : ptr_dataset(ptr_dataset), batch_size(batch_size), shuffle(shuffle), drop_last(drop_last), m_seed(seed)
    {
        /*TODO: Add your code to do the initialization */
        num_samples = ptr_dataset->len();
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

        // xu li droplas
        num_batch = num_samples / batch_size;
        if (drop_last)
        {
            if (num_samples % batch_size > 0)
                num_batch++;
        }

        // xu li batch
        xt::xarray<DType> data_shape = ptr_dataset->get_data_shape();
        xt::xarray<LType> label_shape = ptr_dataset->get_label_shape();

        // xu li len tra ve
        data_shape[0] = num_batch;
        label_shape[0] = num_batch;

        // khoi tao con tro chua dataset
        TensorDataset<DType, LType> *tensor_data = dynamic_cast<TensorDataset<DType, LType> *>(ptr_dataset);
        xt::xarray<DType> batch_data(data_shape);
        xt::xarray<LType> batch_label(label_shape);

        if (ptr_dataset->get_data_shape().size() == 0)
        {
            batch_label = tensor_data->getitem(0).getLabel();
        }

        // xu li data
        for (int batch_index = 0; batch_index < num_batch; batch_index++)
        {
            /* code */
            int batch_index_start = batch_index * num_batch;
            int end_index = (batch_index + 1) * num_batch;
            if (batch_index == num_batch - 1)
            {
                if (end_index > num_samples)
                    end_index = num_samples;
            }
            int tmp = batch_index_start;
            for (batch_index_start; batch_index_start < end_index; batch_index_start++)
            {
                int shuffle_idx = index[batch_index_start];
                DataLabel data_label = tensor_data->getitem(shuffle_idx).getData();
                batch_data[batch_index_start - tmp] = tensor_data->getitem(shuffle_idx).getData();
                if (tensor_data->label_shape.size() == 0)
                {
                    /* code */
                    batch_label[0] = tensor_data->getitem(shuffle_idx).getLabel();
                }
            }
            batch_data[num_batch] = DataLabel(0, 0);
            batch.push_back(Batch(batch_data, batch_label));
        }
    }
    virtual ~DataLoader() {}

    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// START: Section                                                     //
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
            return this->current_idx != other.current_idx;
        }

        Batch<DType, LType> operator*() const
        {
            // TODO implement
            return this->loader->batch.at(current_idx);
        }
    };
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// END: Section                                                       //
    /////////////////////////////////////////////////////////////////////////
};

#endif /* DATALOADER_H */
