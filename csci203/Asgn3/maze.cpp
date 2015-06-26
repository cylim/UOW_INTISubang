#include <algorithm>
#include <cmath>
#include <ctime>
#include "Maze.h"

maze::maze(int height, int width){
	if (height < 4 || width < 4){
		cout << "Invalid Maze size, generated with 10x10." << endl;
		this->width = 10;
		this->height = 10;
	} else {
		this->width = width;
		this->height = height;
	}
	cells.resize(this->height);
	for(int y = 0; y < this->height; y++){
		cells[y].resize(this->width, 0);
	}
}

maze::~maze(){
}

void maze::Generate(){
	srand(time(0));
	int totalCells = height * width;
	int wallDown = 1;

	int curX = 0;
	int curY = 0;

	int cellCount = 0;
	int tempCells[4][2]; // four side

	while (wallDown < totalCells){
		cellCount = 0;

		//find how many cells are available
		if	(curX - 1 >= 0 && (cells[curX - 1][curY] & 0xF0000000) == 0){
			tempCells[cellCount][0] = curX - 1;
			tempCells[cellCount++][1] = curY;
		}
		if	(curX + 1 < height && (cells[curX + 1][curY] & 0xF0000000) == 0){
			tempCells[cellCount][0] = curX + 1;
			tempCells[cellCount++][1] = curY;
		}
		if	(curY - 1 >= 0 && (cells[curX][curY - 1] & 0xF0000000) == 0){
			tempCells[cellCount][0] = curX;
			tempCells[cellCount++][1] = curY - 1;
		}
		if	(curY + 1 < width && (cells[curX][curY + 1] & 0xF0000000) == 0){
			tempCells[cellCount][0] = curX;
			tempCells[cellCount++][1] = curY + 1;
		}

		int locX, locY;

		//now according to cellCount, we know what to do
		if (cellCount == 0){
			//no unexplored cells, so go back
			//fill in once backtracking info is done
			if		( (cells[curX][curY] & 0x10000000) != 0) curX = curX - 1;
			else if ( (cells[curX][curY] & 0x20000000) != 0) curX = curX + 1;
			else if ( (cells[curX][curY] & 0x40000000) != 0) curY = curY - 1;
			else if ( (cells[curX][curY] & 0x80000000) != 0) curY = curY + 1;
			continue;
		}
		else if (cellCount == 1){
			//just one cell available so do your shit there
			locX = tempCells[0][0];
			locY = tempCells[0][1];
		}
		else{
			int index;
			index = rand() % cellCount;

			//comes here if more than 1 cell is available to choose (max 4)
			locX = tempCells[index][0];
			locY = tempCells[index][1];
		}

		//now that a cell is chosen, next what ?
		wallDown++;

		//track how u came in, so that you can backtrace, also mark that you have visited
		int dirX = locX - curX;
		int dirY = locY - curY;

		if		(dirX == 1)		cells[locX][locY] = (cells[locX][locY] | 0x10000000);	//entered from left
		else if (dirX == -1)	cells[locX][locY] = (cells[locX][locY] | 0x20000000);	//right
		else if (dirY == 1)		cells[locX][locY] = (cells[locX][locY] | 0x40000000);	//top
		else if (dirY == -1)	cells[locX][locY] = (cells[locX][locY] | 0x80000000);	//bottom

		curX = locX;
		curY = locY;
	}
}

void maze::Show(){
	cout << endl;
	for (int j = 0; j < width*2+1; j++){
		for (int i = 0; i < height*2+1; i++){
			//compulsory walls
			if (i%2 ==0 && j%2 ==0){
				//only connectors
				cout << "[]";
				continue;
			}
			else if (i%2 !=0 && j%2 !=0){
				//only rooms
				cout << "  ";
			} else {	
				//one of the walls, decide whether to print or not
				//check all four adjacent rooms to see if their path was from this point
				if (j % 2 == 0){
					//for vertical walls only
					int r = (i-1)/2;
					int c = j/2;
					if ( (!(c - 1 < 0) && (cells[r][c-1] & 0x80000000)) || 
						((c < width) && (cells[r][c] & 0x40000000)))
						cout << "  ";
					else
						cout << "[]";
				} else {
					//for horizontal walls only

					int r = i/2;
					int c = (j-1)/2;
					
					if ( (!(r - 1 < 0) && (cells[r-1][c] & 0x20000000)) || 
						((r < height) && (cells[r][c] & 0x10000000)))
						cout << "  ";
					else
						cout << "[]";
				}				
			}
		}
		cout << endl;
	}
}