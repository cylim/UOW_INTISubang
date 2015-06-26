const int  MAX_STACK = 20;	//maximum Stack size

class Stack
{
public:
	Stack();
	bool isEmpty();
	bool push(int  newItem);
	bool pop(int &data);
	bool peek(int &data);

private:
	int items[MAX_STACK]; //array of Stack items
	int top;		    // index to top of Stack
};
