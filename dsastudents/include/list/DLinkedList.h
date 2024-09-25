/*
 * File:   DLinkedList.h
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
#include <sstream>
#include <type_traits>

#include "list/IList.h"
using namespace std;

template <class T>
class DLinkedList : public IList<T>
{
public:
  class Node;        // Forward declaration
  class Iterator;    // Forward declaration
  class BWDIterator; // Forward declaration

protected:
  Node *head;
  Node *tail;
  int count;
  string s;
  bool (*itemEqual)(T &lhs, T &rhs);
  void (*deleteUserData)(DLinkedList<T> *);

public:
  DLinkedList(void (*deleteUserData)(DLinkedList<T> *) = 0,
              bool (*itemEqual)(T &, T &) = 0);
  DLinkedList(const DLinkedList<T> &list);
  DLinkedList<T> &operator=(const DLinkedList<T> &list);
  ~DLinkedList();

  // Inherit from IList: BEGIN
  void add(T e);
  void add(int index, T e);
  T removeAt(int index);
  bool removeItem(T item, void (*removeItemData)(T) = 0);
  bool empty();
  int size();
  void clear();
  T &get(int index);
  int indexOf(T item);
  bool contains(T item);
  string toString(string (*item2str)(T &) = 0);
  // Inherit from IList: END

  void println(string (*item2str)(T &) = 0)
  {
    cout << toString(item2str) << endl;
  }
  void setDeleteUserDataPtr(void (*deleteUserData)(DLinkedList<T> *) = 0)
  {
    this->deleteUserData = deleteUserData;
  }

  bool contains(T array[], int size)
  {
    int idx = 0;
    for (DLinkedList<T>::Iterator it = begin(); it != end(); it++)
    {
      if (!equals(*it, array[idx++], this->itemEqual))
        return false;
    }
    return true;
  }

  Iterator begin() { return Iterator(this, true); }
  Iterator end() { return Iterator(this, false); }

  BWDIterator bbegin() { return BWDIterator(this, true); }
  BWDIterator bend() { return BWDIterator(this, false); }

protected:
  void copyFrom(const DLinkedList<T> &list);
  void removeInternalData();
  Node *getPreviousNodeOf(int index);

  //! FUNTION STATIC
public:
  static void free(DLinkedList<T> *list)
  {
    typename DLinkedList<T>::Iterator it = list->begin();
    while (it != list->end())
    {
      delete *it;
      it++;
    }
  }

protected:
  static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
  {
    if (itemEqual == 0)
      return lhs == rhs;
    else
      return itemEqual(lhs, rhs);
  }

public:
  class Node
  {
  public:
    T data;
    Node *next;
    Node *prev;
    friend class DLinkedList<T>;

  public:
    Node(Node *next = 0, Node *prev = 0)
    {
      this->next = next;
      this->prev = prev;
    }
    Node(T data, Node *next = 0, Node *prev = 0)
    {
      this->data = data;
      this->next = next;
      this->prev = prev;
    }
  };

public:
  class Iterator
  {
  private:
    DLinkedList<T> *pList;
    Node *pNode;

  public:
    Iterator(DLinkedList<T> *pList = 0, bool begin = true)
    {
      if (begin)
      {
        if (pList != 0)
          this->pNode = pList->head->next;
        else
          pNode = 0;
      }
      else
      {
        if (pList != 0)
          this->pNode = pList->tail;
        else
          pNode = 0;
      }
      this->pList = pList;
    }

    Iterator &operator=(const Iterator &iterator)
    {
      this->pNode = iterator.pNode;
      this->pList = iterator.pList;
      return *this;
    }
    void remove(void (*removeItemData)(T) = 0)
    {
      pNode->prev->next = pNode->next;
      pNode->next->prev = pNode->prev;
      Node *pNext = pNode->prev; // MUST prev, so iterator++ will go to end
      if (removeItemData != 0)
        removeItemData(pNode->data);
      delete pNode;
      pNode = pNext;
      pList->count -= 1;
    }

    T &operator*() { return pNode->data; }
    bool operator!=(const Iterator &iterator)
    {
      return pNode != iterator.pNode;
    }
    // Prefix ++ overload
    Iterator &operator++()
    {
      pNode = pNode->next;
      return *this;
    }
    // Postfix ++ overload
    Iterator operator++(int)
    {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }
  };

public:
  class BWDIterator
  {
  private:
    Node *currentNode;
    DLinkedList<T> *pList;

  public:
    BWDIterator(DLinkedList<T> *pList, bool begin)
    {
      if (begin)
      {
        if (pList != 0)
        {
          this->currentNode = pList->head;
        }
        else
          this->currentNode = 0;
      }
      else
      {
        if (pList != 0)
        {
          this->currentNode = pList->tail;
        }
        else
        {
          this->currentNode = 0;
        }
      }
    };
    ~BWDIterator() {};
    BWDIterator &operator=(const BWDIterator &iterator)
    {
      this->currentNode = iterator.currentNode;
      this->pList = iterator.pList;
      return *this;
    };
    T &operator*() { return currentNode->data; };
    bool operator!=(const BWDIterator &iterator)
    {
      return currentNode != iterator.currentNode;
    }
    BWDIterator &operator--()
    {
      currentNode = currentNode->prev;
      return *this;
    }
    BWDIterator operator--(int)
    {
      BWDIterator iterator = *this;
      --*this;
      return iterator;
    }
    void remove(void (*removeItemData)(T) = 0)
    {
      currentNode->prev->next = currentNode->next;
      currentNode->next->prev = currentNode->prev;
      Node *pnext = currentNode->next;
      if (removeItemData != 0)
      {
        removeItemData(currentNode->data);
      }
      delete currentNode;
      currentNode = pnext;
      pList->count -= 1;
    }
  };
};

template <class T>
using List = DLinkedList<T>;

//! ////////////////////////////////////////////////////////////////////
//! //////////////////////     METHOD DEFNITION      ///////////////////
//! ////////////////////////////////////////////////////////////////////

template <class T>
DLinkedList<T>::DLinkedList(void (*deleteUserData)(DLinkedList<T> *),
                            bool (*itemEqual)(T &, T &))
{
  // TODO implement
  count = 0;
  this->deleteUserData = deleteUserData;
  this->itemEqual = itemEqual;
  head = nullptr;
  tail = nullptr;
}

template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> &list)
{
  // TODO implement
  head = nullptr;
  tail = nullptr;
  count = 0;
  Node *current = list.head;
  while (current != nullptr)
  {
    this->add(current->data);
    current = current->next;
  }
}

template <class T>
DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list)
{
  // TODO implement
  if (this == &list)
  {
    return this;
  }
  this->clear();
  Node *current = list.head;
  while (current != nullptr)
  {
    this->add(current->data);
    current = current->next;
  }
  return *this;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
  // TODO implement
  Node *current = head;
  while (current != nullptr)
  {
    Node *next_node = current->next;
    delete current;
    current = next_node;
  }
  head = nullptr;
  tail = nullptr;
  count = 0;
}

template <class T>
void DLinkedList<T>::add(T e)
{
  // TODO implement
  Node *new_node = new Node(e);
  if (head == nullptr)
  {
    head = new_node;
    tail = new_node;
  }
  else
  {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
  count++;
  return;
}
template <class T>
void DLinkedList<T>::add(int index, T e)
{
  // TODO implement
  if (index < 0 || index > count)
  {
    throw std::out_of_range("Index is out of range!");
    return;
  }
  Node *new_node = new Node(e);
  if (index == 0)
  {
    if (head == nullptr)
    {
      head = new_node;
      tail = new_node;
    }
    else
    {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
    }
  }
  else if (index == count)
  {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
  else
  {
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }
    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
  }
  count++;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
  // TODO implement
  if (index < 0 || index >= count)
  {
    throw std::out_of_range("Index is out of range!");
  }
  else
  {
    Node *target;
    if (index == 0)
    {
      target = head;
      head = head->next;
      if (head != nullptr)
      {
        head->prev = nullptr;
      }
      else
        tail = nullptr;
    }
    else if (index == count - 1)
    {
      target = tail;
      tail = tail->prev;
      tail->next = nullptr;
    }
    else
    {
      target = head;
      for (int i = 0; i < index; i++)
      {
        target = target->next;
      }
      
      target->prev->next = target->next;
      target->next->prev = target->prev;
    }
    T data = target->data;
    delete target;
    count--;
    return data;
  }
}

template <class T>
bool DLinkedList<T>::empty()
{
  // TODO implement
  if (count == 0)
  {
    return true;
  }
  return false;
}

template <class T>
int DLinkedList<T>::size()
{
  // TODO implement
  return count;
}

template <class T>
void DLinkedList<T>::clear()
{
  // TODO implement
  while (head != nullptr)
  {
    Node *next = head->next;
    delete head;
    head = next;
  }
  tail = nullptr;
  count = 0;
}

template <class T>
T &DLinkedList<T>::get(int index)
{
  // TODO implement
  if (index < 0 || index >= count)
  {
    throw std::out_of_range("Index is out of range!");
  }
  else
  {
    Node *current = head;
    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }
    return current->data;
  }
}

template <class T>
int DLinkedList<T>::indexOf(T item)
{
  // TODO implement
  Node *current = head;
  int index = 0;
  while (current != nullptr)
  {
    if (current->data == item)
    {
      return index;
    }
    index++;
    current = current->next;
  }
  return -1;
}

template <class T>
bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T))
{
  // TODO implement
  Node *current = head;
  while (current != nullptr)
  {
    if (equals(current->data, item, itemEqual))
    {
      if (removeItemData != nullptr)
      {
        removeItemData(current->data);
      }
      if (current == head)
      {
        head = head->next;
        if (head != nullptr)
        {
          head->prev = nullptr;
        }
        else
          tail = nullptr;
      }
      else if (current == tail)
      {
        tail = tail->prev;
        tail->next = nullptr;
      }
      else
      {
        current->prev->next = current->next;
        current->next->prev = current->prev;
      }
      delete current;
      count--;
      return true;
    }
    current = current->next;
  }
  return false;
}

template <class T>
bool DLinkedList<T>::contains(T item)
{
  // TODO implement
  Node *current = head;
  while (current != nullptr)
  {
    if (equals(current->data, item, this->itemEqual))
    {
      return true;
    }
    current = current->next;
  }
  return false;
}

template <class T>
string DLinkedList<T>::toString(string (*item2str)(T &))
{
  // TODO implement
  stringstream ss;
  Node *current = head;
  ss << "[";
  while (current != nullptr)
  {
    if (item2str != nullptr)
    {
      ss << item2str(current->data);
    }
    else
    {
      ss << current->data;
    }
    if (current->next != nullptr)
    {
      ss << ", ";
    }
    current = current->next;
  }
  ss << "]";
  return ss.str();
}

//! ////////////////////////////////////////////////////////////////////
//! ////////////////////// (private) METHOD DEFNITION //////////////////
//! ////////////////////////////////////////////////////////////////////
template <class T>
void DLinkedList<T>::copyFrom(const DLinkedList<T> &list)
{
  /**
   * Copies the contents of another doubly linked list into this list.
   * Initializes the current list to an empty state and then duplicates all data
   * and pointers from the source list. Iterates through the source list and
   * adds each element, preserving the order of the nodes.
   */
  // TODO implement
}

template <class T>
void DLinkedList<T>::removeInternalData()
{
  /**
   * Clears the internal data of the list by deleting all nodes and user-defined
   * data. If a custom deletion function is provided, it is used to free the
   * user's data stored in the nodes. Traverses and deletes each node between
   * the head and tail to release memory.
   */
  // TODO implement
}

template <class T>
typename DLinkedList<T>::Node *DLinkedList<T>::getPreviousNodeOf(int index)
{
  /**
   * Returns the node preceding the specified index in the doubly linked list.
   * If the index is in the first half of the list, it traverses from the head;
   * otherwise, it traverses from the tail. Efficiently navigates to the node by
   * choosing the shorter path based on the index's position.
   */
  // TODO implement
  if (index < 0 || index > count)
  {
    throw std::out_of_range("Index is out of range!");
  }
  else
  {
    Node *current;
    if (index < count / 2)
    {
      current = head;
      for (int i = 0; i < index; i++)
      {
        current = current->next;
      }
    }
    else
    {
      current = tail;
      for (int i = count - 1; i > index; i++)
      {
        current = current->prev;
      }
    }
    return current;
  }
}

#endif /* DLINKEDLIST_H */
