main		:	main.o Dijkstras.o Stack.o
				g++ -o main main.o Dijkstras.o Stack.o

main.o		:	main.cpp Dijkstras.h
				g++ -c main.cpp 

Dijkstras.o	:	Stack.h Dijkstras.h Dijkstras.cpp
				g++ -c Dijkstras.cpp

Stack.o		:	Stack.h Stack.cpp
				g++ -c Stack.cpp

clean		:
				rm *.o