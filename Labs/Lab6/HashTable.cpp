/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Lab 6
 * Filename : HashTable.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 

 #include <iostream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include "HashTable.h"
 #include <map>
 #include <iterator>
 #include <cstdlib>
 #include <cmath>
 #include <stdexcept>
 #include <cstring>
 
 
 using namespace std;
 /*
    prints hash table separated by commas.
    each array location on a separate line
    line format:
        3:	qqqqq, 
        4:	hello, happy, heath, harps, rrrrr, 
        5:	iiiii, sssss, 
 */
 void HashTable::print()
 {
     for( map<int, vector<string>>::iterator iter=table.begin() ; iter != table.end() ; iter++)
     {
         //4:	hello, happy, heath, harps, rrrrr, 
         //5:	iiiii, sssss
         cout << iter->first << ":\t" ; // need for loop for rest of the line
         //go through each location from beginning to end
         //from beginning of second component in map to end
         //problem w this for loop
         for( vector<string>::iterator iter2=(iter->second.begin() ); iter2 != (iter->second.end()) ; iter2++)
         {
             cout << *iter2 << ", "; //do not endl here, multiple strings in one line
             
         }//loops until no more contents
         
         cout << endl;
     }
 }
 
 
 /*
    Adds all words in the file specified as "filename" to hashtable
    Use push back to insert each of the words into the list at the 
    hash location that the word hashes to. 
 */
 
 // error: ‘String’ was not declared in this scope ? ? ? ? ? fixed, use all lowercase. remember to change in header file as well
 void HashTable::processFile( string filename )
 {
     
     ifstream fileIn(filename.c_str());
     if (!fileIn.is_open())
     {
         cout << "Could not open file, check spelling." << endl;
     }
     else
     {  // fix ... just make a new function to insert and increment collision size 
         
         string input;
         while ( getline(fileIn, input) )
         {
            insert(input); //collisionCount increments in insert function
         }
         
     }
     fileIn.close();
 }
 
 void HashTable::insert( string item )
 {
     //int collisionCount = 0;
     int i = hash(item); // i = location after hashing
     table[i].push_back(item);
     
 }
 
 /* 
    total number of collisions (tracked in insertions), lenght of longest 
    list, avg length of all lists 
 */
 //  error: ‘HashTable’ has not been declared ?? ? ? ?  ? ? lol i forgot to put "" around header file name
 void HashTable::printStats()
 {
     /************CALCULATIONS***********/
     
     int listMaxLength  = 0;
     int longestList = 0; 
     int listLengthSum = 0;
     int currSize = 0;
     
     //iterate through map to get the info needed for stats
    
     for( map<int, vector<string>>::iterator iter=table.begin() ; iter != table.end() ; iter++) //forgot > to close map ... 
     {
         listLengthSum = listLengthSum + ( iter->second.size() );
         currSize = (iter -> second.size() );
        if (currSize > listMaxLength)
        {
            listMaxLength = currSize; //update highest length
            longestList = iter->first; //update the location of the longest list
        }
         
     } 
     /************ END ALCULATIONS***********/
     
     double listAvg = listLengthSum/( table.size() );
     
     //need to calculate longest list and average length of list
     cout << "Total Number of Collisions: " << collisionCount << endl;
     cout << "Longest List: " << longestList << endl;
     cout << "Average length of all lists: "<< listAvg << endl;
     
 }
 
 // moved to  inside of printStats()  ?
 //void HashTable::statHelper()

 //function that actually "hashes" our input strings based on user selection
 int HashTable::hash( string item )
 {
     // add 4th 
     int hashSum = 0;
     int itemLength = item.length();
     
     //1. ADDS UP ASCII vcalues ( no need to change )
     if(hashMethod == 1)
     {
         for(int i=0 ; itemLength > i ; i++)
         {
             hashSum = hashSum + (int)(item[i]); //use (int) to turn into integer
         }
     }
     // 2. uses first 3 chars of key (assuming all are 3 characters or longer)
     // calculate calue of each key 
     //k[0] + 27 * k[1] + 729 * k[2] where 27 represents the number of letters in the English alphabet, plus the blank, and 729 is 27^2.
     else if( hashMethod == 2)
     {
         //get the first 3 characters
         //turn into integer then save
         int x = (int)item[0]; //k[0]
         int y = (int)item[1]; //k[1]
         int z = (int)item[2]; //k[2]
         
         //k[0] + 27 * k[1] + 729 * k[2]
         hashSum = x + (27 * y) + (729 * z);
         
    }
    //       3. This hash function uses all characters in the key and calculates
     //       ∑ i=0,...,keysize-1 k[keysize - i - 1] * 37 i. You can compute this polynomial function (of 37) by using Horner's rule, for example:
     //       h = k0 + (37 * k1) + (37 2 * k2) can be computed recursively by h = ( (k2) * 37 + k1 ) * 37 + k0.
    else if ( hashMethod == 3)
    {
        //sum from i = 0 to keysize - 1 ... or
        for( int i=0 ; i < itemLength ; i++)
        //hashSum = hashSum + (((z*37) +y)*37+x);
        //hashSum = hashSum + item[ item.length() - i -1 ] * pow(37,i);
        hashSum = hashSum + item[ itemLength - i - 1] * pow( 37, i );
    }
    else if (hashMethod == 4)
    {
        hashSum = (int)item[0];
    }
    else
    {
        cout << "Incorrect Hash Method. " << endl;
    }
    return hashSum;
 }
 
 //constructor
 // ERROR candidate expects 1 argument, 2 provided
 HashTable::HashTable(const string &fileIn, const int hm)
 {
     hashMethod = hm;
     ifstream InFile (fileIn.c_str());
     
     if ( InFile.is_open() )
     {
         string input;
         while ( getline(InFile, input) )
         {
            insert(input); 
         }
     }
     InFile.close();
 }
 
 //destructor
 HashTable::~HashTable()
 {
     //
 }
 