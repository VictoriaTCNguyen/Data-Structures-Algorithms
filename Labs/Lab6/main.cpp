/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Lab 6
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
 // testing 
 
 #include <iostream>
 #include <cstdlib>
 #include <string>
 #include "HashTable.h"

 using namespace std;
 
 // command line : /a.out [name of file]  [hash method] ..  [0,1,2,3]
 //argc = argument count , argv = argument vector
 
 int main( int argc, char* argv[] ) 
 { 
  //debug
  cout << argc << argv[0] ;
  
  // use argc to deal with incorrect inputs
  if(argc < 3)
  {
   cout << "Too few command line inputs. \n Follow format: /a.out [input_name.txt]  [hash method 1 2 or 3]" << endl;
   exit(1);
  }
  if(argc > 3)
  {
   cout << "Too many command line inputs. \n Follow format: /a.out [input_name.txt]  [hash method 1 2 or 3]" << endl;
   exit(1);
  }
  else
  {
   //atoi : Parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.
   string fileIn = argv[1] ; //getting the name of input file
   int hashMethod = atoi(argv[2]) ; //picking hash method ..invalid conversion from ‘char*’ to ‘int’ [-fpermissive]
      
   HashTable hash1(fileIn, hashMethod);
   hash1.print();
   hash1.printStats();
   
   hash1.processFile("dict7.txt");
   hash1.printStats();
     
  return hashMethod;
  }
     
}