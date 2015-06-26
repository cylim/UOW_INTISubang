#include <algorithm>
#include <cmath>
#include <ctime>
#include "Maze.h"

Maze::Maze(int height, int width){
	if (height < 4 || width < 4){
		cout << "Invalid Maze size, generated with 20x20." << endl;
		this->width = 20;
		this->height = 20;
	} else {
		this->width = width;
		this->height = height;
	}
	result.resize(this->height);
	checker.resize(this->height);
	maze.resize(this->height * 2 - 1);
	
	for(int y = 0; y < this->height; y++){
		result[y].resize(this->width, path(false, false));
		checker[y].resize(this->width, 0);
		maze[y].resize(this->width, false);

		for(int x = 0; x < this->width; x++){
			// unique number for each cell
			checker[y][x] = y * this->width + x; 
		}
	}
}

Maze::~Maze(){
}

// Generate the Maze
void Maze::Generate(){
	srand(time(0));
	// Randomly choose location in the maze, then carve it
	for(int i = 0; i < height * width * 10; i++){
		int x = rand() % height;
		int y = rand() % width;
		carve(x, y);
	}

	int w = 0;
	int h = 0; 
	// Use carve result to generate maze
	for(int row = 0 ; row < height * 2 - 1; row++){
		for(int col = 0; col < width * 2 - 1; col++){
			if ((row & 1) == 0 && (col & 1) == 0){
				maze[row][col] = true;
			} else {
				if (row == 0 && col < width * 2 - 1 && col & 1 != 0){
					maze[row][col] = result[h][w].right;
					w++;
				} else if ((row & 1) == 0 && col & 1 == 0) {
					maze[row-1][col] = result[h][w].up;
					w++;
				} else if (col & 1 != 0 && col < width * 2 - 1) {
					maze[row][col] = result[h][w].right;
					w++;
				}
			}
		}
		w = 0;
		if ((row & 1) == 0){
			h++;
		}
	}
}

// Display the Maze
void Maze::Show(){

	// Top Border
	cout << endl << "\t[]A ";
	for(int col = 0; col < width * 2 - 1; col++){
		cout << "[]";
	}
	cout << endl;

	for(int row = 0 ; row < height * 2 - 1; row++){
		cout << "\t[]"; // Left Border
		// Maze formatting
		for(int col = 0; col < width * 2 - 1; col++){
			cout << (maze[row][col] ? "  " : "[]");
		}
		cout << "[]" << endl; // Right Border
	}

	//Bottom Border
	cout << '\t';
	for(int col = 0; col < width * 2 - 1; col++){
		cout << "[]";
	}
	cout << " B[]" << endl;
} 

bool Maze::carve(int y, int x){
	int direction = rand() % 2;
	int checkPosition = checker[y][x]; // y is height
	int newPosition;

	// border of the maze
	// if ((direction == 0 && y == 1) ||		// TOP
	// 	(direction == 0 && x == 0) ||		// LEFT
	// 	(direction == 1 && x == width-2) ||	// RIGHT
	// 	(direction == 1 && y == height-1)){	// BOTTOM
	// 	return false;
	// }

	//choose to remove wall horizantal or vertical
	if (direction == 0){
		newPosition = checker[y-1][x];
		if(newPosition == checkPosition){
			return false;
		}
		result[y][x].up = true;
	} else {
		newPosition = checker[y][x+1];
		if(newPosition == checkPosition){
			return false;
		}
		result[y][x].right = true;
	}

	// when the checker[row][column] have same value, 
	// mean they are in a same set.
	for(int r = 0; r < height; r++){
		for(int c = 0; c < width; c++){
			if(checker[r][c] == checkPosition){
				checker[r][c] = newPosition;
			}
		}
	}
}