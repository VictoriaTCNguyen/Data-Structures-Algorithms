/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 2
 * Filename : Stack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/*  a Stack class template that uses an array to store stack contents. Use #define CAPACITY 100 define the array size. 
The top() and pop() functions should throw an underflow_error("stack underflow") exception when stack is empty. 
The push() functions should throw an overflow_error("stack overflow") exception when stack is full Use #include 
<stdexcept> to include overflow and underflow exceptions. */

/*
 * CS010C Summer 2021
 * Programming Assignment 2
 * Stack.h
 * template, exceptions
 */

#ifndef STACK_H_
#define STACK_H_

#define CAPACITY 1000 //start lower to look at overflow
#include <stdexcept>
#include <vector>
#include <stdexcept>

using namespace std;

typedef int T;

template <class T>
class Stack 
{
public:
//char c;
  int t; // type must be int, index into array
  T S[CAPACITY];
  Stack() 
  {
    // empty because t = 0 has one element in it. t = index
    t = -1; 
  }

  void push(T value) //Adds a new element x at the top of the stack
  {
   if(t >= (CAPACITY - 1)) // t is greater than (capacity-1)
   {
     cout << "Stack Overflow \n";
   }
   else
   {
     t++; //increment index by 1 
     S[t] = value;
     //cout << value << " pushed into stack \n" ;
   }
  }

//Removes item on top of the stack, reducing the stack's size by 1 if the stack is not already empty.
  void pop() 
  {
   if( t < -1)
   {
   cout << "Stack Underflow" << endl;
   }
   else
   {
     //cout << "The popped element is " << S[t] << endl;
     t--; //lower index by 1
   }
  }

  T& top() // example of how to throw an underflow error exception with correct syntax. 
  //Returns a reference to the next (top) element in the stack, if the stack is not already empty.
  {
    if(is_empty())
      throw underflow_error("stack underflow");
    else
      return S[t];
  }


/*Returns true if stack is empty, false otherwise. Tests whether the stack size is zero. 
Primarily used as a helper function to ensure that a pop() or item& top() operation is n
ot performed on an empty instance of a Stack. */
  bool is_empty() 
  {
    if (t < 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  unsigned int size() const 
  {
    //return ( t + 1 );
    return t;
  }

};


#endif /* STACK_H_ */