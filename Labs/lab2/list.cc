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
 * Filename : list.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

// CS14
// This file contains all of the functions for the list class

#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List ( ) {

  head = NULL;

}

//------------------------------------------------------------------------

List::~List ( ) {

  // ADD: to avoid memory leaks, make sure you delete all allocated memory
  Node* next;
  for ( Node* temp = head; temp != NULL; temp = next ) {
    next = temp->next;
    delete temp;
  }

}

//------------------------------------------------------------------------

int List::size ( ) const {
  int size = 0;
  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    size ++;
  }
  return size;
}

//------------------------------------------------------------------------

void List::push_front ( int value ) {

  Node* insert = new Node;
  insert->value = value;
  insert->next = head;
  head = insert;

}

//------------------------------------------------------------------------

void
List::push_back ( int value ) {

  if ( size ( ) == 0 ) {
    push_front ( value );
  }
  else {
    Node* tail;
    for ( tail = head; tail->next != NULL ; tail = tail->next );
    Node* insert = new Node;
    insert->value = value;
    insert->next = NULL;
    tail->next = insert;
  }

}

//------------------------------------------------------------------------

void List::print ( ) {

  if ( size ( ) == 0 ) {
    cout << "No elements in the array" << endl;
    return;
  }

  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    cout << temp->value << " ";
  }
  cout << endl;
}



//----------added function - making copy

List::List(const List &copied)
{
  
  //create empty space
  int original_length = copied.size();
  Node* empty[ original_length];
  
  //fill, with empty nodes
  for (int i = 0 ; i < original_length ; i++)
  {
    empty[i] = new Node;
  }
  
  //copy values over
  
  Node* curr = copied.head;
  
  head = empty[0];
  head->value = curr->value;
  head->next = empty[1];
  
  for(int i = 1 ; i < ( original_length-1 ) ; i++)
  {
    curr = curr->next;
    empty[i]->value = curr->value;
    empty[i]->next = empty[i+1];
  }
  
  curr = curr->next;
  empty[original_length-1]->value = curr->value;
}

//-----------added function =

List& List::operator=(const List &copied)
{
  if( &copied != this)
  {
    
    Node* next; 
    for (Node* temp = head ; temp != NULL ; temp =next)
    {
      next = temp->next;
      delete temp;    // deletes memory associated w copied 
    }
    
    //using size og copied list, create an empty array with a matching number of slots
    int original_length = copied.size();
    Node* empty[original_length]; 
    
    // add nodes to the copy equal to the number found in the original list
    for (int i = 0 ; i < original_length ; i++)
    {
      empty[i] = new Node;
    }
    
    // Copy values from node to node
    Node* curr = copied.head; // START: create a new node using the head of the original
    
    head = empty[0]; //sets head to the start of the new nodes
    head->value = curr->value; //copy value over
    head->next = empty[1]; // move head over 1
    
    //LOOP: iterate through and assign next & values accordingly
    for ( int i = 1 ; i < ( original_length - 1) ; i++)
    {
      curr = curr->next; //moves current node over
      empty[i]->value = curr->value; //assigning new value
      empty[i]->next = empty[i+1];
    }
    
    //last one must be done outside
    
    curr = curr->next;
    empty[original_length-1]->value = curr->value;
    
  }
  return *this;
}