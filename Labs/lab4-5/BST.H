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
 * Filename : BST.H
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
 * BST.H
 * RR
 */

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST {

private:
  struct BinaryNode 
  {

    int value;
    int id; //added so letter and id can be swapped - output will be in order (i hope)
    BinaryNode* left;
    BinaryNode* right;
    int depth;
    int height;
    //int inorder_num;
    //int preorder_num;
    //int postorder_num;
    /**/
    //void helper;
    /**/
    BinaryNode(int& v) : value(v), id('a'), left(NULL), right(NULL) {} //added id
    static BinaryNode* insert(int v, BinaryNode* t) 
    {
      // insert nodes one by one 
      if(t == NULL) // inserts if t is currently NULL 
        {
        t = new BinaryNode(v);
        }
      else if (v < t->value)
	      t->left = insert(v, t->left);
      else if (v > t->value)
	      t->right = insert(v, t->right);
      //if value is already in BST 
     else if(t->value == v)
      {
        cout << "Value already present in tree, try different value." << endl;
      }        	      
      else
	      t->value = v;
      return t;

    }
    
    static BinaryNode* remove(int v, BinaryNode* t) 
    {
      if(t) 
      {
        //searching for value present
        //search(BinaryNode* t, int v)
        {
          if (t == NULL)
          {
            return NULL;
          }
          else if( t->value == v)
          {
            return t;
          }
          else if( t->value > v) //
          {
            //return search(t->left, v);
            t->left = remove(v, t->left);
          }
          else if (t->value < v)
          {
            //return search(t->right,v);
            t->right = remove(v,t->right);
          }
          else if ( t->right != NULL && t->left != NULL)
          {
            t->value = find_min(t->right)->value;
            t->right = remove(t->value, t->right);
          }
	      //else if(t->value == NULL)
	      //{
	        //cout << "test" << endl;
	     // }
	     else 
	     {
	       BinaryNode* oldNode = t; // 
	       t = (t->left != NULL) ? t->left : t->right; //if t left is not NULL, assign left to t, else assign right 
	       delete oldNode;
         cout << "Error - Trying to remove value not present in tree" << endl;	       
	     }
	    //deal with value not being present in tree
        }
    }
    return t;
    }
    //looking for node with no left children
    static BinaryNode* find_min(BinaryNode* t) 
    {
      if(t == NULL)
	      return NULL;
      if(t->left == NULL)
	      return t;
      return find_min(t->left);
    }
    
};

public:
  //char begin = 'a';
  int treeHeight = 0;
  BST(): root(NULL) {}
  ~BST() {}
  //
  //void helper(BinaryNode* t, int height, int *key);
  void insert(int v) 
  { 
    root = BinaryNode::insert(v, root); 
  }
  void remove(int v)
  { 
    root = BinaryNode::remove(v, root); 
  }
  
  void display() 
  { 
    display(root); 
  }
  
  void display( BinaryNode* t ) 
  {
    //Depth of node in BST = # edges in path connecting the root to said node = # ancestors of said node (excludes the node itself)
    // in-order traversal with indented display.
    static int depth = 0;
    ++depth; //depth increases 
    if ( t == NULL ) return; //depth stays 0 while t = NULL 
    if ( t->right != NULL ) display(t->right); //displays higher number if present ( will be to the right )
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL ) //value to the left is present ( lower value ) height is same 
      display(t->left);
    --depth;
    //testing:
  //  cout << "depth: " << depth << endl;
  }
  /*
  //serts up,, prints the root
  void displayHeight( ofstream& out)
  {
    out << "// mode = height" << endl;
    out << "digraph G" << endl;
    out << "{" << endl;
  //out << begin << " [color = lightblue, style = filled, label =\"" << t->value <<", h=" << treeHeight << "\"];" << endl;    
    out << begin << " [color = lightblue, style = filled, label=\"key=" << root->value <<", h=" << treeHeight << "\"];" << endl;  
    out << begin << "->" <<"b;" << endl;
    letter++;
    displayHeight( root , out );
    
    //FIX: not being printed
    out << "\n";
    out << "}";
  }
  */
  
  
   /**/
  //testing new method
int getMaxDepth(BinaryNode* t)
{
  if (t == NULL)
  {
    return 0;
  }
  else
  {
    //subtree height
    int leftDepth = getMaxDepth(t->left);
    int rightDepth = getMaxDepth(t->right);
    
    //getting the larger between left and right
    if( leftDepth > rightDepth )
    {
      return (leftDepth + 1);
    }
    else
    {
      return (rightDepth + 1);
    }
  }
}    

