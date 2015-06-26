// \file priorityQueue.cpp
// \brief a print job simulation program
// \author Lim Chee Yeong 4933643
// \date May, 2015

#include "priorityQueue.h"
#include <iostream>
#include <queue>
using namespace std;

// default constructor, which creates a new empty 
// priorityQueue, initializing frontPtr & backPtr to NULL
priorityQueue::priorityQueue(){
    frontPtr = NULL;
    backPtr = NULL;
    iteratePtr = NULL;
    comparePtr = NULL;
    length = 0;
}

// returns true if priorityQueue is empty, otherwise returns false
bool priorityQueue::isEmpty(){
    if(length == 0){
		return true;
    } else {
		return false;
	}
}

// adds newItem at the back of a priorityQueue. Returns true if
// enqueue succeeds, otherwise returns false.
bool priorityQueue::insert(printJob newItem){  
	QueueNode *pnew = new QueueNode;
	if (pnew == NULL){ 
		return false; 
	}
	pnew->item = newItem;
	pnew->next = NULL;
	pnew->prev = NULL;
	if(isEmpty()){ 
   		frontPtr = pnew;
		backPtr = pnew;
	} else { 
		pnew->prev = backPtr;
		backPtr->next = pnew;
		backPtr = pnew;
		maxHeap();
	}
	length++;
	return true;
}

// removes the item at the front of a priorityQueue and returns it 
// in data. Returns true if succeeds, otherwise returns false.
bool priorityQueue::pop(printJob &data){
	if(isEmpty()){
		return false;
	}
	data = frontPtr->item;
	if(frontPtr == backPtr){
		frontPtr = NULL;
		backPtr = NULL;
	} else {			      
		frontPtr = frontPtr->next;
	}
	length--; 
	return true;
}

// Returns the length of the queue.
int priorityQueue::size(){
	return length;
}

// Display the content of the queue
void priorityQueue::showQueue(float waitTime){
	if(!isEmpty()){
		QueueNode *pnew = frontPtr;
		int count = 0;
		while(pnew != NULL){

			//calculate the lastest wait time,
			//add it into the print job and then heap it.
			pnew->item.waitTime += waitTime;
			if(pnew->item.waitTime >= 2 && pnew->item.priority == 1){
				pnew->item.priority = 2;
				maxHeap();
			} else if(pnew->item.waitTime >= 8 && pnew->item.priority == 2){
				pnew->item.priority = 3;
				maxHeap();
			}

			if(count < 8){
				cout << pnew->item.ID << " ";
			} else if(count == 8){
				cout << "...";
			}
			pnew = pnew->next;
			count++;
		}
	} else {
		cout << "---";
	}
}

// Max heap the queue by the priority
void priorityQueue::maxHeap(){
	if(!isEmpty()){
		iteratePtr = backPtr;
		comparePtr = iteratePtr->prev;
		while(iteratePtr->prev != NULL){
			if(iteratePtr->item.priority > comparePtr->item.priority){
				// To check the output before swap
				// cout << "\nq" << iteratePtr->item.ID << ' '
				//  	<< iteratePtr->next << ' ' 
				//  	<< iteratePtr->prev->item.ID << endl;
				swap(iteratePtr->item, comparePtr->item);
				// To check the output before swap
			  	// cout << "q" << iteratePtr->item.ID << ' ' 
			  	//   	<< iteratePtr->next << ' ' 
				// 		<< iteratePtr->prev->item.ID << endl;
				// cout << "q" << comparePtr->item.ID << ' ' 
			  	//   	<< comparePtr->next->item.ID << ' ' 
				// 		<< comparePtr->prev << endl;

				if(iteratePtr->next == NULL){
				   	backPtr = iteratePtr;
				   	// To check the output before swap
				   	// cout << "backPtr: " << backPtr->item.ID << endl;
				   	// cout << backPtr->prev->item.ID;
				}
				if(comparePtr->prev == NULL){
			    	frontPtr = comparePtr;
			    	// To check the output before swap
			    	// cout << "frontPtr: " << frontPtr->item.ID << endl;
			    	// cout << frontPtr->next->item.ID << endl;
			    	break;
		    	}
		    }
			iteratePtr = iteratePtr->prev;
			comparePtr = iteratePtr->prev;
		}
	}
}