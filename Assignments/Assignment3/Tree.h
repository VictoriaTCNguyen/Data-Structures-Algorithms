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
 * Filename : Tree.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

//Tree.h
#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

using namespace std;

class Tree 
{
private:
  Node *root;

private:
  void preOrder( Node * );

public:
  void insert( const string & );
  bool search( const string & );
  void inOrder( );
  void postOrder( );
  void preOrder( );
  string largest( );
  string smallest( );
  int height( const string & );
  void remove( const string & );

  // Add any additional variables/functions here
   Tree();
   ~Tree();
  
    Node* insert(string, Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    Node* removeHelper(Node* , string);
    Node* smallest(Node*);
    Node* largest(Node*);
    int height(Node*);
    int height(Node*,string);
    int heightHelper(Node*, string, int &);
    void printNode(Node*);
};

#endif