int getMaxDepth()
{
  return getMaxDepth(root);
}
  
  void outputHeight(BinaryNode* t, ofstream &out) 
  {
    //all 3 of these must be static  for each type (some only have 2 vars)
    static char letter = 'a';  
    static int maxDepth = getMaxDepth(); //not declared in this scope? FIX: moved out of struct, into public.
    static int currDepth = 0;
    currDepth++;

    int height = maxDepth -currDepth;
    
    //int key = 1;
    //out << "digraph G {" << endl;
   // out << t->id << " [color = lightblue, style = filled, label=\"key=" << t->value << ", h=" << height << "\"];" << endl;

    if(t->left)
    {
      letter++;
      t->left->id = letter;
      outputHeight(t->left, out);
    }
    if(t->right)
    {
      letter++;
      t->right->id = letter;
      outputHeight(t->right, out);      
    }
    //helper(t, height, &key);
    //out << "}" << endl;
     out << t->id << " [color = lightblue, style = filled, label=\"key=" << t->value << ", h=" << height << "\"];" << endl;
  }
  
  void outputHeight()
  {
    ofstream out("output.dot");
    if(out)
    {
      out << "//dotty type: height" << endl << "digraph G {" << endl;
      outputHeight(root, out);
      
      out << endl << endl;
      out << "//edges" << endl;
      
      outputHeightEdges(root, out);
      out << endl << "}" << endl;
      out.close();
    }
    else
    {
      cout << "could not open output file, check to see if available in folder";
      exit(1);
    }
    
  }
  
  void outputHeightEdges(BinaryNode* t, ofstream &out)
  {
    if (t-> left)
    {
      out << t->id << " -> " << t->left->id << ";" << endl;
    }
    if (t->right)
    {
      out << t->id << " -> " << t->right->id << ";" << endl;
    } 
    if(t->left)
    {
      displayInOrderEdges(t->left, out);
    }
    if(t->right)
    {
      displayInOrderEdges(t->right, out);
    }    
  }  
  /*
    //getting height of each node
    void helper(BinaryNode* t, int height, int *key,ofstream& out) 
    {
      if (t == NULL) return;
      out << t->value << " [color = ..., label=\"key=" << *key++ << ", h=" << height << "\"];" << endl;
      helper(t->left, height + 1, key);
      helper(t->right, height + 1, key);
    }
    
    void edges(BinaryNode *t,ofstream& out)
    {
      if (t == NULL) return;
      if (t->left != NULL) 
      {
      out << t->value << " -> ";
      out << t->left->value << endl;
      }
      if (t->right != NULL) 
      {
      out << t->value << " -> ";
      out << t->right->value << endl;
      edges(t->left);
      edges(t->right);
      }
    }  
  */
  
  /**/
  /*
  void displayHeight(BinaryNode* t, ofstream& out) 
  {
    //empty
    if(t == nullptr) 
    {
      return;
    }

    BinaryNode* levelBefore = t;
    char charBefore = begin;
    if(levelBefore->left != NULL || levelBefore->right !=NULL) 
    {
      treeHeight++;
      
      if(levelBefore->left != NULL) 
      {
        t = levelBefore->left;
        out << begin << " [color = lightblue, style = filled, label=\"key=" << t->value <<", h=" << treeHeight << "\"];"<< endl;
        out << charBefore << "->" << begin <<";" << endl;
        letter++;
      }
      
      if(levelBefore->right != NULL) 
      {
        t = levelBefore->right;
        out << begin << " [color = lightblue, style = filled, label=\"key=" << t->value <<", h=" << treeHeight << "\"];"<<endl;
        out << charBefore << "->" << begin <<";" << endl;
        letter++;
      }

    }

    displayHeight(levelBefore->left, out);
    displayHeight(levelBefore->right, out);
    
  }*/
  
  void displayPreOrder()
  {
    ofstream out("output.dot");
    if(out)
    {
      out << "//dotty type: preorder" << endl << "digraph G {" << endl << endl;
      
      
      displayPreOrder(root, out);
      
      out << endl << endl;
    
    
      out << "//edges" << endl;
      displayPreOrderEdges(root, out);
      out << endl << "}" << endl;
      out.close();
    }
    else
    {
      cout << "could not open output file, check to see if available in folder";
      exit(1);
    }
  }
  
  void displayPreOrder(BinaryNode* t, ofstream &out)
  {
    static int preorderNum = 0;
    static char letter = 'a';
    preorderNum++;
    
    
    //sorting out letter (value / id )
    if(t->left)
    {
      (letter + 1);
      t->left->id = letter;
      displayPreOrder(t->left, out);
    }
    if(t->right)
    {
      letter++;
      t->right->id = letter;
      displayPreOrder(t->right, out);
    }    
    //saparate value and id so theyre in order in output 
    out << t->id << " [color = orange, style = filled, peripheries = 2, label=\"key=" << t->value << ", pre=" << preorderNum << "\"];" << endl;
  

  }//why are id's not being changed to letters?
  
  void displayPreOrderEdges(BinaryNode* t, ofstream &out)
  {
    if (t-> left)
    {
      out << t->id << " -> " << t->left->id << "[color=blue];" << endl;
    }
    if (t->right)
    {
      out << t->id << " -> " << t->right->id << " [color=blue];" << endl;
    } 
    if(t->left)
    {
      displayInOrderEdges(t->left, out);
    }
    if(t->right)
    {
      displayInOrderEdges(t->right, out);
    }    
  }  
  /*
  void displayPreOrder( BinaryNode* t, ofstream &out )
  {
    if ( t == NULL)
    {
      return;
    }
    BinaryNode* levelBefore = t;
    if(levelBefore-> left != NULL || levelBefore->right!= NULL )
    {
      letter++;
      treeHeight++;
    }
    if(levelBefore -> left != NULL )
  }  */
  
  
  void displayInOrder()
  {
    ofstream out("output.dot");
    if(out)
    {
      out << "//dotty type: in order" << endl << "digraph G {" << endl << endl;
      
      
      displayInOrder(root, out);
      
      out << endl << endl;
    
    
      out << "//edges" << endl;
      displayInOrderEdges(root, out);
      out << endl << "}" << endl;
      out.close();
    }
    else
    {
      cout << "could not open output file, check to see if available in folder";
      exit(1);
    }
  }  
  
  void displayInOrderEdges(BinaryNode* t, ofstream &out)
  {
    if (t-> left)
    {
      out << t->id << " -> " << t->left->id << ";" << endl;
    }
    if (t->right)
    {
      out << t->id << " -> " << t->right->id << ";" << endl;
    } 
    if(t->left)
    {
      displayInOrderEdges(t->left, out);
    }
    if(t->right)
    {
      displayInOrderEdges(t->right, out);
    }    
  }
  
  
  void displayInOrder( BinaryNode* t, ofstream &out )
  {
    static char letter = 'a';
    static int inOrder_num = 0;
    
    if (t-> left)
    {
      letter++;
      t->left->id = letter;
      displayInOrder(t->left, out);
    }
    
    inOrder_num++;
    out << t->id << "[color=red, peripheries =2, style = filled, label=\"key" << t->value << ", in =" << inOrder_num << "\"];" << endl;
    if (t-> right)
    {
      letter++;
      t->right->id = letter;
      displayInOrder(t->right, out);
    }

  }


