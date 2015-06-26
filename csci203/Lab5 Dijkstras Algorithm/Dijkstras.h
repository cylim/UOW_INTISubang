#define INFINITY 999
#define SIZE 20

class Graph
{
private:
	int L[SIZE][SIZE];
	int P[SIZE], D[SIZE];
	bool S[SIZE];
	int source;
	int numOfNodes;
public:
	Graph();
	void Build();
	void GetShortestPath();
	void Output();
	void PrintPath(int);
};


