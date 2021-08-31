/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278   
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 4
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/* 
 * Node.h
 * cs10c_sum21
 * huffman 
 */
#include <string>

using namespace std;

#ifndef __NODE_H_
#define __NODE_H_

class Node {
public:
 	Node();
	Node(char c, int count); // "pass me a character and a count "
	Node(Node* left, Node* right, char c, int count);
	~Node();
  Node* left;
  Node* right;
  char c;
  int count;
  string bits;
};

#endif /* NODE_H_ */


