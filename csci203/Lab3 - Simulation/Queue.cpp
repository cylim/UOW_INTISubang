
#include "Queue.h"
#include <iostream>
using namespace std;
// default constructor, which creates a new empty 
// Queue, initializing frontPtr & backPtr to NULL
Queue::Queue( ) 
{
    frontPtr = NULL;
    backPtr = NULL;
    length = 0;
}

// returns true if Queue is empty, otherwise returns false
bool Queue::isEmpty( ) 
{
    if (length == 0)
		return true;
	else
		return false;
}

// adds newItem at the back of a Queue. Returns true if
// enqueue succeeds, otherwise returns false.
bool Queue::enqueue (cust newItem)
{  
	QueueNode *pnew = new QueueNode;
	if (pnew == NULL)  
		return  false;
	pnew->item = newItem;
	pnew->next = NULL;
	if (isEmpty( )) { 
   		frontPtr = pnew;
		backPtr = pnew;
	}	
	else {  
		backPtr->next = pnew;
		backPtr = pnew;	  
	}
	length++;
	return  true;
}

// removes the item at the front of a Queue and returns it // in data. Returns true if succeeds, otherwise returns 
// false.
bool Queue::dequeue (cust &data)
{
	if (isEmpty( ))  
		return false;
	QueueNode *pnew = frontPtr;
	data = frontPtr->item;
	if (frontPtr == backPtr) {
		frontPtr = NULL;
		backPtr = NULL;
	}
	else 			      
		frontPtr = frontPtr->next;
	length--; 
	delete pnew;
	return true;
}

// retrieves a copy of the item at the front of a Queue
// and returns it in data, leaving Queue unchanged.
// Returns true if succeeds, otherwise returns false.
bool Queue::getFront (cust &data)
{
	if (isEmpty( ))  
		return false;
	data = frontPtr->item;
	return true;
}

// retrieves a copy of the item at the back of a Queue
// and returns it in data, leaving Queue unchanged.
// Returns true if succeeds, otherwise returns false.
bool Queue::getBack (cust &data)
{
	if (isEmpty( ))  
		return false;
   data = backPtr->item;
   return true;
}

// Returns the length of the queue.
int Queue::size ()
{
	return length;
}

// Display the content of the queue
void Queue::showQueue()
{
	if (!isEmpty()) {
		QueueNode *pnew = frontPtr;
		while (pnew != NULL) {
			cout << pnew->item.ID << " ";
			pnew = pnew->next;
		}
	}
	else
		cout << "---";

}