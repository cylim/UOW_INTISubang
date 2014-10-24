all:			task1 task2

task1: 			task1.o Circle.o
				g++ -o task1 task1.o Circle.o

task1.o:		task1.cpp Circle.h
				g++ -c task1.cpp

Circle.o:		Circle.cpp Circle.h
				g++ -c Circle.cpp

task2:			task2.o RetailItem.o
				g++ -o task2 task2.o RetailItem.o

task2.o:		task2.cpp RetailItem.h
				g++ -c task2.cpp

RetailItem.o:	RetailItem.cpp RetailItem.h
				g++ -c RetailItem.cpp

clean:			
				rm *.o