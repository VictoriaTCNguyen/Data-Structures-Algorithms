/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 1
 * Filename : MyList.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "Node.h"
#include <iostream>

using namespace std;

#ifndef MYLIST_H_
#define MYLIST_H_

class MyList
{
 private:
  Node* head;
 public:
  MyList(); // Default constructor
  MyList(const MyList& str); 
  MyList(const string& str); 
  MyList(const char* str); //Constructs a list from a passed in string literal, e.g. MyList l1("Red pill, or Blue pill?");
  ~MyList(); //Destructor

  /* Mutators */
  void push_front(char value); //Inserts value at the front of the list.
  void push_back(char value); //Inserts value at the back of the list.
  void pop_front(); //Removes the first item from the list. No action on empty list.
  void pop_back(); //Removes the last item from the list. No action on empty list.
  void swap(int i, int j); //Swaps the value of the nodes at positions i and j. Program should take no action if i or j is out-of-bounds.
  void insert_at_pos(int i, char value); //Inserts a node with value at position i in the list. Program should abort via an assert statement if i is out-of-bounds.
  void reverse(); //Reverses the items in the list.
  
  /* Accessors */
  int  size()const; //Returns the number of nodes in the list.
  void print()const; //Prints the contents of the list.
  int  find(char value)const; //Finds the position of the first occurrence of a character value in the list and returns that position. If the character is not in the list, the function returns -1.
  int  find(MyList& query_str)const; //Finds the position of the first occurrence of MyList query_str in the list and return that position. If query_str is not in the list, the function returns -1.

  /* Operator overloaders */
  MyList& operator=(const MyList& str); //Overloaded assignment operator. Assigns the contents rhs (r-value) list to lhs (l-value) list, e.g. l1 = l2; Check for self-assignment.
  char& operator[](const int i); //Concatenates two lists together, i.e. l1 + l2;
  MyList operator+(const MyList& str); //Overloaded [ ] operator. Reads the character located at l1[i] in list l1. Program should abort via an assert statement if i is out-of-bounds.
  //const char& operator[ ](const int i) const;
  
  /* Newly assigned functions */
  bool is_palindrome()const; //works
  void merge_list(MyList A, MyList B);
  bool remove_char(char c);
  char front()const;
};
#endif /* MYLIST_H_ */