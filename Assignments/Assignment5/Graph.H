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
 * Filename : Graph.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/*
 * cs014_21sumB
 * Graph.H
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Vertex.H"

using namespace std;

/*****
 * 
    vertices - A vector containing all of the vertices in the graph. The start vertex is the first node in the adjacency list.
    void build_graph(ifstream& ifs) - Reads the graph input file and instantiates a graph object. Invoke from within an overloaded 
        Graph constructor which has has an ifstream parameter. Call this overloaded Graph constructor from within your main function.
    void bfs() - Breadth First Search. Via a BFS traversal, this function should assign each individual vertex's distance to the number
        of hops that the vertex is from the start vertex. The start vertex (label) is the first node listed in the input file input.txt.
    void output_graph() - writes the graph object to an output file named graph.dot that can be viewed in Graphviz.

    REQUIRED - Refer to the algorithm in the slides for BFS.

    Output a graph.dot that encodes the BFS shortest path tree (graph). The edge(s) that are included in a shortest path from the source 
        node to each node that is reachable are clearly denoted and distinguishable from those edges not included in shortest path tree. 
        Graphviz has an attribute style that can be set to bold or dashed, e.g., style=bold, style=dotted. Extra credit may be awarded for 
        particularly well structured and stellar appearing graphs drawn with Graphviz.

    NOTE: Your program will be run with the following command $./a.out input.txt
 * 
 ******/

class Graph {
public:
    Graph()
    {
        //nodeCount = 0;
        //edgeCount = 0;
    }
    Graph(ifstream& ifs) //
    { 
        build_graph(ifs);
    }
    ~Graph()
    {
        while(!vertices.empty())
        {
            //delete vertices.back()
            vertices.clear();
        }
    }
    void build_graph(ifstream& ifs)//
    {
        if(!ifs.is_open())
        {
            cout << "Could not open input file. Check to see if input.txt is in the folder" << endl;
            exit(1);
        }
        else
        {
            //declare what's being pulled from the file
            int nodeCount;
            int edgeCount;
            string nodeName;
            string sourceName;
            string destinationName;
            string neighbor;
            string holder; // for converting to integer
            
            //grab number of nodes and number of edges from first 2 lines 
            //convert from string to integer
            ifs >> holder;
            nodeCount = stoi(holder);
            ifs >> holder;
            edgeCount = stoi(holder);
            
            //for loop that gathers nodeCount number of strings from same number of lines 
            for(int i = 0 ; i < nodeCount ; i++ )
            {
                ifs >> nodeName; // grab the name
                Vertex s;
                s.label = nodeName; //sets the label to the nodeName just fed in
                vertices.push_back(s); //push back s, the label, into vertex "vertices"
            } // end loop - stops after nodeCount number of iterations
            
            //for loop gathering edgeCount pairs of [(Source) (Destination)] edges
            for( int i=0 ; i < edgeCount ; i++)
            {
                //arg 0 arg 1 .... ? no
                //grabs names of both parts of pairs (separate strings so no need to dissect)
                ifs >> sourceName;
                ifs >> destinationName;
                
                //these become indices for sources and dest or count 
                int sourceCount = 0;
                int destCount = 0;
                
                //while the item in vertices has a label that doesnt = current source, increase count
                //same for destination
                
                while(vertices[sourceCount].label != sourceName)
                {
                    sourceCount++;
                }
                while(vertices[destCount].label != destinationName)
                {
                    destCount++;
                }
                
                //destination added as source's neighbor
                vertices[sourceCount].neighbors.push_back(destCount);
            }
            
        }
        
        
    }
    void output_graph() //
    {
        ofstream outFile;
        outFile.open("graph.dot");
        outFile << "Copy and paste the following into https://dreampuf.github.io/GraphvizOnline/" << endl;
        outFile << "digraph G" << endl << "{" << endl << endl ;
        outFile << "\trankdir=\"LR\";" << endl << endl ;
        outFile << "\t// nodes " << endl;
        outFile << "\t// City_name(Shortest Path from Origin)" << endl;
        
        // prints labels (node names) and use bfs distance from root in order
        for ( uint i = 0  ; i < vertices.size() ; i++ )
        {
            outFile << "\t" << vertices[i].label << "[label=\"" <<  vertices[i].label <<"("<< vertices.at(i).distance << ")\"]" << endl; 
        }
        
        outFile << endl;
        outFile << "\t //edges, shortest distances shown in red." << endl;
        
        // use neighbors to print source -> destination
        for (uint i = 0 ; i < vertices.size() ; i++)
        {
            for(auto iterator = vertices[i].neighbors.begin() ; iterator != vertices[i].neighbors.end() ; iterator++)
            { // begin for
                //prints label -> label of destination
                outFile << "\t " << vertices[i].label << " -> " << vertices[*iterator].label; //works
                
                bool found = false; // for search , default at not found
                
                for(auto iterator2 = vertices[i].shortest_path.begin() ; iterator2 != vertices[i].shortest_path.end(); iterator2++)
                {
                    //after showing up in the search, mark
                    //append style to show it's the shortest path
                    if(vertices[*iterator].label == vertices[*iterator2].label) //not working
                    {
                        outFile << " [style=bold,color=orangered4];";
                        found = true; //mark as found
                    }
                }
                // labels for not found in shortest path search. 
                if(!found)
                {
                    outFile << " [style=dashed,arrowhead=curve,color=dimgray];"; //
                }
                outFile << endl;
            } //end for 
        }
        
        outFile << "}" << endl;
        
        outFile.close();
    }
    void bfs()//
    { 
    queue<Vertex> vertexQueue; //make a queue from vector<vertex> called vertexQueue
    vertices.front().distance = 0; //initialize distance 
    vertexQueue.push(vertices.front()); // push from front of queue "vertices"
    
    //loop until queue is drained 
    while(!vertexQueue.empty()) // error: in argument to unary 
    {
        //iterates through neighbors of what's in front of vertexQueue (-> vertices)
        for ( auto iterator = vertexQueue.front().neighbors.begin() ; iterator != vertexQueue.front().neighbors.end() ; iterator++ ) //  ?? not sure
        {
            //how do i calculate distnace between neighbors :()
            // change from arbitrary infinity -> 0 -> increment up per hop?
            if(vertices[*iterator].distance == 999) //not sure about distance used here
            {
                //if iterator points at a distance of 999 ("infinity"), set a new value marker to 0
                int val = 0;
                //perform a for loop on nodes w this marker && have labels that don't match those from the initial queue
                for (val = 0 ; vertexQueue.front().label != vertices[val].label ; val++)
                {
                    //do nothing other than increment up 
                }
                vertices[val].shortest_path.push_back(*iterator); //fixed? fixed !!!
                
                //calculate distance
                vertices[*iterator].distance = vertexQueue.front().distance + 1; 
                vertexQueue.push(vertices[*iterator]);
            }
        } // end of for loop : iterates through neighbors of what's in front of vertexQueue (-> vertices)
    
        vertexQueue.pop();
    }
    
        //done? done !!
    }
private:
    vector<Vertex> vertices;
};

#endif /* GRAPH_H_ */