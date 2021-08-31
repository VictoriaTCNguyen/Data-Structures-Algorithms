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
 * Filename : Vertex.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/*
 * cs014_21sumB
 * Vertex.H
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>

using namespace std;

/******
    label - Individual vertex's label.
    int distance - Distance the vertex is from the start vertex. The graph is unordered so all distances between two adjacent vertices are 1.
    neighbors - An STL list of the vertices adjacent to an individual graph vertex instance. The integer value is the neighboring vertex's position in the graph object's member vector vertices.
    (Optional) use a vector of neighbors - Can be used as a substitute for an STL list to store references to an individual vertex’s neighbors.
****/

class Vertex {
public:
    Vertex()
    { 
        label = ""; //individual vertex's label - should this be string?
        distance = 999; //start with an "arbitrary infinity"
    }
    ~Vertex(){}
    string label;
    int distance;
    list<int> neighbors;
    list<int>shortest_path; // goes thru destinations and saves shortest paths
    
};

#endif /* VERTEX_H_ */