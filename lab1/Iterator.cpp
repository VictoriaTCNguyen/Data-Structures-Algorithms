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
 * Filename : Iterator.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include <cstdlib>
#include <cassert>
#include "Iterator.h"
#include "Node.h"

/**
 * Constructor
 */
Iterator::Iterator()
{
	curr_pos = NULL;
	last_pos = NULL;
}

/**
 * Destructor
 */
Iterator::~Iterator()
{}

/**
 * Looks up the value at the current postion
 * @param none
 * @return the value of the node to which iterator points
 */
int Iterator::get_value()const
{
	assert(get_curr_pos() != NULL);
	return get_curr_pos()->get_value();
}

/**
 * Accessors
 */
Node* Iterator::get_curr_pos()const
{
	return curr_pos;
}

Node* Iterator::get_last_pos()const
{
	return last_pos;
}

/**
 * Mutators
 */
void Iterator::set_curr_pos(Node* temp)
{
	curr_pos = temp;
}

void Iterator::set_last_pos(Node* temp)
{
	last_pos = temp;
}

/**
 * Compares two iterators
 * @param rhs the iterator to compare to 'this' 
 * @return true if iterators are equal
 */ 
bool Iterator::is_equal(Iterator rhs)const
{
	/* Both iterators point to same memory location */
	if(get_curr_pos() == rhs.get_curr_pos())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * Advances iterator to the next node
 * @param none
 * @return none
 */
void Iterator::next_pos()
{
	assert(get_curr_pos() != NULL);
	set_curr_pos(get_curr_pos()->get_next());
}

// start of my own 

//decrements (moves back) iterator one position towards head of list), same as operator--
void Iterator::prev_pos() 
{
	assert(get_curr_pos() != NULL);
	set_curr_pos(get_curr_pos() -> get_prev());
}

//increments (advances) iterator one position towards tail of list.
void Iterator::operator++()
{
	assert(get_curr_pos() != NULL);
	set_curr_pos(get_curr_pos() -> get_next());
}

//decrements (moves back) iterator one position towards head of list) - same as prev_pos
void Iterator::operator--()
{
	assert(get_curr_pos() != NULL);
	set_curr_pos(get_curr_pos() -> get_prev());
}

//checks if two iterators reference the same location - true if yes false if no 
bool Iterator::operator==(Iterator rhs) const
{
	return get_curr_pos() == rhs.get_curr_pos();
}

//checks if two iterators reference a different location - true if yes false if no.
bool Iterator::operator!=(Iterator rhs) const
{
	return get_curr_pos() != rhs.get_curr_pos();
}