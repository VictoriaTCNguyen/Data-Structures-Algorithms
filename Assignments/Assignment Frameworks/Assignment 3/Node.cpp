#include <iostream>
#include "Tree.h"

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
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search test: find \"neo\"" << endl;
  if ( tree.search( "neo" ) )
    cout << "Passed" << endl;
  else
    cout << "Failed" << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"neo\" = " 
       << tree.height( "neo" ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Remove testing" << endl;
  cout << "Removing \"neo\"" << endl;
  tree.remove( "neo" );
  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;

  return 1;
}