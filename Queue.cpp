#include "Queue.h"
#include <iostream>
#include <stdexcept>//used to be able to "throw" exceptions
#include <string>

using namespace std;

class Queue::Node //self-referential Node class
{
	public:
	   char data = ' ';
	   Node* link = nullptr;
	   //link is a data member which is a pointer 
	   //to an object of the same type (i.e. Node)
	
};//end Node class definition (can only be seen by the List class)

Queue::~Queue(){

   while(num_elements > 0)
      dequeue();

}
	
int Queue::size()
{
    return num_elements;
 }

void Queue::enqueue(char k)
{
	
	Node* newPtr = new Node{k};
	Node* tmpPtr = frontPtr;
	int loc = 1; 
	
	  if(num_elements == 0){

	newPtr->link = frontPtr;
	frontPtr = newPtr;
	num_elements++;
	return;

	}

	    while( loc != num_elements) //get pointer to (k-1)th node
	     {
		tmpPtr = tmpPtr->link;
		loc++;
	     }
	
	  newPtr->link = tmpPtr->link;
	  tmpPtr->link = newPtr;  
	 num_elements++;
	 
 }

void Queue::dequeue()
{
	
	if(num_elements == 0){

	throw out_of_range("Queue::dequeue() Empty Queue");

	} 
	
	Node* delPtr = nullptr;
	delPtr = frontPtr;
	frontPtr = frontPtr->link;
	delete delPtr;
	num_elements--;
}
	
	

void Queue::clear()
{

  while(size() != 0)
  {
      dequeue();
  }

}

char Queue::front()
{
	if(num_elements == 0){

	throw out_of_range("Queue::front() Empty Queue");
	
	}

	Node* printPtr = nullptr;
	
	  printPtr = frontPtr;
	  return printPtr->data;	

}


bool Queue::isEmpty()
{

	bool empty = false;

	if(num_elements == 0){

	 empty = true;
	
	}

  return empty;

}




