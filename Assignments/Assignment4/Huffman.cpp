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
 * Filename : Huffman.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#include <vector>
#include "Huffman.h"
#include <unordered_map>
using namespace std;

/* PUBLIC */
  Huffman::Huffman()
  {
    //
  }
  
  /*
  "To print the contents of mymap use the following for loop with an iterator."
  for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
    cout << it->first << "," << mymap_compress[it->first] <<  endl;
 }
  */
  
  
  /* constructor, reads in single file (message) one char at a time */ 
  //watch for newline and EOF
  //call BuildPQ() AFTER file is closed
  Huffman::Huffman(const string& inputFile) 
  {
    //in main.cpp, we take the second command line argument and take that in as input_file.
    //then perform Huffman h on it 
    //ifstream is the stream class infile is the name
      ifstream infile;
      
      //gets infile to open inputFile
      infile.open(inputFile.c_str()); //Returns pointer to an array that contains sequence of characters representing the current value of the string object.
      
      if(!infile.is_open() )//could not open file
      {
          cout << "Could not open file, check spelling" << endl;
          exit(1);
      }
      
      //char ch; // ? 
      pq_zero<int> pq;
      
      //int index=0; //index starts at zero
      vector<char> charVector; //vector to store characters
      string str;
      string strTemp;
      
      if(infile.is_open())
      {
        while(getline(infile,strTemp))
        {
          // removes separation between paragraph, combines into one large message 
          const std::string::size_type position = strTemp.find('\r'); 
          if (position != string::npos)
          {
            strTemp.erase(position);
          }
          //appends to message
        message += strTemp;
      }
      
      cout << "Message: " << message << endl;
      //adds to mymap
      for(char ch: message)
      {
        mymap[ch]++;
      }

      infile.close();
      
      BuildPQ();

  }
  }
  
  //destructor
  Huffman::~Huffman()
  {
      if(root != nullptr)
      //delete root
      return;
  }
  
  // prints char=>char_frequency
  void Huffman::PrintCharFrequencies() 
  {
      cout << endl << "Character Frequencies" << endl;
      for(auto iterator = mymap.begin() ; iterator != mymap.end() ; iterator++) //auto creates iterator
      {
          cout << iterator->first << " ==> " << iterator->second << endl << endl;
      }
  }
  
  // adds Nodes to priority queue with frequency counts
  void Huffman::BuildPQ()
  {
      char pq_char;
      int pq_count;
      int i = 0;
      
      for ( auto iterator = mymap.begin() ; iterator != mymap.end() ; iterator++)
      {
        //push node to pq
          pq_char = iterator->first;
          pq_count = iterator->second;
          
          pq.push(new Node(NULL, NULL, pq_char, pq_count), pq_count);
          i++;
      }
  }
  
 // combines lowest count nodes into Huffman Tree 
 // Pops top two Nodes off of PQ and combines them into a new node with sum
 //of frequency counts of the two children. Push new combined node into PQ.
  void Huffman::BuildHuffmanTree()
  {
    int pq_size = pq.size();
    pq_size++;
    
    while ( pq.size() != 1)
    {
      Node* left = pq.top();
      pq.pop();
      
      Node* right =pq.top();
      pq.pop();
      
      int sum = left->count + right->count;
      
      //$ used for internal nodes idk how but this fixed memory errors  - nodes werent writted to pq correctly
      //Node* new_node = new Node(left, right, '$', sum); 
      pq.push(new Node(left, right, '$',sum),sum);
      pq_size++;
    }
    
    //root is noq at pq top
   // Node* root = new Node;
    //root = pq.top();
  }
  
  // calls private function
  void Huffman::SetBitsPerChar()
  {
    cout << "Huffman Codes: " << endl << endl;
    for (auto pair: mymap_compress)
    {
      cout << pair.first << " " << pair.second << endl;
    }
  }
  
  // optional, calls private function
  /*void Huffman::DisplayPrefixTree()
  {
      
  }*/
  
  void Huffman::displayHuffmanTree(Node* n)
  {
    if (n == NULL)
    {
      cout << "node is null in display" << endl;
      return;
    }
    
    //printing node data
    cout << "node c: " << n->c << " ";
    cout << "node count: " << n->count << " " << endl;
    
    //go left 
    displayHuffmanTree(n->left);
    
    //go right 
    displayHuffmanTree(n->right);
  }
  
  // postorder traversal, calls private function
  void Huffman::SetBitCodes()
  {
      if (root == NULL)
      {
        cout << "root is null" << endl;
        return;
      }
      
      Node* root = new Node;
      root = pq.top();
      root->bits = "";
      
      //trying to fix
      map<char,string> mymap_compress;
      SetBitCodes(root);
  }
  
  //other version .. test 
  void Huffman::SetBitsCodes(Node* curr, string str)
  {
    if (curr == NULL)
    {
      cout << "empty node" << endl;
      return;
    }
    
    if (curr->c != 'S') //not internal node
    {
      SetBitsCodes(curr->left, str + "0");
      SetBitsCodes(curr->right, str + "1");
    }
    
    if(curr->c == '$') // is internal
    {
      SetBitsCodes(curr->left, str + "0");
      SetBitsCodes(curr->right, str + "1");
    }
  }
  
  
  // prints the num bits used: non-compressed/compressed format
  void Huffman::Stats()
  { //map<char,int> mymap;
      //similar to how to how we did outputs for the dot lab?
      int bitSum = 0;
       // for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
   // cout << it->first << "," << mymap_compress[it->first] <<  endl;
      cout << "Without Compression, 8-bit characters: " << endl;
      //rough format:
      //cout << char << " occurs " << charCount << " times. Cost of: " << charTotalBits = charCount*8 << " bits. Total so far: " << sumTotalBits << " bits."<< endl;
      for( auto iterator = mymap.begin() ; iterator != mymap.end() ; iterator++) // or is it less than or equal to mymap.end ... 
      {
        int charCost = (iterator->second)*8; // does this get messed up in every iteration 
        bitSum = bitSum + charCost;
        
        cout << iterator->first << " occurs " << iterator->second << " times. Cost of " << charCost << " bits. Total so far: " << bitSum << " bits." << endl;
      }
      cout << "\tTotal bits = " << bitSum << endl << endl; // maybe tackle this similarly to how i did the infix postfix assignment? jk past victoria is a fool  
      
      // huffman lossless
      int huffmanTotal = 0;
      cout << "Huffman code used for lossless compression: " << endl;
      //rough format:
      //cout << char << " occurs " << charCount << " times. Bit sequence " << calculated sequence << 
      //". Cost of: " << cost = count*(countofbits) << " bits. Total so far: cumulative cost"<< endl
      
      for( auto iterator2 = mymap.begin() ; iterator2 != mymap.end() ; iterator2++)
      {
        char key = iterator2->first;
        
        for( auto iterator3 = mymap_compress.begin() ; iterator3 != mymap_compress.end() ; iterator3++)
        {
          if (iterator3->first == key)
          {
            int bitcost = (iterator3->second).length() *iterator2->second;
            huffmanTotal = huffmanTotal + bitcost;
            
            cout << iterator2->first << " occurs " << iterator2->second << " times. Bit sequence: " << iterator3->second << ". Cost of : " << bitcost << " bits. Total so far: " << huffmanTotal <<"." <<endl;
            cout << endl;
          }
        }
      }
      cout << "\tTotal: " << huffmanTotal << endl;
      
  }
  
  // prints char, bitstream
  void Huffman::BitMap()
  {
      cout << "Bit Map" << endl;
      //cout << c << ", " << bitstream << endl;
      //iterate through mymap_compress, <char c,count>
      for(auto iterator = mymap_compress.begin(); iterator != mymap_compress.end() ; iterator++)
      {
        cout << iterator->first << ", " << iterator->second <<endl;
        cout << endl;
      }
  }
  
  void Huffman::PrintMessage() //prints original message in huffman codes
  {
    cout << endl << "Message in HUFFMAN CODE" << endl;
    
    for (auto iter = mymap_compress.begin() ; iter != mymap_compress.end() ; iter ++ )
    {
      cout << iter->second << " ";
    }
    cout << endl;
  }
  
