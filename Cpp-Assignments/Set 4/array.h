#ifndef __GARRAY_H
#define __GARRAY_H
#include<iostream>
template<typename T>
class MyArray {
  T *m_arr;
  T m_len;
  public:
  MyArray();
  MyArray(T len);
  ~MyArray();
  void append(T val);
  T at(int index);
  bool search(T key) const;
  T sum() const;
  T min() const;
  T max() const;
  void reverse();
  void sort();
};

#endif
