/**
 * Course: CS010C Summer 2021
 *
 * First Name: Victoria
 * Last Name: Nguyen
 * Username: vnguy278
 * email address: vnguy278@ucr.edu
 *
 *
 * Assignment: Assignment 1
 * Filename : MyList.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "MyList.h"
#include <cstdlib>
#include <cassert>

using namespace std;

// default constructor
MyList::MyList() //
{ 
 head = NULL; 
 //tail = NULL;
}

//reverted to 74 from sun morn

//Copy constructor. Constructs a list from a passed in MyList object, e.g. MyList l1(l2);. Performs a deep-copy, 
//where memory separate from the argument object is allocated from the heap, using the keyword new
MyList::MyList(const MyList& str)
{
    head = NULL;
    //for loop -- a temporary node moves to the next until no longer a null pointer. 
    for (Node* temp = str.head; temp != NULL; temp = temp-> next)
    {
        // value of temp is pushed to the back of the array each time 
        push_back (temp -> value);
    }
}

//Constructs a list from a passed in string object, e.g. string username = "FLYNN"; MyList l1(username);.
MyList::MyList(const string& str)
{
    head = NULL;
    //for loop: starts at beginning and increases 1 unit i until i exceeds size of string. 
    for( uint i = 0; i < str.length(); i++)
    {
        push_back(str[i]);
    }
}

//same as previous ?
//Constructs a list from a passed in string literal, e.g. MyList l1("Red pill, or Blue pill?");
MyList::MyList(const char* str)
{
    //for ( uint i = 0; i < str.size() ; i++ ) size giving issues
    //for ( uint i = 0; i < str.length ; i++ )  nope
    head = nullptr;
    string temp = str;
    for ( uint i = 0; i < temp.size() ; i++ ) //sizeof returns amount of memory allocated for (str)
    {
        push_back( temp[i] );
    }
}

// destructor
MyList::~MyList()
{
    
    while(head)
    {
        Node* temp = head;
        //Node* temp = head; must initiate outside while < FIX incorrect, initiate while inside
                            //initiating outside caused premature destruction
        //temp = head ; //THEN set equal to head 
        head = head->next; //head continues 
        //cout << "Destructing" << temp -> value << endl;
        delete temp;
    } // ends when there's no more head
}

/* MUTATORS */

//inserts value at the front of the list
void MyList::push_front(char value) //problem :(
{
    //create the node
    Node *new_node = new Node;
    
    new_node -> value = value;
    //if empty
    if(!head)
    {   new_node->next = nullptr;
        head = new_node;
    }
    else
    {
        new_node->next=head;
        head = new_node;
    }
}

//inserts value at the back of the list
void MyList::push_back(char value)
{
    //create the node
    Node* new_node = new Node();
     
     //set its value = value 
    new_node -> value = value;
    new_node -> next = nullptr;
    
    //when list is empty
    //if(head = NULL) wrong bc head can be null without list being empty 
    if(!head) //empty list becomes node
    {
        //make new node the head 
        head = new_node;
        return;
    }
    else // link new node to last 
    {
        Node* back_node = head;
        
        while(back_node-> next != nullptr)
        {
            back_node = back_node->next;
        }
        //end for loop
        back_node->next = new_node;
    }
}
  
//removes first item from the list, does nothing if empty
void MyList::pop_front()
{
    // if there is no head
    if (!head)
    {
        head = head->next;
    }
}
  
//removes last item from list, does nothing if empty 
void MyList::pop_back()
{
    if(head->next == nullptr)
    {
        cout << "nothing to pop" << endl;
        head = head->next;
        return;
    }
    
    Node* temp = head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
}
  
 // swaps the values of nodes from postions i and j. does nothing if i and j are out of bounds. 
 void MyList::swap(int i, int j)
 {
   //if i or j are less than 0 ( index starts at 0), or goes beyond upper bound 
   if ( 0 > i || 0 > j || i + 1 > size() || j + 1 > size() )
   {
       return;
   }     
   else 
   {
       //create two new nodes for i and j, set both to head
        Node* i_curr = head;
        Node* j_curr = head;
        
        int x = 0; // remember to put "int" in front ... otherwise : error: ‘x’ was not declared in this scope
        int y = 0;

        //nodes are the same, do nothing
        if (i == j)
        {
            return;
        }
        
        //traverse until arbitrary x is less than i
        for ( x = 0 ; x < i ; x++ )
        {
            //set equal to next node
            i_curr = i_curr-> next;
        }
   
        //same for y and j
        for ( y = 0 ; y < j ; y++)
        {
            //set equal to next node
            j_curr = j_curr->next;
        }

        // SWAP VALUES
        //new char "val_swap" set to equal i_curr's value
        //error: ‘value’ was not declared in this scope ... no need to swap values? // nope just forgot > in -> 
        char val_swap = i_curr->value;
        i_curr->value = j_curr->value; //set i_curr's value to j_curr's
        j_curr->value = val_swap; //set the previous value of i_curr (stored as val_swap) to j_curr
   }
 }
  
