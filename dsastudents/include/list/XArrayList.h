/*
 * File:   XArrayList.h
 */

#ifndef XARRAYLIST_H
#define XARRAYLIST_H
#include <memory.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <type_traits>

#include "list/IList.h"
using namespace std;

template <class T>
class XArrayList : public IList<T> {
 public:
  class Iterator;  // forward declaration

 protected:
  T *data;
  int capacity;
  bool (*itemEqual)(T &lhs, T &rhs);
  void (*deleteUserData)(XArrayList<T> *);

 public:
  XArrayList(void (*deleteUserData)(XArrayList<T> *) = 0,
             bool (*itemEqual)(T &, T &) = 0, int capacity = 10);
  XArrayList(const XArrayList<T> &list);
  XArrayList<T> &operator=(const XArrayList<T> &list);
  ~XArrayList();

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
  // Inherit from IList: BEGIN

  void println(string (*item2str)(T &) = 0) {
    cout << toString(item2str) << endl;
  }
  void setDeleteUserDataPtr(void (*deleteUserData)(XArrayList<T> *) = 0) {
    this->deleteUserData = deleteUserData;
  }

  Iterator begin() { return Iterator(this, 0); }
  Iterator end() { return Iterator(this, count); }

 protected:
  void checkIndex(int index);      // check validity of index for accessing
  void ensureCapacity(int index);  // auto-allocate if needed
  void copyFrom(const XArrayList<T> &list);
  void removeInternalData();

  //! FUNTION STATIC
 protected:
  static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &)) {
    if (itemEqual == 0)
      return lhs == rhs;
    else
      return itemEqual(lhs, rhs);
  }

 public:
  static void free(XArrayList<T> *list) {
    typename XArrayList<T>::Iterator it = list->begin();
    while (it != list->end()) {
      delete *it;
      it++;
    }
  }

 public:
  class Iterator {
   private:
    int cursor;
    XArrayList<T> *pList;

   public:
    Iterator(XArrayList<T> *pList = 0, int index = 0) {
      this->pList = pList;
      this->cursor = index;
    }
    Iterator &operator=(const Iterator &iterator) {
      cursor = iterator.cursor;
      pList = iterator.pList;
      return *this;
    }
    void remove(void (*removeItemData)(T) = 0) {
      T item = pList->removeAt(cursor);
      if (removeItemData != 0) removeItemData(item);
      cursor -= 1;  // MUST keep index of previous, for ++ later
    }

    T &operator*() { return pList->data[cursor]; }
    bool operator!=(const Iterator &iterator) {
      return cursor != iterator.cursor;
    }
    // Prefix ++ overload
    Iterator &operator++() {
      this->cursor++;
      return *this;
    }
    // Postfix ++ overload
    Iterator operator++(int) {
      Iterator iterator = *this;
      ++*this;
      return iterator;
    }
  };
};

//! ////////////////////////////////////////////////////////////////////
//! //////////////////////     METHOD DEFNITION      ///////////////////
//! ////////////////////////////////////////////////////////////////////

template <class T>
XArrayList<T>::XArrayList(void (*deleteUserData)(XArrayList<T> *),
                          bool (*itemEqual)(T &, T &), int capacity) {
  // TODO implement
}

template <class T>
XArrayList<T>::XArrayList(const XArrayList<T> &list) {
  // TODO implement
}

template <class T>
XArrayList<T> &XArrayList<T>::operator=(const XArrayList<T> &list) {
  // TODO implement
}

template <class T>
XArrayList<T>::~XArrayList() {
  // TODO implement
}

template <class T>
void XArrayList<T>::add(T e) {
  // TODO implement
}

template <class T>
void XArrayList<T>::add(int index, T e) {
  // TODO implement
}

template <class T>
T XArrayList<T>::removeAt(int index) {
  // TODO implement
}

template <class T>
bool XArrayList<T>::removeItem(T item, void (*removeItemData)(T)) {
  // TODO implement
}

template <class T>
bool XArrayList<T>::empty() {
  // TODO implement
}

template <class T>
int XArrayList<T>::size() {
  // TODO implement
}

template <class T>
void XArrayList<T>::clear() {
  // TODO implement
}

template <class T>
T &XArrayList<T>::get(int index) {
  // TODO implement
}

template <class T>
int XArrayList<T>::indexOf(T item) {
  // TODO implement
}

template <class T>
bool XArrayList<T>::contains(T item) {
  // TODO implement
}

template <class T>
string XArrayList<T>::toString(string (*item2str)(T &)) {
  // TODO implement
}

//! ////////////////////////////////////////////////////////////////////
//! ////////////////////// (private) METHOD DEFNITION //////////////////
//! ////////////////////////////////////////////////////////////////////
template <class T>
void XArrayList<T>::checkIndex(int index) {
  /**
   * Validates whether the given index is within the valid range of the list.
   * Throws an std::out_of_range exception if the index is negative or exceeds
   * the number of elements. Ensures safe access to the list's elements by
   * preventing invalid index operations.
   */
  // TODO implement
}
template <class T>
void XArrayList<T>::ensureCapacity(int index) {
  /**
   * Ensures that the list has enough capacity to accommodate the given index.
   * If the index is out of range, it throws an std::out_of_range exception. If
   * the index exceeds the current capacity, reallocates the internal array with
   * increased capacity, copying the existing elements to the new array. In case
   * of memory allocation failure, catches std::bad_alloc.
   */
  // TODO implement
}

template <class T>
void XArrayList<T>::copyFrom(const XArrayList<T> &list) {
  /*
   * Copies the contents of another XArrayList into this list.
   * Initializes the list with the same capacity as the source list and copies
   * all elements. Also duplicates user-defined comparison and deletion
   * functions, if applicable.
   */
  // TODO implement
}

template <class T>
void XArrayList<T>::removeInternalData() {
  /*
   * Clears the internal data of the list by deleting the dynamic array and any
   * user-defined data. If a custom deletion function is provided, it is used to
   * free the stored elements. Finally, the dynamic array itself is deallocated
   * from memory.
   */
  // TODO implement
}

#endif /* XARRAYLIST_H */
