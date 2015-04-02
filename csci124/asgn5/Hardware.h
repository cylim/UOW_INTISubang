#include <fstream>

class Hardware{
	struct node;
	typedef node* nodeptr;
	struct node{
		int barcode;
		char description[30];
		double price;
		int quantity;
		nodeptr left,right;
	};
	nodeptr root;

	void insertnode(const int&, char[], double&, int&, nodeptr&);
	nodeptr findnode(const int&, nodeptr&);
	void inorder(nodeptr);
	void inordersave(std::ofstream&, nodeptr);
	void postorderdelete(nodeptr);
public:
	Hardware();
	~Hardware();
	void insert(const int&, char[], double&, int&);
	bool locate(const int&, char[], double&, int&);
	void inorder_traversal();
	void update(const int&, double&, int&);
	void updateQuantity(const int&, int&);
};