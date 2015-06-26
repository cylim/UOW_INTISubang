struct cust {
	unsigned int ID;
	float arr_time;
	float srv_time;
};

struct  QueueNode		
{						// declaration of QueueNode to
    cust item;			// store items in queue 
    QueueNode *next;	// as linked list
};

class Queue
{
   public:
		Queue ();
		bool isEmpty ();
		bool enqueue (cust newItem);
		bool dequeue (cust &data);   
		bool getFront (cust &data);
		bool getBack (cust &data);
		int size ();
		void showQueue();
   private:
		QueueNode *frontPtr;	// pointer to front of Queue
		QueueNode *backPtr;		// pointer to back of Queue
		int length;				// the length of the queue
};
