main	:	Maze.o main.o
			g++ -o main main.o Maze.o

Main.o	:	Maze.h main.cpp
			g++ -c main.cpp

Maze.o	:	Maze.cpp Maze.h location.h path.h
			g++ -c Maze.cpp

clean	:	
		:	rm *.o