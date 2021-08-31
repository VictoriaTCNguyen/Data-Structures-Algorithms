/*
 * CS010C Summer 2021
 * Programming Assignment 2
 * Stack.h
 * template, exceptions
 */

#ifndef STACK_H_
#define STACK_H_

#define CAPACITY 10
#include <stdexcept>

using namespace std;

typedef int T;

//template <class T>
class Stack {
public:
  int t; // type must be int, index into array
  T S[CAPACITY];
  Stack() { t = -1; }

  void push(T value) {
   //
  }

  void pop() {
   //
  }

  T& top() {
    if(is_empty())
      throw underflow_error("stack underflow");
    else
      return S[t];
  }

  bool is_empty() {
    //;
  }

  unsigned int size() const {
   //
  }

};

#endif /* STACK_H_ */