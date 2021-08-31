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
 * Filename : Node.cpp
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

Node::~Node ( ) 
{
  if ( right ) 
  {
    delete right;
  }

  if ( left ) 
  {
    delete left;
  }

}

string Node::getStr() 
{
  return str;
}

int Node::getCount()
{
  return count;
}

void Node::setStr(string aStr)
{
  str = aStr;
}
  
void Node::setCount(int aCount) 
{
    count = aCount;
}

void Node::printNode(Node* node) 
{
    cout << node->str << "(" << node->count << "), ";
}


