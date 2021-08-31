/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: lab2
 * Filename : list.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

// CS14
// This file contains the list class declaration.

#ifndef __LIST_H_
#define __LIST_H_

#include "node.h"

class List {
private:
  Node* head;
  int* dataObject;

public:
  List ( );
  ~List ( );
  int size ( ) const;
  void push_front ( int );
  void push_back ( int );
  void print ( );
   void SetDataObject(const int setVal) 
   {
      *dataObject = setVal;
   }
   int GetDataObject() const 
   {
      return *dataObject;
   }
   List& operator=( const List& );
   List( const List & );
};
#endif

