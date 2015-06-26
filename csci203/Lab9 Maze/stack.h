const int  MAX_STACK = 300;	//maximum Stack size

struct stackItem {
	int row;
	int col;
};

class stack
{
    public:
        stack ();
		bool isEmpty();
		bool push (stackItem newItem);
		bool pop (stackItem &data);
		bool peek (stackItem &data);

    private:
        stackItem items[MAX_STACK]; //array of Stack items
        int top;		    // index to top of Stack
};


