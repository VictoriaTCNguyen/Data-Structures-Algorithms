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
 * Filename : pq_zero.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 

//allowed to add functions deemed necessary to heap portion of class
// 1. get binary heap implemented, test for functionality
//      - temporarily make it public to test each heap function independent of the overall priority queue class 
// useful expressions: parent index = (i-1)/2, left child index = 2i+1, right child index = 2i+2.

#ifndef __PQ_ZERO_H
#define __PQ_ZERO_H
//adapt this class so heap has its index based at index 1 in underlying vector 

using namespace std;
#include <vector>
#include <map>
#include <iostream>

template< class Item > 
class pq_zero
{
private:
  vector<Item> heap; // The heap expands/shrinks to fit data.. increment up/down
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
  void percolate_up( indx i ) //percolates child upward if parent is greater prio - percolating will move up/so that the heap is sorted 
  {
    // while 0...i, parent is within index values (won't look above root), & parent has higher prio than child
    while( (i > 0)  && parent(i) >= 0 && priority[heap[parent(i)]] >= priority[heap[i]] )
    {
      //parent has same priority as current item
      if ( priority[heap[parent(i)]] == priority[heap[i]] )
      { //force first one added to go first... not sure how to do so just break for now
        break;
      }
      //otherwise, swap the child and parent
      else
      {
        int parent_temp_up = parent(i); // temporary holder while swapping
        
        swap(parent_temp_up, i); //puts i in position of parent
        i = parent(i); // turn child into parent
      }
    }
  }
  
  //percolating a parent downwards
  void percolate_down( indx i ) //BROKEN
  {
    int l = childLeft(i);
    
    //returns if item has higher prio than both of its left and right 
    if (( l > 0 ) && (childRight(i) > 0) && (priority[heap[l]] > priority[heap[childRight(i)]] ))
    {
      l = childRight(i);
    }
    if ( (l > 0) && (priority[heap[l]] <= priority[heap[i]]))
    {
      if (heap[l] == heap[i])
        return;
      swap(i,l);
      percolate_down(l);
      
    }
  }
  

  //array<int> h; //array h that stores integers
  
  /* Get PARENT, LEFT CHILD, RIGHT CHILD index values */
  int parent(int child) //parent index = (i-1)/2
  {
    if(child == 0)
    {
      return -1;
    }
    else
    {
      return (child-1)/2;
    }
  }
  
  int childLeft(int parent)
  {
    int childReturn = (2*parent)+1;
    if( childReturn < (int)heap.size() )
    {
      return childReturn;
    }
    else
    {
      return -1;
    }
  }

  int childRight(int parent)
  {
    int childReturn = 2*parent+2;
    if ( childReturn < (int)heap.size())
    {
      return childReturn;
    }
    else
    {
      return -1;
    }
   
  }
  /* end of parent, left, right */
  // allows for the actual swapping in percolate_up and down ...  helper function to swap two integers
  void swap(indx parentIndex, indx childIndex )
  {
    //initialize new temp item for parent as assigned in percoalte
    Item temp = heap[parentIndex];
   
    heap[parentIndex] = heap[childIndex]; //set new temp to heap[temp_down]
    heap[childIndex] = temp; //replace
   
    //set in index
    index[temp] = childIndex;
    index[heap[parentIndex]] = parentIndex;
  }  
  
  void build_heap()
  {
    for ( int i = (size()/2) ; i >= 0 ; --i)
    {
      percolate_down(i);
    }
  }
  
public: 

  //constructor 
  pq_zero()
  {}
  
  //overload to build heap 
  pq_zero(const vector<Item> it, vector<float> pr )
  {
    for(int i = 0; i < it.size(); i++)
    {
      heap[i] = it[i];
      priority[it[i]] = pr[i];
    }
    build_heap();
  }
  
  int size( ) const // return size of the heap
  {
    return heap.size();
  }
  
