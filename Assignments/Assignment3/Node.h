/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 3
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Node 
{

private:
  string str;
  int count;

public:
  Node* left;
  Node* right;

public:
  Node ( string s ) 
  {
    left = right = NULL; 
    count = 1; 
    str = s; 
  };
  Node ( ) 
  {
    left = right = NULL;
    count = 0;
  };
  ~Node ( );

  // Add any additional variables/functions here
  string getStr();
  int getCount();
  
  void setCount(int);
  void setStr(string);
  void printNode(Node*);
};

#endif