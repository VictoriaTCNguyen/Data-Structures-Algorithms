/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: lab4
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 

/**
 * cs014_sum20A
 * lab4-5
 * main.cc
 * RR
 */

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[]) 
{
  
  if(argc != 2) 
  {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  // ofstream you will use to write to file output.dot
  // currently an empty output.dot gets written into pwd
  ofstream ofs("output.dot");
  if(!ofs) 
  {
    cout << "output.dot could not be opened." << endl;
    exit(1);
  }
  
  for(;;) 
  {
    cin >> cmd; //user inputs command
    if(cmd == "insert")
    {
      cin >> key; // get value user wants to insert
      
      // add code to the insert function that outputs an error message if x is already in the tree
      // currently does nothing whern we try to add duplicate 
      
      //if key is not found in tree
      t.insert(key);
      

    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
      //add code to the remove function that outputs an error message if x is NOT in the tree
      //currently, code does nothing when we try to remove something that isn't in the tree
    }
    else if(cmd == "dotty") 
    {
      string mode;
      cout << "choose height, preorder, inorder, or postorder: "<< endl;
      cin >> mode;
      if(mode == "height")
      {
        t.outputHeight();
        //t.displayHeight(ofs);
        cout << "Output generated, see output.dot" << endl;
      }
      else if(mode == "preorder")
      {
        t.displayPreOrder();
        cout << "Output generated, see output.dot" << endl;
      }
      else if( mode == "inorder")
      {
        t.displayInOrder();
        cout << "Output generated, see output.dot" << endl;
      }
      else if( mode == "postorder")
      {
        t.displayPostOrder();
        cout << "Output generated, see output.dot" << endl;
      }
      }
    else if(cmd == "display") t.display();
    else if(cmd == "end") return 0;
    else
      cout << cmd << " command not found, try again." << endl;
  }
  // close ofstream
  cout << "Good bye!" << endl;
  return 0;
}
