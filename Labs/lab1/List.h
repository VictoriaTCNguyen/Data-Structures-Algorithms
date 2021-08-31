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
 * Filename : List.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/**
 * UCR CS&E 
 * CS 10C  (RR)
 * Summer 2021
 * Lab 1
 * List.h
 */

#ifndef LIST_H_
#define LIST_H_

#include "Node.h"
#include "Iterator.h"

class List
{
public:
	List();
	~List();
	void push_back(int value);
	void push_front(int value);
	void print()const;
	Node* get_head()const;
	Node* get_tail()const;		
	Iterator begin()const;
	Iterator end()const;
	Iterator reverseBegin()const;
	Iterator reverseEnd()const;
	
	/* These functions are all yours! */
	void sorted_insert(int value);
	void print_reverse()const;
	void insert_after(int i, int value, int size);
	void insert_before(int i, int value, int size);
	int count(int value) const;
	int find_size(); //additional function to find size of list
	
private:
	Node* head;
	Node* tail;
};

#endif /*LIST_H_*/
