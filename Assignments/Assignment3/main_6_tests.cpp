#include <iostream>
#include "Tree.h"
#include "Node.h"
#include "Tree.cpp"
#include "Node.cpp"

using namespace std;

void printOrders( Tree *tree ) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}

int main( ) {

  Tree tree;

  cout << "Test 1: Testing simple insert" << endl;
  tree.insert( "neo" );
  tree.insert( "trinity" );
  printOrders( &tree );
  cout <<  endl << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search test: find \"neo\"" << endl;
  if ( tree.search( "neo" ) )
    cout << "Passed" << endl;
  else
    cout << "Failed" << endl;
  cout <<  endl << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout <<  endl << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout <<  endl << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"neo\" = " 
       << tree.height( "neo" ) << endl;
  cout <<  endl << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Remove testing" << endl;
  cout << "Removing \"neo\"" << endl;
  tree.remove( "neo" );
  printOrders( &tree );
  cout <<  endl << "----------------------------------------------------------------" 
       << endl;

  return 1;
}

/* expected output 

Test 1: Testing simple insert
Preorder = neo(1), trinity(1), 
Inorder = neo(1), trinity(1), 
Postorder = trinity(1), neo(1), 
----------------------------------------------------------------
Test 2: Search test: find "neo"
Passed
----------------------------------------------------------------
Test 3: Smallest value in the tree is...
neo
----------------------------------------------------------------
Test 4: Largest value in the tree is...
trinity
----------------------------------------------------------------
Test 5: Testing subtree heights
Height of subtree rooted at "neo" = 1
----------------------------------------------------------------
Test 6: Remove testing
Removing "neo"
Preorder = trinity(1), 
Inorder = trinity(1), 
Postorder = trinity(1), 
----------------------------------------------------------------

*/