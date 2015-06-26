main: 				main.o priorityQueue.o
					g++ -o main main.o priorityQueue.o

main.o:				main.cpp priorityQueue.h
					g++ -c main.cpp

priorityQueue.o:	priorityQueue.cpp priorityQueue.h
					g++ -c priorityQueue.cpp

clean:			
					rm *.o