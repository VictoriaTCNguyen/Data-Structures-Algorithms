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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

// CS14
// lab 2 main.cc 

#include <iostream>
#include "list.h"

using namespace std;

int
main ( ) {

  List first_list;
  List second_list;
  
  first_list.push_front(1);
  first_list.push_front(2);
  first_list.push_front(3);
  first_list.push_front(4);
  first_list.push_front(5);

  cout << "The first list is" << endl;
  first_list.print();

  second_list.push_front(10);
  second_list.push_front(9);
  second_list.push_front(8);
  second_list.push_front(7);
  second_list.push_front(6);
  
  cout << "The second list is" << endl;
  second_list.print();

  cout << "Making second equal to the first." << endl;
  second_list = first_list;
  
  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();
  
  cout << "Adding 100 to the front of the first, and " << endl;
  cout << "200 to the front of the second" << endl;
  first_list.push_front(100);
  second_list.push_front(200);
  
  first_list.push_back(3000);
  //second_list.push_back();
  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  cout << "Adding 1000 to the end of the first, and " << endl;
  cout << "2000 to the end of the second" << endl;
  first_list.push_back(1000);
  second_list.push_back(2000);  

  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  // add file I/O and merge testing here

  return 0;
}

