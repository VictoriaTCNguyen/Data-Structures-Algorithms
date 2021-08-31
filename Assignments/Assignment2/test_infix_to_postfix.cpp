/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 2
 * Filename : test_infix_to_postfix.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <vector>
#include "Stack.h"
#include <stdexcept>
#include <fstream>

using namespace std;
int c;

// Characterize characters as Operators
bool isOperator(char C)
{
  if(C == '+' || C == '-' || C == '*' || C == '/')
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Return precedence of operators 
int precedence(char c) 
{
  if(c == '/' || c=='*')
  {
    return 2;
  }
    else if(c == '+' || c == '-')
    {
      return 1;
    }
    else
    {
      return -1;
    }
}

void InfixtoPostfix(string P) 
{
  Stack<char> S; //create an empty stack S to hold doubles
  int size = P.length(); //number of chars in string P
  int i=0;
  string postfix="";
  string token;

  for (i=0; i<size; i++) // start for loop
  { 
    c = P[i]; 
     
     // Operands and decimals
    if( (P[i] >= '0' && P[i] <= '9') || P[i] == '.') 
    {
      postfix += P[i]; // adds operand to postfix string
    }
    else if (P[i] == ' ') {} //do nothing for spaces between 
    else if (P[i] == '(') 
    {
      S.push(P[i]); //push ( to stack S
    }
    // 
    else if (P[i] == ')') 
    {
      while (S.top() != '(') // Until it hits a (
      {// add top of stack S to postfix, pop 
        postfix += " ";         
        postfix += S.top(); 
   
        S.pop();
      }
      S.pop(); //pop
    } 
    
    // an operator is encountered
    else 
    {
      //put a space after operand
      postfix += " ";
      // is operator with precedence less than or equal to top of the stack. 
      while (!S.is_empty() && precedence(P[i])  <= precedence(S.top()) && isOperator (P[i])) 
      {
        // add top of S to postfix, pop, add space
        postfix = postfix + S.top();
        S.pop();
        postfix += " "; 
        }
        
        //Push
        S.push(P[i]);
    }
    
    Stack<char> temp;

    while (!S.is_empty())
    {
      temp.push(S.top());
      S.pop();
    }  
     
    while (!temp.is_empty()) 
    {
      S.push(temp.top());
      temp.pop();
    }

  } // end for loop
  // very important that this happens outside of the loop ... i've learned my lesson 
  //put together final postfix result
  postfix += " ";   
  postfix = postfix  + S.top(); 
  cout << postfix << endl; 
   // result
}

int main() 
{
  string postfix;
  string file_inf;
  ofstream outfile;
  cout << "Enter input file name, including file extension (.txt):";
  cin >> file_inf ;
  cout << endl;
   
  string line;

  ifstream myfile;
  myfile.open(file_inf.c_str());   
 
  if (!myfile.is_open())
  {
    cout << "File does not exist yet !\n";
    return 1;
  }
    
  else
  {
    string line;
    while (getline(myfile, line)) 
    {
      InfixtoPostfix(line.c_str());
    }
  }    

  myfile.close();
  outfile.close();
  return 0;
}