void displayPostOrder()
  {
    ofstream out("output.dot");
    if(out)
    {
      out << "//dotty type: post order" << endl << "digraph G {" << endl << endl;
      
      
      displayPostOrder(root, out);
      
      out << endl << endl;
    
      out << "//edges" << endl;
      displayPostOrderEdges(root, out);
      out << endl << "}" << endl;
      out.close();
    }
    else
    {
      cout << "could not open output file, check to see if available in folder";
      exit(1);
    }
  }  
  
  void displayPostOrderEdges(BinaryNode* t, ofstream &out)
  {
    if (t-> left)
    {
      out << t->id << " -> " << t->left->id << ";" << endl;
    }
    if (t->right)
    {
      out << t->id << " -> " << t->right->id << ";" << endl;
    } 
    if(t->left)
    {
      displayPostOrderEdges(t->left, out);
    }
    if(t->right)
    {
      displayPostOrderEdges(t->right, out);
    }    
  }
  
  void displayPostOrder( BinaryNode* t, ofstream &out )
  {
    static char letter = 'a';
    static int postorderNum = 0;
    
    if ( t == NULL)
    {
      return;
    }
    if (t->right)
    {
      letter++;
      t->right->id = letter;
      displayPostOrder(t->right, out);
    }
    if (t->left)
    {
      letter++;
      t->left->id = letter;
      displayPostOrder(t->left, out);
    }
    postorderNum++;
    //no example output... smilar to preorder?
    out << t->id << " [color = aquamarine3, peripheries = 2, style = filled, label=\"key=" << t->value << ",post =" << postorderNum << "\"];" << endl;
  }

  private:
    BinaryNode* root; 
};

#endif /* BST_H_ */

