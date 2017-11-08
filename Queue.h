#ifndef QUEUE_H
#define QUEUE_H


using namespace std;
class Queue
{
private:
 
   class Node;

   Node* frontPtr = nullptr;
   int num_elements = 0;

public:

   ~Queue(); //d'tor   

   int size(); //tells you the number of items in the ADT 

   void enqueue(char); //inserts item at the back of queue

   void dequeue(); //removes an item from the front of the queue

   bool isEmpty(); //checks to see if ADT is empty

   char front(); //tells us the element at the front of the list without removing it 

   void clear(); //makes the ADT empty
 

};

#endif
