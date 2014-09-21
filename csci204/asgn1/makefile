main: 			main.o Supermarket.o
				g++ -o main main.o Supermarket.o

main.o:			main.cpp Supermarket.h
				g++ -c main.cpp

Supermarket.o:	Supermarket.cpp Supermarket.h
				g++ -c Supermarket.cpp

clean:			
				rm *.o
