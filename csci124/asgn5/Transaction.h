class Transaction{
		struct node;
	typedef node* nodeptr;
	struct node{
		int invoice;
		int barcode[10];
		char description[10][30];
		double price[10];
		int quantity[10];
		int totalType;
		nodeptr next;
	};
	nodeptr head;
	double totalPrice;
public:
	Transaction();
	~Transaction();
	void push_back(int);
	bool isempty();
	void display();
	void remove(int);
	void edit(int, int&, int&, int&, int&);
	void add(int, int, char[], double, int);
};