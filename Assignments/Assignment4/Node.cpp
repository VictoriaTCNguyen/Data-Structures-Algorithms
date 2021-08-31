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
 * Filename : Node.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "Node.h"

// constructor

Node::Node() {}
Node::Node(char c, int count)
{
    count = count;
    c = c;
}

// constructor
Node::Node(Node* lnode, Node* rnode, char ch, int cnt) 
{
    left = lnode;
    right = rnode;
    c = ch;
    count = cnt;
    
    bits=""; //empty string for bits
}

Node::~Node() 
{
    if (right)
    {
        delete right;
    }
    if (left) 
    {
        delete left;
    }
}

//end of Node.cpp