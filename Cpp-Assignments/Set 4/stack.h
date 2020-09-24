#ifndef __GSTACK_H
#define __GSTACK_H
#include <iostream>
#include <vector>
constexpr int max_size=50;

template<typename T>
class MyStack {
  T m_arr[max_size];
  int m_top;
  int m_maxlen;
  public:
  MyStack();
  MyStack(T len);
  MyStack(T ,T);
  void push(T val);
  int pop();
  int peek() ;
  bool isEmpty() const;
  bool isFull() const;
};

#endif
