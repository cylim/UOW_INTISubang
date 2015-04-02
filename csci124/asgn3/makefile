main:		main.o cyber.o
			g++ -o main main.o cyber.o

main.o:		main.cpp cyber.h
			g++ -c main.cpp

cyber.o:	cyber.cpp cyber.h
			g++ -c cyber.cpp

clean:
			rm *.o