#include <cstdlib>
#include "maze.h"

// Generate and display a random maze.
int main(int argc, char *argv[]){
   int height = 0;
   int width = 0;
   cout << "\t++++++++++++++++++++++++++++++++++++++++++" << endl
         << "\t++\t\tMaze Generator\t\t++" << endl
         << "\t++++++++++++++++++++++++++++++++++++++++++" << endl;

   if(argc == 3){
      height += atoi(argv[1]);
      width += atoi(argv[2]);   
   } else {
      cout << "Please enter height of maze: ";
      cin >> height;
      cout << "Please enter width of maze: ";
      cin >> width;
   }

   maze m(height, width);
   m.Generate();
   m.Show();
   return 0;
}