/* PRIVATE */
  //list<string> message_list; // stores multiple input files if needed. comprised of the string "message" below?
  //string message;      // stores a single input file
  //map<char,int> mymap; // maps frequency "count" indexed by char 'c'
  //map<char,string> mymap_compress; // maps frequency "count" to bitstream
  //pq_zero<Node*> pq;   // binary heap priority queue stores nodes with priority
  //ode* root; // root of prefix tree
  //void DisplayPrefixTree(Node* t); // optional, use for debugging, display tree
  
  // sets string bits for leaf nodes
  void Huffman::SetBitCodes(Node* curr)
  {
      if( curr == nullptr)
      {
        return;
      }
      
      if( curr->left )
      {
        curr->left->bits = curr->bits +"0";
        SetBitCodes(curr->left);
      }
      
      if ( curr-> right )
      {
        curr->right->bits = curr->bits + "1";
        SetBitCodes(curr->right);
      }
      
      if(curr->c != '$')
      {
        mymap_compress[curr->c] = curr->bits;
      }
  }
  
  void Huffman::SetBitsPerChar(Node* n) // maps bitstream to char
  {
    if (n == nullptr)
    {
      return;
    }
    
    //leaf node
    if(!n->left && !n->right)
    {
      if (n->bits != "")
      {
        cout << " bits: " << n->bits <<endl;
        mymap_compress[n->c] = n->bits;
      }
      
      else
      {
        mymap_compress[n->c] = "1";
      }
    }
    if (n->left)
    {
      SetBitsPerChar(n->left);
    }
    if (n->right)
    {
      SetBitsPerChar(n->right);
    }
  }
  
  void Huffman::setMessage(string msg)
  {
  
    message = msg;
  }
  
  string Huffman::getMessage()
  {
    return message;
  }
