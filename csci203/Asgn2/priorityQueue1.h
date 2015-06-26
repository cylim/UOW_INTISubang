// \file priorityQueue.h
// \brief a print job simulation program
// \author Lim Chee Yeong 4933643
// \date May, 2015

//initialize a class to store the data of each printJob
struct printJob{
	int ID; 			// job ID
	int priority; 		// job priority
	float arrivalTime;	// arrival time of the job
	float printTime;	// time consume for the job printing
	float waitTime;		// Total wait time
};

struct QueueNode{		// declaration of QueueNode to
    printJob item;		// store items in queue 
    QueueNode *next;	// as linked list
    QueueNode *prev;	// store previous node
};

class priorityQueue{
   public:
		priorityQueue ();
		bool isEmpty ();
		bool insert (printJob newItem);
		bool pop (printJob &data);
		int size ();
		void showQueue(float = 0);
		void maxHeap();
   private:
		QueueNode *frontPtr;	// pointer to front of Queue
		QueueNode *backPtr;		// pointer to back of Queue
		QueueNode *iteratePtr;	// pointer to move around the Queue
		QueueNode *comparePtr;	//to do comparison with iterate Pointer
		int length;				// the length of the Queue
};
