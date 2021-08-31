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
 * Filename : OpenAddressCollisionTests.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

/* randomly generates an input sequence of integer keys and performs collision resolution in an 
open addressing hashing scheme using the following probing sequences: 
linear probing, quadratic probing, and cubic probing. 
    Cubic probing is simply using an offset of i^3 away from the original collision location, versus 
    i for linear and 
    i^2 for quadratic. 
    
    Then run some tests varying table sizes and maximum number of elements inserted into the hash 
    table to see when the number of collisions dominates the cost of inserts. Use table sizes that are 
    prime numbers and maximum number of elements inserted at 25%, 50%, 75%, and 90% of the size of the 
    hash table. */
    
    //collisions occur when item being inserted into a hash table maps to same bucket as existing item
    //in hash table ... chaining handles these collisions by using lists for each bucket. lists store 
    // multiple items that map to same bucket .. insert uses items key to determine bucket, inserts item 
    //in bucket's list.

//Open addressing is a collision resolution technique where collisions are resolved by looking for an 
//empty bucket elsewhere in the table

//% for modulo (11%3 =2)
//%=takes modulus using two operands and assign the result to left operand.
    
 #include <iostream>
 #include <cstdlib>
 #include <vector>
 #include <cmath> //needed for exponents/power (pow) ... ex pow(i,3) = i^3
 #include <string>
 
 using namespace std;
 
 
 int oac()
 {
    //choose a prime number for table size 7001 test all 
    const int tableSize = 7001;
    const int max = 5500;     
     
     //rand() function is used in C/C++ to generate random numbers in the range [0, RAND_max)
     vector <int> cubic(tableSize, -1); 
     vector <int> linear(tableSize, -1);
     vector <int> quadratic(tableSize, -1);
     
     
     //initialize no. collisions to 0
     int cubicCollCount = 0 ;
     int linearCollCount = 0 ;
     int quadraticCollCount = 0 ;
     
     //Cubic 
     
     for( int  i = 0 ; i < max ; i++)
     {
         
         int hashCol = rand() % tableSize;
         int offset = 0;
         
         //cubic
         while(cubic[hashCol] == 1)
         {
             cubicCollCount++;
             offset++;
             hashCol = hashCol + pow(offset,3);
             hashCol %= tableSize;
             
         }
         cubic[hashCol] = 1;
     }
     
     //linear
    for( int  i = 0 ; i < max ; i++)
     {
         
         int hashCol = rand() % tableSize;
         int offset = 0;
         
         while(cubic[hashCol] == 1)
         {
             linearCollCount++;
             offset++;
             hashCol = hashCol + offset;
             hashCol %= tableSize;
             
         }
         linear[hashCol] = 1;
     }     
     
     
     //quadratic
    for( int  i = 0 ; i < max ; i++)
     {
         
         int hashCol = rand() % tableSize;
         int offset = 0;
         
    while(quadratic[hashCol] == 1)
         {
             quadraticCollCount++;
             offset++;
             hashCol = hashCol + pow(offset,2);
             hashCol %= tableSize;
             
         }
         quadratic[hashCol] = 1;
     }
     
     // Print
     cout << "Cubic Collisions " << cubicCollCount << endl;
     cout << "Linear Collisions "<< linearCollCount << endl;
     cout << "Quadratic Collisions "<< quadraticCollCount <<endl;
     
     return 0;
 }