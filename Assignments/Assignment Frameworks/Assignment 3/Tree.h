#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Node {

private:
  string str;
  int count;

public:
  Node* left;
  Node* right;

public:
  Node ( string s ) { left = right = NULL; count = 1; str = s; };
  Node ( ) { left = right = NULL; count = 0; };
  ~Node ( );

  // Add any additional variables/functions here

};

#endif