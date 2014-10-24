main:				main.o customerHandler.o
					g++ -o main main.o customerHandler.o

main.o:				main.cpp customerHandler.h
					g++ -c main.cpp

customerHandler.o:	customerHandler.cpp customerHandler.h
					g++ -c customerHandler.cpp

clean:
					rm *.o