//inserts node with VALUE at position i in the list. should abort via assert if i if out of bounds. 
void MyList::insert_at_pos(int i, char value)
{
    //assert i is between 0 and size of list 
    //assert( 0 < i < size() );    void MyList::insert_at_pos(int, char): Assertion `0 <= i <= size()' failed. 3 part assertion not allowed?
    //assert( 0 < i && i < size() ); //used cout to find size remains 0... fix size() ?
    assert( 0 <= i && i <= size() );
    
    //insert at 0 
    if( i == 0 )
    {
        // push_back(value); wrong direction 
        push_front(value);
        return;
    }
    //isnert at end
    if ( i == size() )
    {
        //push_front(value); wrong direction 
        push_back(value);
        return; 
    }
    //anywhere in between
    //create a new node to insert 
    Node* temp = head;
    for ( int j = 0 ; j < i - 1 ; j++ )
    {
        //traverses from 0 to the spot before the desired position. 
        //in each traversal, sets the new node temp to next node. 
        if(temp->next ==0)
        {
            cout << endl << "Out of range "<< endl;
            exit(1);
        }
        temp = temp->next;
    }

    //create another node, new_node
    Node* new_node = new Node();
    //set its value to value
    new_node-> value = value;
     //set its next node to the next node that comes after the traversed temp 
    new_node->next = temp->next;
    //set next to the new node. 
    temp->next = new_node;
    
    //delete temp;
    return;
}
  
  //reverses items in the list. 
void MyList::reverse()
{
    // start with 3 nodes
    Node* reverse = 0;
    Node* after_reverse = 0;
    Node* temp = head; //one needed to start at head 
    
    while(temp) //starting from head
    {
        after_reverse = temp->next; //node takes on value of node after temp
        temp->next = reverse; // reverse will begin taking on the values of char after temp 
        reverse = temp; // set reverse equal to temp 
        temp = after_reverse; //set temp to after_reverse
    }
    
    head = reverse; 
}

/* ACCESSORS */ 

//returns number of nodes in the list
int MyList::size()const
{
    
    int size_count = 0; // initialize at 0
    //Node* thisNode = head; //initialize current node
    //traverses from head to temp
    for(Node* temp = head; temp; temp = temp->next)
    {
        ++size_count; //increase size by 1 for each node
    }
    return size_count; //forcing size to return to 0? try using new var to count nodes
    
    
    /*
    int node_count = 0;
    for(Node* temp = head; temp; temp = temp->next)
    {
        node_count++;
    }
    return node_count;  */  
}

//prints contents of the list
void MyList::print()const
{
    //progresses the same way size did
    for( Node* temp = head; temp ; temp = temp-> next)
    {
        //print temp's value 
        cout << temp->value /*<< " "*/ ; // no spaces between 
    }
    cout << endl;
}

// finds position of first occurence of char value in list, returns position. 
//if character isnt in list, function returns -1. 
int MyList::find(char value)const
{
    //Used to keep track of the Node Index
	int i = 0;  
	for( Node* temp = head ; temp ; temp = temp->next)
	{
	    //stops if temp "finds" the value
	    if( temp->value == value ) //" it is true that the value of temp is equal to value "
	    {
	        //returns the position
	        return i;
	    }
	    // "stop condition" not found. vehicle to continue traversing
	    else
	    {
	        i++;
	    }
	} //END FOR LOOP 
	 
	// "stop condition" not found and there are no more elements to traverse ... 
	//If element not found
	return -1;    
}

// finds position of first occurrence of MyList query_str in the list and returns position. If not in list,
// function returns -1. 
int MyList::find(MyList& query_str)const
{
    //scrap. can't use == value
    /*int i=0;
    
    //for loop to traverse -- similar to those used before 
    for (Node* temp = head; temp; temp = temp->next)
    {
        //stops if values are matched up ( temp's value and given val)
        if ( temp->value == value )
        {
            return i;
        }
        //match not found, continue
        else
        {
            i++;
        }
    } //end for loop 
    return -1;   //not in list 
    */
    //index i 
    int i = 0;
    for(Node* l1_temp = head; l1_temp != nullptr; l1_temp = l1_temp->next) //reuse of l1 in main causing seg fault maybe?
    {
        //if the two values are the same, go through query_str until query_str is nullptr
        Node* temp_1 = l1_temp;
        Node* temp_2 = query_str.head;
        while(temp_1->value == temp_2->value){
            temp_1 = temp_1->next;
            temp_2 = temp_2->next;
            if(temp_2 == nullptr){
                return i;
            }
        }
        ++i;
    }
    return -1;
}

