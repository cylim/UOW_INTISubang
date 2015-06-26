#include <iostream>
#include "Dijkstras.h"

using namespace std;

int main()
{
	Graph G;
	G.Build();
	G.GetShortestPath();
	G.Output();
}

/*
from	to		distance 
1		4		10
1		2		3
1		3		6
2		3		2
3		4		1
3		5		5
4		5		2
4		6		6
5		6		3
*/

/*
1 2 2
1 4 3
2 4 4
2 3 7
2 5 5
3 5 2
3 6 3
4 5 6
5 6 4
*/