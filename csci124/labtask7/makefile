main:		main.o customer.o
			g++ -o main main.o customer.o

main.o:		main.cpp customer.h
			g++ -c main.cpp

customer.o: customer.cpp customer.h
			g++ -c customer.cpp

clean:
			rm *.o