/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: lab3
 * Filename : WordLadder.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/*
 * WordLadder.h
 * Ryan Rusich
 */

#ifndef WORDLADDER_H_
#define WORDLADDER_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class WordLadder 
{
public:
  WordLadder();
  WordLadder(const string& listFile);
  ~WordLadder();
  void outputLadder(const string& start, const string& end);
  void outputLadder(stack<string>& s, const string& start);
  void printDictionary();
  bool offByOne(const string& s1, const string& s2);
  list<string> dict;
  
private:
  queue<stack<string>> string_stack; // queue of stack of strings 
};

#endif /* WORDLADDER_H_ */
