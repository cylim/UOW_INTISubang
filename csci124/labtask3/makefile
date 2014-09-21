prog:			main.o fileOperation.o chemical.o
			g++ -o prog main.o fileOperation.o chemical.o

main.o:			main.cpp fileOperation.h chemical.h
			g++ -c main.cpp

fileOperation.o:	fileOperation.cpp fileOperation.h
			g++ -c fileOperation.cpp
			
chemical.o:		chemical.cpp chemical.h
			g++ -c chemical.cpp
			
clean:			
			rm *.o
