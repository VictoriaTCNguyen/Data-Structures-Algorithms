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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


/* main.cpp
 * cs10c_sum21
 * huffman 
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Huffman.h"

using namespace std;

int main(int argc, char* argv[]) {
  
  // forces command line input of exactly 2 arguments : the a.out and name of text file to read in
  if (argc != 2) {
    cerr << "Usage error, expected: ./a.out *.txt\n";
    exit(1);
  }
  
  string input_file = argv[1]; //takes in input file name
  Huffman h(input_file); //performs huffman on the input file['s contents']
  h.BuildHuffmanTree();
  h.PrintCharFrequencies(); 
  h.SetBitCodes();
  h.SetBitsPerChar();
  h.Stats();
  h.BitMap();
  
  return 0;
}


