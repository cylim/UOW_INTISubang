chord	:	main.o chord.o node.o
			g++ -o CHORD main.o chord.o node.o

main.o	:	main.cpp chord.h
			g++ -c main.cpp

chord.o	:	chord.cpp chord.h command.h node.h
			g++ -c chord.cpp

node.o	:	node.cpp node.h
			g++ -c node.cpp

clean	:
			rm *.o