main		:	Main.o Match.o
				g++ -o main Main.o Match.o

Main.o		:	Main.o Main.cpp
				g++ -c Main.cpp

Match.o		: 	Match.o Match.cpp
				g++ -c Match.cpp

clean		: 	rm *.o