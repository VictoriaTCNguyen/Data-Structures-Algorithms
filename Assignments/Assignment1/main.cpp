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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <vector>
#include "MyList.h"

using namespace std;

int main() {

  char c = 'a';
  MyList l1;

  cout << "push_back z: " ;
  l1.push_back('z');
  l1.print();

  l1.pop_back();
  cout << "pop_back z: " ;
  l1.print();

  cout << "push_front 0 0 z 0 z: " ; //not pushign? fixed 
  l1.push_front('0');
  l1.push_front('0');
  l1.push_front('z');
  l1.push_front('0');
  l1.push_front('z');
  l1.print();

  int loc_size = l1.size();
  //failing around here because of assert
  cout << "size: " << l1.size() << endl;
  cout << "array style print: " ;
  //loc_size is 0 because l1 size is 0. size() broken ? fixed
  for(int i = 0; i < loc_size; i++)
    cout << l1[i] << " ";
  cout << endl;

  cout << "insert_at_pos a 0 on left and right of middle z: " ;
  l1.insert_at_pos(2, '0');
  l1.insert_at_pos(5, '0');
  l1.print();

  cout << "push_back letters f-j: ";
  for(int i = 0; i < 10; i++)
    l1.push_back(c+i);
  l1.print();

  cout << "pop_front z z: ";
  for(int i = 0; i < 2; i++)
    l1.pop_front();
  l1.print();

  cout << "pop_back f-j: ";
  for(int i = 0; i < 5; i++)
    l1.pop_back();
  l1.print();

  cout << "reverse odd sized list: ";
  l1.reverse();
  l1.print();

  cout << "push_front f: ";
  l1.push_front('f');
  l1.print();

  cout << "reverse even sized list: ";
  l1.reverse();
  l1.print();

  // make some copies for later use
  cout << "Construct new lists l2,l3,l4:\n";
  cout << "MyList l4(l1);\nMyList l3 = l4;\nMyList l2(l3);" << endl;
  MyList l4(l1);
  MyList l3 = l4;
  MyList l2(l3);

  //l1.print();
  // test pop_back
  cout << "pop_back entire list, l1: ";
  loc_size = l1.size(); //drains list

  for(int i = 0; i < loc_size; i++)
    l1.pop_back();
  l1.print(); //success, should be blank?

  // test reverse
  cout << "reverse empty list, l1: ";
  l1.reverse();
  l1.print(); //should be empty?

  cout << "pop_back entire list but one item, l2: ";
  loc_size = l2.size();
  
  //cout << endl << "test: " ;
  //l2.print(); passes

  for(int i = 0; i < loc_size-1; i++)
    l2.pop_back();
  l2.print();; //passes, should be 0

  cout << "reverse one item list, l2: ";
  l2.reverse();
  l2.print(); //reverses single item and prints. correct?

  cout << "pop_back entire list but two items, l3: ";
  loc_size = l3.size();

  for(int i = 0; i < loc_size-2; i++)
    l3.pop_back();
  l3.print();

  cout << "reverse two item list, l3: ";
  l3.reverse();
  l3.print();

  cout << "list l4: ";
  l4.print();

  cout << "list l4 + l3: "; //merge lists not working
  l4 + l3; 
  l4.print();

  //begins destructing here
  cout << "list l4 + l2: ";
  l4 + l2; 
  l4.print();

  cout << "list l4 + l1: ";
  l4 + l1; 
  l4.print();

  cout << "Good Bye!" << endl;
  return 0;
}