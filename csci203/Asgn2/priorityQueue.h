// \file priorityQueue.h
// \brief a print job simulation program
// \author Lim Chee Yeong 4933643
// \date May, 2015

struct printJob {
  int ID;             // job ID
	int priority;       // job priority
	float arrivalTime;	// arrival time of the job
	float printTime;    // time consume for the job printing
	float waitTime;     // Total wait time
};

class priorityQueue {
private:
	printJob job[100];  // Maximum job allow in the queue
 	int size;           // Current queue size

 	void heap();        // Sorting the job by priority
  void arrange();     // Rearrange the job with same priority but shortest job first

public:
  priorityQueue(); 			   // Constructor				
  void insert(printJob);   // Add job to the queue
  void remove(printJob&);  // Remove job from the queue
  void showQueue(float=0); // display data inside the queue

	// Check whether the queue is empty
	inline bool isEmpty(){ return (size == 0); }
 	// Return size of the queue
 	inline int getSize(){ return size; }
};