#include <iostream>
#include <vector>
#include "command.h"
#include "node.h"

using namespace std;

class Chord{
public:
	Chord();				
	~Chord();

	void run(string);				// to indicate that the program is start running

private:
	int maxSize;					// max size of the CHORD
	bool validate;					// check whether CHORD is created
	vector<Command> cmd;			// to store command
	vector<Node> node;				// to store all nodes
	vector<int> cNode;				// to store available node index

	void init(int);					// initialize the Chord
	void addPeer(int);				// adding new peer
	void removePeer(int);			// remove a peer
	void insert(int, string);		// insert message by a peer
	void Delete(int, string);		// delete the messgae form the peer
	void print(int);				// print out the data of a node
	void find(int, int); 			// find peer node
	unsigned hash(string); 			// hashing 
	void read(string); 				// readfile
	void updateFinger();			// update FingerTable
};