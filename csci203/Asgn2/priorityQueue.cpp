// \file priorityQueue.cpp
// \brief a print job simulation program
// \author Lim Chee Yeong 4933643
// \date May, 2015

#include <iostream>
#include "priorityQueue.h"
using namespace std;

// inline function to get left or right
inline int left(int i) { return 2*i; }
inline int right(int i) { return 2*i+1; }

// Constructor
// Set the initial size as 0
priorityQueue::priorityQueue(){ 
	size = 0; 
}

// Add s to the heap with the given priority as its priority
void priorityQueue::insert(printJob node){  
	job[size] = node;
  	size++;

  	heap();
}

// Remove the string of highest priority and return that string
void priorityQueue::remove(printJob &node){
  	if (!isEmpty()){
  		node = job[0];
  		size--;

  		for(int i=0; i<size; i++){
  			job[i] = job[i+1];
  		}
  	}        
}

// Heap the queue
void priorityQueue::heap(){
	for(int i = size/2; i>=0; i--){
		int position = i;
		int child;
		do{
			child = position;
			if(left(child) <= size && job[left(child)].priority > job[position].priority){
				position = left(child);
			}
			if(right(child) <= size && job[right(child)].priority > job[position].priority) {
				position = right(child);
			}

			if(position != child){
				swap(job[position], job[child]);
			}
		} while(position != child);
	}

	//arrange();
}

// arrange the job by the shortest print time
void priorityQueue::arrange(){
	for(int i=0; i < size-1; i++){
		if(job[i].priority == job[i+1].priority){
			if(job[i].printTime < job[i+1].printTime){
				swap(job[i],job[i+1]);
			}
		}
	}
}

void priorityQueue::showQueue(float waitTime){
	if(!isEmpty()){
		int count = 0;
		while(count < size){
			//calculate the lastest wait time,
			//add it into the print job and then heap it.
			job[count].waitTime += waitTime;
			if(job[count].waitTime >= 2 && job[count].priority == 1){
				job[count].priority = 2;
				heap();
			} else if(job[count].waitTime >= 6 && job[count].priority == 2){
				job[count].priority = 3;
				heap();
			}

			if(count < 8){
				cout << job[count].ID << " ";
			} else if(count == 8){
				cout << "...";
			}
			count++;
		}
	} else {
		cout << "---";
	}
}