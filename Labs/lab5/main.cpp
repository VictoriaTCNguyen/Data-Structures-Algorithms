/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278   
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Lab 5
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include "pq_zero.h"
#include <vector> 
using namespace std;

int main()
{
    int v[] = {7,2,4,1,9,3,8,8,5,-2,-6,55}; // 14values 
    int p[] = {2,1,3,-1,7,1,4,5,9,23,55,55}; //priorities
    pq_zero<int> pq;

    int  length = sizeof (v) /sizeof(int);
    
    int j= 0;
   
   //build heap
   //default priority of 1
    for (j=0; j<length; j++)
    {
        pq.push(v[j],p[j]);
        //pq.push(a[j]);
    }
   
    //display_heap heap
    cout << endl << "PQ ZERO RESULT" << endl;    
     pq.display_heap();
    cout << endl << endl;     

     //test pq_one
    pq_one<int> pq1;
    
    for (j=0; j<length; j++)
    {
        pq1.push(v[j],p[j]);
        //pq.push(v[j],p[j]);
    }
   
    //display_heap heap
    cout << endl << "PQ ONE RESULT" << endl;    
     //cout << endl << "pq1:" <<endl;
     pq1.display_heap();

    return 0;
}