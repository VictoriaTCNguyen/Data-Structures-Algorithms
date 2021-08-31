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
 * Filename : List.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <cstdlib>
#include <list>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}


// start of my own

//inserts new node with value into list
void List::sorted_insert(int value)
{
	//create new 
	if(value < head->get_value())
	{
		push_front(value);
		return;
	}
	
	//if value between node & prev
	for (Node* i = head->get_next(); i != NULL ; i = i->get_next() )
	{
		if ( (value <= i->get_value() ) && (value >= i-> get_prev()->get_value() ) )
		{
			Node* new_node = new Node(value); // create new node of "value
			new_node->set_next(i);
			new_node->set_prev(i->get_prev());
			i->get_prev()->set_next(new_node);
			i->set_prev(new_node);
			return;
		}
	}
	// inserts at end if not
	push_back(value);
}

//prints contents of list backwards
void List::print_reverse() const
{
	cout << "\nList contents in reverse:\n";

	/* list is empty */
	//if(!head)
	if(!tail)
	{
		cout << "empty\n";
		return;
	}
	
	Iterator it = begin();
	//for(Iterator iter = end(); !iter.is_equal(begin()); iter.prev_pos())
	for (Node* x = head->get_next() ; x != NULL ; x = x->get_next() )
	{
		it.next_pos();
	}
	
	//printing last val 
	cout << it.get_value() <<", ";
	
	//printing until empty
	while (!it.is_equal(begin()))
	{
		it.prev_pos();
		cout << it.get_value() << ", ";
	}
	cout << endl;
}

int List::find_size()
{
	int size = 0;
	for(Iterator iter = begin(); iter.get_curr_pos() != NULL; ++iter )
	{
		size++;
	}
	return size;
}

//inserts new node with value at position i+1 in the list
void List::insert_after(int i, int value, int size)
{
//Check for valid position (less than 0 or larger than list size)
    if (i < 0 || i > size - 1)
    {
        cout << "Invalid position, outside of boundaries." << endl;
    }
    else 
    	{
    	Iterator iter = begin();
        for(int k = 0; k <= i; ++k)
        	{
        	iter.next_pos();
        	
	    	//creates a new node called new_node
	    	Node* new_node = new Node(value);
	    	new_node->set_next(iter.get_curr_pos()->get_next());
	    	new_node->set_prev(iter.get_curr_pos());
	    	iter.get_curr_pos()->get_next()->set_prev(new_node);
	    	iter.get_curr_pos()->set_next(new_node);
	    	new_node = NULL;
	    	delete new_node;
			}
    	}
}
//inserts node with specified value at i-1 in the list
void List::insert_before(int i, int value, int size)
{
	//Check for valid position (less than 0 or larger than list size)
    if (i < 0 || i > size + 1)
    cout << "Invalid position, outside of boundaries." << endl;
    else
    {
    	insert_after(i-1, value, size);
    }
 }

//returns number of times value appears in list
int List::count(int value) const
{
	int count = 0;
	for (Iterator iter = begin(); iter.get_curr_pos() != NULL; iter.next_pos())
	{
		if(iter.get_value() == value)
		{
			count++;
		}
	}
	return count;
}
// additional functs

Iterator List::reverseBegin()const
{
	Iterator iter;
	iter.set_curr_pos(get_tail());
	iter.set_last_pos(get_head());
	return iter;
}


Iterator List::reverseEnd()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_head());
	return iter;
}