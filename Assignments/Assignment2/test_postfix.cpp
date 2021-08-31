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
 * Filename : test_postfix.cpp
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
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

//evaluate a postfix expression AKA RPN 
double RPN(const string &expr) // & = reference declarator, address operator. ex. setting &expr = variable, they will have the same memory address
{
    istringstream iss(expr); //input stream for strings
    Stack <double> S; //stack of doubles 
    //cout << endl<<endl << "Step\tInput\tOperation\t..to Stack\t\t\t\tStack Contents" << endl; //heading for table
    string token; // treat everything as tokens so we can work with decimals etc ... "Splits str[] according to given delimiters.""
    double operResult; //result of an operator and 2 operands 
    int i=1; 
  
  while( iss >> token ) //while the input stream brings in a token 
  {
      cout << i << "\t"; // "Step"
      i++; //increment
      cout << token << "\t"; //"Input"
      
      double numToken; // doubles : fractional as well as whole numbers with values
      if (istringstream(token) >> numToken)
      {
          //cout << "Push\t\t" ; // "Operation"
          S.push(numToken); //push to stack 
          //cout << "push " << numToken << " to stack \t"; //"..to Stack" 
      }
      //not a number token = operators
      else
      {
          //cout << "Operator\t"; // "Operation" column
          double operandSecond = S.top(); 
          S.pop();
          double operandFirst = S.top();
          S.pop(); //pop both operands
          
          /* DEALING WITH THE 4 OPERATORS */
          /*    1. Get result of the two operands following the operation
                2. Print into table
                3. Push computed values into stack */
          if ( token == "*") 
          {
              operResult = operandFirst * operandSecond;
              //cout << operandFirst << "*" << operandSecond << " = " << operResult << " to stack\t";
              S.push(operResult); 
          }
          else if ( token == "/") 
          {
              operResult = operandFirst / operandSecond;
              //cout << operandFirst << "/" << operandSecond << " = " << operResult << " to stack\t";
              S.push(operResult);
          }
          else if ( token == "+") 
          {
              operResult = operandFirst + operandSecond;
              //cout << operandFirst << "+" << operandSecond << " = " << operResult << " to stack\t";
              S.push(operResult); 
          }
          else if ( token == "-") 
          {
              operResult = operandFirst - operandSecond;
              //cout << operandFirst << "-" << operandSecond << " = " << operResult << " to stack\t";
              S.push(operResult); 
          }
          else
          {     //if an invalid symbol made it in somehow 
              cout << "Error, invalid operation" << endl;
              exit(1);
          }
          /* DEALING WITH THE 4 OPERATORS */   
    }

    
    
  /* PRINTING STACK CONTENTS */
  Stack<double> temp;
  cout << "\t\t";
  while(!S.is_empty())
  {
      //push the top of the stack S onto temp, then pop 
      temp.push(S.top());
      S.pop();
  }
  
  //"Stack Contents"
  while(!temp.is_empty())
  {
      double t = temp.top();
      cout << t << " ";
      temp.pop();
      
      //restore original stack's contents
      S.push(t);
  }
  

  cout << endl;
  }
  return S.top();
  }

int main() 
{
    string file_in;
    ofstream outfile;
    outfile.open("rpn"); //executable

    // Ask user for file name 
    cout << "Enter file name, including extension (.txt): ";
    cin >> file_in ; 
    cout << endl;
    
    //Prints the contents of the line for user to read 
    cout << "File contents (postfix to be evaluated):" << endl; 
 
    // read a file
    string line;
    ifstream myfile; 
    myfile.open(file_in.c_str());
  
  if (!myfile.is_open())
  {
        cout << "File does not exist yet, check file name. \n";
        return 1;
  }
  else
  {
      string line;
      while (getline(myfile, line)) 
      {
          
          // using printf() in all tests for consistency
          printf("%s", line.c_str());
          outfile << line.c_str() << endl;
          RPN(line.c_str());
       }
    
    }

 myfile.close();
 outfile.close();
  
  cout << endl << "Final Stack is the result." << endl;  
  
 return 0;
}

