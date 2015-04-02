all: 		task1 Symbolic task3

task1:		task1.o
			g++ -o task1 task1.o

task1.o:	task1.cpp
			g++ -c task1.cpp

Symbolic:	Symbolic.o
			g++ -o Symbolic Symbolic.o

Symbolic.o:	Symbolic.cpp
			g++ -c Symbolic.cpp

task3:		task3.o class.o
			g++ -o task3 task3.o class.o

task3.o:	task3.cpp class.h
			g++ -c task3.cpp

class.o:	class.cpp class.h
			g++ -c class.cpp

clean:
			rm *.o