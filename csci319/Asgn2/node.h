#include <vector>
#include <map>
#include <string>

using namespace std;

// datatype to store finger table
struct Finger{
	int index;
	int key;
};

// datatype to store data
struct Data {
	unsigned key;
	string message;
};

// Node class
class Node{
public:
	vector<Finger> fingerTable;			// finger table

	Node(bool, int);
	~Node();
	
	bool getState();					// check whether the node is available
	void updatePeer(vector<int>);		// set up the node
	bool insertData(unsigned, string);	// insert data to node
	bool removeData(unsigned);			// remove data from node
	void showData();					// show all the data of the node
	void showFinger();					// show the finger table of the node
	bool remove();						// remove the node
private:
	bool state;							// node status
	map<unsigned, string> data;			// data datatypes
	//int predecessor;					// node before the node
	//int successor;						// node after the node
};