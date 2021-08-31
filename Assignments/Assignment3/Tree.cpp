/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 3
 * Filename : Tree.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#include "Tree.h"

//constructor
Tree::Tree()
{
 root = nullptr;
}

//destructor

Tree::~Tree()
{
 delete root;
}

// preOrder (public interface)
void Tree::preOrder( )
{
 preOrder(root);
 cout << "\n";
}
  
//print preorder (private)
// root , left , right
void Tree::preOrder(Node* node) 
{
 if (node == NULL)
 return;
 node->printNode(node);
 preOrder(node->left);
 preOrder(node->right);
}
 
 //public:

 void Tree::insert(const string &value)
 {
  root = insert(value, root);
 }
 
 Node* Tree::insert(string value, Node* node)
 {
  Node* temp = new Node(value);
  if (node == NULL) //empty node 
  {
   return temp; //return temp node
  }
  
  if (value < node->getStr()) //value is less than string of node
  {
   Node *left = insert(value, node->left);
   node->left = left;
  }
  else if (value > node->getStr()) 
  {
   Node *right = insert(value, node->right);
   node->right = right;
  }
  else if (value == node->getStr()) 
  {
   //str value already exists, increment count
   int tempCount = node->getCount();
   (node->setCount(tempCount+1));
   return node;
  }
  return node;
}
 
  
  bool Tree::search( const string &value )
  {
   Node* current = new Node();
   
   current = root;
   if (root== NULL) return false;
   //do until root is the dead end 
   while (current != NULL)
   {
    //start with right 
    if (value > current->getStr())
    current = current->right;
    else if (value < current->getStr()) //left side
    current = current->left;
    else //found value, value = root str
    return true;
   }
   return false;
  }
  
  void Tree::inOrder( )
  {
   inOrder(root);
  }
  
  void Tree::inOrder(Node* node)
  {
   if (node == NULL)
   {
    return;
   }
   inOrder(node->left);
   node->printNode(node);
   inOrder(node->right);
  }
  
  // traverse left subtree, right subtree, root
  void Tree::postOrder( )
  {
   postOrder(root);
  }
 
 void Tree::postOrder(Node* node)
 {
  if(node == NULL) 
   return;
       
  postOrder(node->left);
  postOrder(node->right);
  //cout << node->getStr() << " ";
  node->printNode(node);
 }
 
 //find smallest value
 //go to the leftmost leaf
 string Tree::largest( )
 {
  Node* current = new Node;
  current = root;
  while (current->right != NULL)
  {
   current = current->right;
  }
  return (current->getStr());
  }
  
 Node* Tree::largest(Node* node) 
 {
  while (node->right)
  node = node->right;
  return node;
 }
  
  string Tree::smallest( ) //error
  {
   if (root == NULL)
   {
    return "";
   }
   Node* current = new Node;
   current = root;
   
   while (current->left != NULL)
   {
    current = current->left;
   }
   return (current->getStr());
  }
  
  Node* Tree::smallest(Node* node) //error
  {
   while (node->left)
   node = node->left;
   return node; 
  }
  
 int Tree::height( const string & value)
 {
  Node* current = new Node();
  int h=-1;
  current = root;
  if (root== NULL) return -1;
  
  //do until root is the dead end 
  while (current != NULL)
  {
   //start with right subtree
   if (value > current->getStr())
    current = current->right;
   else if (value < current->getStr()) //left hand side
    current = current->left;
   else  
   {//found value, value = root str 
    h= height(current, value);
    return h;
   }
  }
   return -1;
 }

 
// Helper function to find the height
// of a given node in the binary tree
int Tree::heightHelper(Node* node, string value, int& height)
{
 // basic case
 if (node == NULL) 
 {
  return -1;
 }
 
    // Store the maximum height of
    // the left and right subtrees
    int leftHeight = heightHelper(
        node->left, value, height);
 
    int rightHeight = heightHelper(node->right, value, height);
 
    // Update height of the current node
    int maxHeight = max(leftHeight, rightHeight) + 1;
 
    // If current node is the required node
    if (node->getStr() == value)
     height = maxHeight;
 
    return maxHeight;
}

  int Tree::height(Node* node, string value){
      int h = -1;
      //store height of the Tree
      int maxHeight = heightHelper(node, value, h);
      
      //return the height
      return maxHeight;
  }
  
  int Tree::height(Node* node)
  {
      if (node == NULL)
      {
          return 0;
      }
      else
      {
          //compute height of each subtree
          int leftHeight = height(node->left);
          int rightHeight = height(node->right);
          
          //compare, return larger one
          if ( leftHeight > rightHeight )
          {
              return (leftHeight +1);
          }
          else
          {
              return (rightHeight + 1);
          }
      }
  }
  
  void Tree::remove( const string &value )
  {
      root = removeHelper(root,value);
  }
  
  Node* Tree::removeHelper(Node* node, string value)
  {
      if (root == NULL)
      {
          return root;
      }
      
      if (node == NULL)
      {
          return NULL;
      }
      
 //go left if value < root's string
      if (value < node->getStr()) {
          node->left = removeHelper(node->left,value);
      }
      //go right if value > root's string
      else if (value > node->getStr()) {
          node->right = removeHelper(node->right, value);
      }
      // value = node's string
      else {
          //decement count
          if (node->getCount() > 1) {
              int cnt;
              cnt = node->getCount();
              node->setCount(cnt-1);
          }
          
          //leaf node
          if (node->left == NULL && node->right ==NULL){
              return NULL;
          }
           
          //node has one child or no child
          else if (node->left == NULL) {
              Node* temp = new Node;
              temp = node->right;
              free(node);
              return temp;
          }
          else if (node->right == NULL) {
              Node* temp = new Node;
              temp = node->left;
              free(node);
              return temp;
          }
          
          //case node with 2 children. get the inorder successor to 
          // find the smallest of the right subtree
          Node* inorderSucc = new Node;
          //inorderSucc = smallest(root->right);
          inorderSucc = largest(node->left);
          // assign temp node as root
          string temp = node->getStr();
          //root str = inorder success str
          //root->setStr(value) = inorderSucc->getStr();
          node->setStr(inorderSucc->getStr());
          inorderSucc->setStr(temp);
          
          //delete the swapped node
          //root->right = removeHelper (root->right, temp);
          node->left = removeHelper(node->left, temp);
      }
      return node;
  }