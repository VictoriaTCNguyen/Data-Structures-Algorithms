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
 * Filename : WorldLadder.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


// $ g++ -o a.out -g -W -Wall -Werror -std=c++11 *.cpp *.h
// ./a.out words5.txt snack steak
#include <stack>
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <string>

#include "WordLadder.h"

using namespace std;

//transform one letter at a time
//word must be transformed to another word present in one of the dictionary lists
//same length, lowercase
//want to find the shortest distance from beginning to end
//is it possible there are multiple ways to get same shortest distance?

// do we input the name of the wordlist needed or does it count the number of characters and select for us / do nothing if characters dont match? 
// distance = transformations needed to get from beginning word to end word


WordLadder::WordLadder()
{
  //list<string> emptyList;
}
  
//Constructor that passes in the name of the dictionary file.
WordLadder::WordLadder(const string& listFile)
{
  ifstream inputStream(listFile);
  string temp;
  
  if(!inputStream.is_open())
  {
    cout << "Cannot open file" << endl;
    exit(1);
  }
  
  while(inputStream >> temp)
  {
    dict.push_back(temp);
  }
  inputStream.close();
}

//destructor - clear dictionary
WordLadder::~WordLadder()
{
  dict.clear();
}
  
//passes in the start and end words and outputs to standard output the word ladder.
void WordLadder::outputLadder(const string& start, const string& end) //fix... not getting optimal ladder
{
  //set to false by default
  //bool startExist = false;
  bool endExist = false;
  
  //traverses from beginning of dictionary to end 
  for(list<string>::iterator dictTraverse = dict.begin(); dictTraverse != dict.end(); dictTraverse++)
  {
    /*if (*dictTraverse == start)
    {
      startExist = true;
    } */
    
    if (*dictTraverse == end)
    {
      endExist = true;
    }    
  }
  
  //  if(!startExist || !endExist) in test 6, begin word doesnt exist but changing 1 letter results in existing word
  //handle end word not being in dict
  if(!endExist)
  {
    cout << "Check spelling - end word not found in dictionary" << endl;
    return;
  } 
  
  stack<string> wordStack;
  wordStack.push(end);
  
  queue<stack<string>> wordQueue;
  wordQueue.push(wordStack);
  queue<stack<string>> solQueue;
  
  while (!wordQueue.empty()) // while queue is not empty
  {
    // for each word in the dictionary from beginning to end
    for (list<string>::iterator dictTraverse = dict.begin(); dictTraverse != dict.end(); dictTraverse++)
    {
      //if word is exactly one letter from top string of front stack
      if(offByOne(*dictTraverse, wordQueue.front().top()))
      { //then
        if( *dictTraverse == start ) //if word is end word
        //if( *dictTraverse == end ) //changing this to end works in AWS but changes zybooks output ?
        {
          // word ladder found, it is the front stack plus the end word
          wordQueue.front().push(*dictTraverse);
          solQueue.push(wordQueue.front());
        }
        else
        {
          stack<string> tempStack = wordQueue.front() ; // make copy of front stack
          tempStack.push(*dictTraverse); //Push the found word onto the copy.
          dictTraverse = dict.erase(dictTraverse);//remove word from dictionary so it won't loop backwards PROBLEM AREA????
          dictTraverse--; // set one step back as to not skip next word
          wordQueue.push(tempStack); // Enqueue the copy.
        }
      }
    }
    wordQueue.pop(); // Dequeue front stack.
  }
  
  //fail to construct ladder
  if(solQueue.empty())
  {
    cout << "Can't create ladder with these words" << endl;
    return;
  }
  
  stack<string> shortStack = solQueue.front();
  solQueue.pop();
  
  while(!solQueue.empty())
  {
    if(solQueue.front().size() < shortStack.size())
    {
      shortStack = solQueue.front();
    }
    solQueue.pop();
  }
  
  outputLadder(shortStack,start);
}

//print stack once shortest sequence is found
void WordLadder::outputLadder(stack<string>& s, const string& start)
{
  string string_temp = start;
  string str;
  str = string_temp;
  str = s.top();
  s.pop();
  
  while (!s.empty()) //constructing
  {
    str = s.top() + '\n' + str;
    s.pop();
  }
  
  cout << str << endl; //print the string
  
}
  
void WordLadder::printDictionary()
{
  list<string>::iterator dictTraverse = dict.begin();
  for (dictTraverse = dict.begin(); dictTraverse != dict.end(); dictTraverse++)
  {
    cout << *dictTraverse << endl;
  }
}
  
  
//go through the characters of both strings 
//problem area ... timing out in zybooks. make more efficient
bool WordLadder::offByOne(const string& s1, const string& s2)
{
  //immediately rules out matching words
  if (s1 == s2)
  {
    return false;
  }
  
  //start with false
  bool ob1 = false;
  for(uint i = 0 ; i < s1.size() ; i++ )
  {
    if (s1[i] != s2[i] && ob1)
    {
      return false;
    }
    else if ( s1[i] != s2[i] )
    {
      ob1 = true;
    }
  }
  return ob1;
}


  
/* list<string> dict
{

} */
  
/* ALGORITHM: Find Word Ladder */
  
//create stack of strings
//std::stack<string> my_stack;
//push the start word onto the stack
//my_stack.push_back(start)
//create a queue of stacks
//each of the stacks are all of the words that are one letter off from start
//enqueue this stack 
  
  
  