/* OPERATOR OVERLOADERS */

//for deep copy ?

//overloaded assignment operator
//assigns the contents rhs (r-value) list to lhs (l-value) list
//l1 = l2, check for self-assignment

//error: ‘MyList& operator=(const MyList&)’ must be a nonstatic member function MyList& operator=(const MyList& str)
// fix : adding MyList:: in front 
MyList& MyList::operator=(const MyList& str)
{
    if( this != &str)
    {
        while(this->head != 0)
        {
            this->pop_front();
        }
        for(Node* curr = str.head ; curr != 0 ; curr = curr->next)
        {
            this-> push_back(curr->value);
        }
    }
    return *this;
}

//concatenates two lists together
//i.e. l1 + l2
MyList MyList::operator+(const MyList& str)
{
    //create a temp node = 0 
    Node* temp = 0; 
    // rhs = r-value list . 
    MyList rhs = str;
    
    //for loop iterating from head of string to tmemp , setting temp to next each time 
    for ( temp = str.head ; temp ; temp = temp->next )
    {
        //push back the value of temp 
        this -> push_back(temp->value);
    } // end for loop 
    return *this;
}

//overloaded [ ] operator, reads the character located at l1[i] in list l1
// program should abort via an assert statement if i is out of bounds. 
/*const char& MyList::operator[ ](const int i) const
{
   assert(( 0 <= i) && (i <= size() ));
}*/

//overloaded [ ] operator
// returns writable reference to memory location 
char& MyList::operator[ ](const int i)
{
    //Program should abort via an assert statement if i is out-of-bounds.
    assert(( 0 <= i) && (i < size() ));
    
    //create new temp node at head 
    //Node* temp = head;
    int x =0;
    
    //for loop
    //start w arbitrary position (i already taken) , until x is less then i x will increase
    for (Node* curr = head ; curr != 0 ; curr = curr->next)
    {
        if (x==i)
        {
            return curr->value;
        }
        x++;
    }//end for loop
    cout << endl << "Out of range." << endl;
    //return value of temp 
    exit(1);
}

/* Newly assigned functions */
  
// checks whether list object (implicit) contains a palindrome
bool MyList::is_palindrome()const
{
    MyList string_reversed = *this; //set this to the reverse string 
    string_reversed.reverse(); //reverse it
    
    //start with both heads 
    Node* f = head; //f for forward
    Node* r = string_reversed.head; //r for reverse 
    
    while(r != NULL && f != NULL) //while neither values are null, this will stop checking in case one is somehow longer than the other. 
    {
        // "stop condition" if , at any point , the current characters/values are not equal 
        if(r->value != f->value) 
        {
            //not a palindrome 
            return false;
        }
        //continues to progress until null value or non-matching chars are found
        f = f->next;
        r = r->next;
    }  //end of while 
    //if stop condition isn't met before a null is reached ... 
    return true; //is a palindrome 
}

// merges two sorted lists (A and B) into implicit list object. 
// A and B are passed-by-copy
void MyList::merge_list(MyList A, MyList B)
{
    //nuke & redo 
    head = nullptr;
    Node* node_a = A.head;
    Node* node_b = B.head;
    
    //neither nodes are empty
    while (node_a != nullptr && node_b != nullptr)
    {
        if(node_a->value < node_b->value)
        {
            //push back value of node a
            //assign next val to node a
            push_back(node_a-> value);
            node_a = node_a->next;
        }
        else
        {
            push_back(node_b->value);
            node_b = node_b->next;
        }
    }
    //if either are null
    if(node_a == nullptr)
    {
        while(node_b != nullptr) //both
        {
            push_back(node_b->value);
            node_b = node_b->next;
        }
    }
    //repeat for a, just swap letters
    if(node_b == nullptr)
    {
        while(node_a != nullptr) //both
        {
            push_back(node_a->value);
            node_a = node_a->next;
        }
    }    
    
}

// removes al instances of char "c" from implicit list object.
//failing tests : fix to loop until all instances are removed
bool MyList::remove_char(char c)
{
    if (!head)
    {
        cout << "list is empty" << endl;
        return false;
    }
    
    else if (this->head->value == c)
    {
        Node* current = head;
        this->head = this->head->next;
        delete current;
        return true;
    }
    else
    {
        Node* prev = this-> head;
        Node* current = head->next;
        while(current != NULL)
        {
            if (current->value == c)
            {
                break;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        if(current == NULL)
        {
            cout << "No match, can't remove" << endl;
            return false;
        }
        else
        {
            prev->next = current->next;
            delete current;
            return true;
        }
        
    }
}

//returns first node's value 
char MyList::front()const
{
    //return *head->value;
    return head->value;
}
  
  