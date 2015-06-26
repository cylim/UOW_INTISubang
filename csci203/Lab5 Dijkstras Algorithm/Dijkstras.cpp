#include <iostream>
#include "Dijkstras.h"
#include "Stack.h"

using namespace std;

Graph::Graph()
{
	for(int i=0; i<SIZE;i++) {
		S[i] = false;
		P[i] = -1;
		D[i] = INFINITY;
	}
}

void Graph::Build()
{
	int i, j;

	cout << "Enter the number of nodes of the graph (should be > 0) : ";
	cin >> numOfNodes;
	
	//Read the adjacency matrix for the graph
	cout << "Enter the distance of each node-pair for the graph\n";
	cout << "Enter a negative node number to stop\n";
	for(i=0; i<numOfNodes; i++) {
		for(j=0; j<numOfNodes; j++) {
			L[i][j] = INFINITY;
		}
	}
	do {
		cout << "From "; cin >> i;
		cout << "To ";	cin >> j;
		if (i <= 0 || j <= 0)
			break;
		cout << "Distance is "; 
		cin >> L[i-1][j-1];
		cout << endl;
		L[j - 1][i - 1] = L[i - 1][j - 1];
	} while (i != 0 && j != 0);
	//read the source node from which the shortest paths to other nodes has to be found
	cout << "Enter the source node : ";
	cin >> source;
	cout << endl;
	while ((source <= 0) && (source > numOfNodes-1)) {
		cout << "Source node should be between 1 and " << numOfNodes << endl;
		cout << "Enter the source node again\n";
		cin >> source;
	}
	source = source - 1;
}


void Graph::GetShortestPath()
{
	int minD = INFINITY;
	int v, w, temp, nearest;
	int count = 1;	// keep track on how many nodes has been chosen
					// set to 1 because the source node is chosen initially
	// mark the source node as chosen
	v = source;
	S[v] = true;

	for (int j=0; j<numOfNodes; j++) {
		D[j] = L[source][j];
		if (D[j] != INFINITY)
			P[j] = source;
	}
	D[source] = 0;

	while (count < numOfNodes) { // while there are still nodes yet to be chosen
		minD = INFINITY;
		for (int j = 0; j < numOfNodes; j++) {
			if ((S[j] == false) && (D[j] < minD)) {
				minD = D[j];
				v = j;
			}
		}
		S[v] = true;

		for (int w=0; w<numOfNodes; w++) {
			if ((S[w] == false) && (L[v][w] != INFINITY)) {
				// if the D from source->v->node is less than the 
				// recorded D, then set it to be the new recorded D
				// and set Predecessor to v
				if ((D[v] + L[v][w]) < D[w]) { 
					D[w] = D[v] + L[v][w];
					P[w] = v;
				}
			}
		}
		count++;
	}
}

void Graph::PrintPath(int node)
{
	int predecessor, m;
	Stack myStack;
	if(P[node] == -1){
		cout << "No path from " << source+1 << " to " << node+1 << endl;
	}else{
		predecessor = P[node];
		while(predecessor != source){
			myStack.push(predecessor);
			predecessor = P[predecessor];
		}
	}
	cout << source+1 << " -> "
	while(!myStack.isEmpty()){
		myStack.pop(m);
		cout << m+1 << " -> ";
	}
	cout << node+1;
}

void Graph::Output()
{
	// print the path from source node to all other nodes
	for (int i = 0; i<numOfNodes; i++) {
		if (i != source) {
			PrintPath(i);
			if (P[i] != -1)
				cout << " distance is " << D[i] << endl;
		}
	}
}

