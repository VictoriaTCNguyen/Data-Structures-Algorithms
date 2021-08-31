/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 5
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/*
 * cs10c_sum21
 * main.cpp
 */


#include "Graph.H"

int main(int argc, char* argv[]) {

    if(argc != 2) {
      cerr << "Usage error: expected <executable> <input>" << endl;
      exit(1);
    }
    
    //taking in example input file - can later change to take in file names 
   // ifsteam ifs("input.txt"); //change to argv 1 later 
    
    
    ifstream ifs(argv[1]);
    if(!ifs) 
    {
      cerr << "Input file not found. Try input.txt" << endl;
      exit(1);
    }
    
    

    Graph g(ifs);
    ifs.close();
    g.bfs();
    g.output_graph();
    cout << "The End." << endl;

    return 0;
}
