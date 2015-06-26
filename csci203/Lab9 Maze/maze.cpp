#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "stack.h"

using namespace std;

char maze[13][21] = { 	"TTTTTTTTTTTTTTTTTTTT",
						"TFTFFFFFFTFTFFFFFFFT",
						"TFTFTTTTFTFTFTTTTTTT",
						"TFTFTFFFFTFTFFFFFFFF",
						"TFTFTTTTFTFTFTTTTTTT",
						"TFTFFFFTFTFTFTFFFFFT",
						"TFTTTTTTFTFTFTFTTTFT",
						"TFFFFFFFFTFTFTFTFTFT",
						"TFTTTTTTTTFTFTFTFTFT",
						"TFTFFFFFFFFTFTFTFFFT",
						"TFTFTTTTTTTTFTFTFTTT",
						"TFTFFFFFFFFFFTFTFTFF",
						"TFTTTTTTTTTTTTTTFTTT"  };

bool solved = false;
stack myStack;
int startR = 0, startC = 0;
int endR = 12, endC = 18;
int curR, curC;

void drawMaze()
{
	cout << "     0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 " << endl;
	cout << "     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 " << endl;
	cout << "   ╔═════════════════════════════════════════╗" << endl;
	cout << " 0 ║ \033[31mA\033[0m                                       ║" << endl;
	cout << " 1 ║   ║   ╔═════════╗   ║   ╔════════════   ║" << endl;
	cout << " 2 ║   ║   ║         ║   ║   ║               ║" << endl;
	cout << " 3 ║   ║   ║   ══════╣   ║   ╠═══════════════╣" << endl;
	cout << " 4 ║   ║   ║         ║   ║   ║               ║" << endl;
	cout << " 5 ║   ║   ╚══════   ║   ║   ║   ╔═══════╗   ║" <<  endl;
	cout << " 6 ║   ║             ║   ║   ║   ║       ║   ║" << endl;
	cout << " 7 ║   ╠═════════════╝   ║   ║   ║   ║   ║   ║" << endl;
	cout << " 8 ║   ║                 ║   ║   ║   ║   ║   ║" << endl;
	cout << " 9 ║   ║   ╔═════════════╝   ║   ║   ╠═══╝   ║" << endl;
	cout << "10 ║   ║   ║                 ║   ║   ║       ║" << endl;
	cout << "11 ║   ║   ╚═════════════════╝   ║   ║   ════╣" << endl;
	cout << "12 ║   ║                             ║     \033[33mB\033[0m ║" << endl;
	cout << "   ╚═════════════════════════════════════════╝" << endl;
	
}

void solveMaze()
{
	stackItem curItem;
	int m, n;
	int line = 15;
	cout << "\033[32m";
	while (solved != true) {
		if ((curR == endR) && (curC == endC)) {	//if curent position is already the end
			solved = true;
			break;
		}

		if ((curC+1 < 20) && (maze[curR][curC+1] == 'T')) {	//try to move right
			curC++;
			curItem.row = curR;
			curItem.col = curC;
			myStack.push (curItem); //save move to the stack
			maze[curR][curC] = '*';
			m = curR+4;
			n = curC*2+6;
			cout << "\033[" << m << ";" << n << "f" << "*";
			
		}
		else if ((curR+1 < 13) && (maze[curR+1][curC] == 'T')) { //try to move down
			curR++;
			curItem.row = curR;
			curItem.col = curC;
			myStack.push (curItem);
			maze[curR][curC] = '*';
			m = curR+4;
			n = curC*2+6;
			cout << "\033[" << m << ";" << n << "f" << "*";
			
		}
		else if ((curC-1 >= 0) && (maze[curR][curC-1] == 'T')) { //try to move left
			curC--;
			curItem.row = curR;
			curItem.col = curC;
			myStack.push (curItem);
			maze[curR][curC] = '*';
			m = curR+4;
			n = curC*2+6;
			cout << "\033[" << m << ";" << n << "f" << "*";
			
		}
		else if ((curR-1 >= 0) && (maze[curR-1][curC] == 'T')) { //try to move up
			curR--;
			curItem.row = curR;
			curItem.col = curC;
			myStack.push (curItem);
			maze[curR][curC] = '*';
			m = curR+4;
			n = curC*2+6;
			cout << "\033[" << m << ";" << n << "f" << "*";
			
		}
		else {//no more possible move, backtrack
			m = curR+4;
			n = curC*2+6;
			cout << "\033[" << m << ";" << n << "f" << " ";
			myStack.pop (curItem); //go back to previous move
			curR = curItem.row;
			curC = curItem.col;
			if ( ((curC+1 < 20) && (maze[curR][curC+1] == 'T')) || ((curR+1 < 13) && (maze[curR+1][curC] == 'T')) ||
			((curC-1 >= 0) && (maze[curR][curC-1] == 'T')) || ((curR-1 >= 0) && (maze[curR-1][curC] == 'T')) )
				myStack.push (curItem);
		}
		cout.flush(); 
		usleep (500000);
	}
}
		
int main ()
{
	stackItem temp;

	system ("clear");
	drawMaze();
	curR = startR;
	curC = startC;
	temp.row = startR;
	temp.col = startC;
	myStack.push (temp);	//save starting location to stack
	solveMaze();
	cout << "\033[0m\n\n" << endl;
	return 0;
}

