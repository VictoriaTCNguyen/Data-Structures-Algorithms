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
 * Filename : HashTable.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
 //hash funct h maps keys of a given type to integers in a fixed interval [0,m-1]
 //  ex: h(k) = kmodm
 // m is size of hash table 
 //n is nunmber of elements stored in hash table
 
 #ifndef HASHTABLE_H_
 #define HASHTABLE_H_
 
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <map>
 #include <iterator>
 #include <cstdlib>
 
 using namespace std;
 
 class HashTable //
 {
  public:
    void print();
    void processFile( string filename );
    void insert( string );
    void printStats();
    //int hash( string item ); //error here cannot be overloaded oops
    HashTable(const string &fileIn, const int hashMethod); //
    ~HashTable();
   
    //void statHelper();
  private:
   int collisionCount;
   map< int, vector<string> > table; // stores location, [vector of ] strings in a map called table 
   int hash( string ); 
   char hashMethod; // int 1 2 or 3, picks method 
 };
 
 #endif