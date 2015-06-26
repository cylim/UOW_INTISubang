#include <iostream>
#include <vector>

using namespace std;

class maze {
public:
   maze(int, int);
   ~maze();
   void Generate(); // Generate the maze
   void Show(); // Display the maze

private:
   int width;
   int height;
   vector<vector<int> > cells;
};