  bool empty( ) const // check whether heap is empty, true if yes
  {
    if (heap.size() == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  
  const Item& top( ) const
  {
    return heap.front();
  }
  
  void pop( )
  {
    heap[0] = heap[size() -1];
    heap.pop_back();
    percolate_down(0);
  }

  // insert an item to the priority queue
  // push back the item/element and percolate up size -1
  // take care of priority and index
  
  void push( const Item& w, float prio ) 
  {
    
    //check for same item, different prio
    // change from indx/int -> uint as there was a signed to unsigned error. 
  
    priority[w] = prio;
  
    if(size() == 0)
    {
      heap.push_back(w);
      index[w] = 0 ;
      return;
    }
    
    heap.push_back(w);
    
    for(int i = (size()/2)-1 ; i >= 0 ; i--)
    {
      percolate_up(i);
    }
  }
  
  void display_heap()
  {
    for (uint i = 0 ; i < heap.size() ; i++)
    {
      cout << heap[i];
    }
  }
    
  };
#endif //end of pq_zero


/********************************************************************************************************/

//not sure how to reuse private functions unless maybe through splitting into 3 classes :  parent - pq zero - pq one 
// class pq_one
#ifndef __PQ_ONE_H
#define __PQ_ONE_H

template< class Item >
class pq_one : public pq_zero<Item>
{

private:

  vector<Item> heap; // The heap expands/shrinks to fit data.. increment up/down
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
  void percolate_up( indx i ) //percolates child upward if parent is greater prio - percolating will move up/so that the heap is sorted 
  {
    // while 0...i, parent is within index values (won't look above root), & parent has higher prio than child
    while( (i > 0)  && parent(i) >= 0 && priority[heap[parent(i)]] >= priority[heap[i]] )
    {
      //parent has same priority as current item
      if ( priority[heap[parent(i)]] == priority[heap[i]] )
      { //force first one added to go first... not sure how to do so just break for now
        break;
      }
      //otherwise, swap the child and parent
      else
      {
        int parent_temp_up = parent(i); // temporary holder while swapping
        
        swap(parent_temp_up, i); //puts i in position of parent
        i = parent(i); // turn child into parent
      }
    }
  }
  
  //percolating a parent downwards
  void percolate_down( indx i ) //BROKEN
  {
    int l = childLeft(i);
    
    //returns if item has higher prio than both of its left and right 
    if (( l > 0 ) && (childRight(i) > 0) && (priority[heap[l]] > priority[heap[childRight(i)]] ))
    {
      l = childRight(i);
    }
    if ( (l > 0) && (priority[heap[l]] <= priority[heap[i]]))
    {
      if (heap[l] == heap[i])
        return;
      swap(i,l);
      percolate_down(l);
      
    }
  }
  

  //array<int> h; //array h that stores integers
  
  /* Get PARENT, LEFT CHILD, RIGHT CHILD index values */
  int parent(int child) //parent index = (i-1)/2
  {
    if(child==0) 
      return -1;
    else 
      return (child)/2;
  }
  
  int childLeft(int parent)
  {
    int childReturn=2*parent;
    
    if (childReturn < heap.size())
      return childReturn;
    else
      return -1;
  }

  int childRight(int parent)
  {
    int childReturn=2*parent+1;
    
    if (childReturn < heap.size())
      return childReturn;
    else
      return -1;    
  }
  
  /* end of parent, left, right */
  // allows for the actual swapping in percolate_up and down ...  helper function to swap two integers
  void swap(indx parentIndex, indx childIndex )
  {
    //initialize new temp item for parent as assigned in percoalte
    Item temp = heap[parentIndex];
   
    heap[parentIndex] = heap[childIndex]; //set new temp to heap[temp_down]
    heap[childIndex] = temp; //replace
   
    //set in index
    index[temp] = childIndex;
    index[heap[parentIndex]] = parentIndex;
  }
  
  void build_heap()
  {
    for ( int i = (size()/2) ; i >= 0 ; --i)
    {
      percolate_down(i);
    }
  }
  

 public:
  pq_one(){}

  pq_one(const vector<const Item> vecItem, const vector<float>& vecPriority){}
 
  int size( ) const{return 1;}
  // public functions are reused 
};

#endif