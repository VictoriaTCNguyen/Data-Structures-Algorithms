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
  tree.insert("Foxtrot");
  tree.insert("Romeo");
  tree.insert("Zulu");
  tree.insert("Charlie");
  tree.insert("Whiskey");
  tree.insert("Tango");
  tree.insert("Alpha");
  tree.insert("Delta");
  printOrders( &tree );
  cout << endl << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search test: find \"Tango\"" << endl;
  if ( tree.search( "Tango" ) )
    cout << "Passed" << endl;
  else
    cout << "Failed" << endl;
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Search test: find \"Uniform\"" << endl;
  if ( tree.search( "Uniform" ) )
    cout << "Passed" << endl;
  else
    cout << "Failed" << endl;
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Testing subtree height:\"Kilo\",(-1 not in tree)" << endl;
  cout << "Height of subtree rooted at \"Kilo\" = " 
       << tree.height( "Kilo" ) << endl;
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;
  cout << "Test 7: Testing subtree height:\"Charlie\",(-1 not in tree)" << endl;
  cout << "Height of subtree rooted at \"Charlie\" = " 
       << tree.height( "Charlie" ) << endl;
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;
  cout << "Test 8: Remove Foxtrot" << endl;
  cout << "Removing \"Foxtrot\"" << endl;
  tree.remove( "Foxtrot" );
  printOrders( &tree );
  cout << endl <<  "----------------------------------------------------------------" 
       << endl;

  return 1;
}

/* expected output 

Test 1: Testing simple insert
Preorder = Foxtrot(1), Charlie(1), Alpha(1), Delta(1), Romeo(1), Zulu(1), Whiskey(1), Tango(1), 
Inorder = Alpha(1), Charlie(1), Delta(1), Foxtrot(1), Romeo(1), Tango(1), Whiskey(1), Zulu(1), 
Postorder = Alpha(1), Delta(1), Charlie(1), Tango(1), Whiskey(1), Zulu(1), Romeo(1), Foxtrot(1), 
----------------------------------------------------------------
Test 2: Search test: find "Tango"
Passed
----------------------------------------------------------------
Test 3: Search test: find "Uniform"
Failed
----------------------------------------------------------------
Test 4: Smallest value in the tree is...
Alpha
----------------------------------------------------------------
Test 5: Largest value in the tree is...
Zulu
----------------------------------------------------------------
Test 6: Testing subtree height:"Kilo",(-1 not in tree)
Height of subtree rooted at "Kilo" = -1
----------------------------------------------------------------
Test 7: Testing subtree height:"Charlie",(-1 not in tree)
Height of subtree rooted at "Charlie" = 1
----------------------------------------------------------------
Test 8: Remove Foxtrot
Removing "Foxtrot"
Preorder = Delta(1), Charlie(1), Alpha(1), Romeo(1), Zulu(1), Whiskey(1), Tango(1), 
Inorder = Alpha(1), Charlie(1), Delta(1), Romeo(1), Tango(1), Whiskey(1), Zulu(1), 
Postorder = Alpha(1), Charlie(1), Tango(1), Whiskey(1), Zulu(1), Romeo(1), Delta(1), 
----------------------------------------------------------------



*/