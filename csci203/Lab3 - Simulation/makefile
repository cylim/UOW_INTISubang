main: 			Simulate.o Queue.o
				g++ -o main Simulate.o Queue.o

Simulate.o:		Simulate.cpp Queue.h
				g++ -c Simulate.cpp

Queue.o:		Queue.cpp Queue.h
				g++ -c Queue.cpp

clean:			
				rm *.o