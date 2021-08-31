/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: lab1
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
	Node();
	Node(int value);
	~Node();
	Node* get_next()const;
	Node* get_prev()const;
	int get_value()const;
	void set_next(Node*);
	void set_prev(Node*);
	void set_value(int value);
	
private:
	Node* next;
	Node* prev;
	int value;
};

#endif /*NODE_H_*/
