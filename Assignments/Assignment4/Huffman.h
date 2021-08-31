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
 * Filename : Huffman.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/* Huffman.h
 * cs10c_sum21
 * huffman 
 */

#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include "pq_zero.h"
#include "Node.h"

using namespace std;

class Huffman {
public:
  Huffman();
  Huffman(const string& inputFile); /* constructor, reads in single file (message) one char at a time */ //watch for newline and EOF
  ~Huffman();
  void PrintCharFrequencies(); // prints char=>char_frequency
  void BuildPQ(); // adds Nodes to priority queue with frequency counts       add nodes to priority queue
  void BuildHuffmanTree(); // combines lowest count nodes into Huffman Tree 
  void SetBitsPerChar(); // calls private function
  void DisplayPrefixTree(); // optional, calls private function
  void SetBitCodes();  // postorder traversal, calls private function
  void Stats(); // prints the num bits used: non-compressed/compressed format
  void BitMap(); // prints char, bitstream
  void PrintMessage(); //prints original message in huffman codes
  
  /*** own ***/
  void setMessage(string s);
  string getMessage();
  void calcFrequency(string s, int i);
  void deleteNode(Node* n);
  //void setMyMap(map<char,int> m);
  //map<char,int> getMyMap();
  int countLeafNodes(Node* n);
  int treeSize(Node* n);
  void displayHuffmanTree(Node* n); // delte later, for testing
  
private:
  list<string> message_list; // stores multiple input files if needed
  string message;      // stores a single input file
  map<char,int> mymap; // maps frequency "count" indexed by char 'c'
  map<char,string> mymap_compress; // maps frequency "count" to bitstream
  pq_zero<Node*> pq;   // binary heap priority queue stores nodes with priority
  Node* root; // root of prefix tree
  void DisplayPrefixTree(Node* t); // optional, use for debugging, display tree
  void SetBitCodes(Node* curr); // sets string bits for leaf nodes
  void SetBitsPerChar(Node* n); // maps bitstream to char
  /** to test **/
  void SetBitsCodes(Node* n, string str);
};

#endif /* HUFFMAN_H_ */




