#include <vector>
#include <iostream>
#include "path.h"

using namespace std;

class Maze {
public:
   Maze(int, int);
   ~Maze();
   void Generate(); // Generate the maze
   void Show(); // Display the maze

private:
   bool carve(int, int);

   int width;
   int height;
   vector<vector<path> > result;
   vector<vector<int> > checker;
   vector<vector<bool> > maze;
};