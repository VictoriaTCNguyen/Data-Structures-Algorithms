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
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

//do not change

#ifndef __NODE_H_
#define __NODE_H_

class Node {
  friend class MyList;
private:
  Node* next;
  char value;
};
#endif /* NODE_H_ */