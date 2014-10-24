all:		task1 task2

task1:		task1.o Bank.o
			g++ -o task1 task1.o Bank.o

task1.o:	task1.cpp Bank.h
			g++ -c task1.cpp

Bank.o:		Bank.cpp Bank.h
			g++ -c Bank.cpp

task2:		task2.o Container.o
			g++ -o task2 task2.o Container.o

task2.o:	task2.cpp Container.h
			g++ -c task2.cpp

Container.o:Container.cpp Container.h
			g++ -c Container.cpp

clean:
			rm *.o