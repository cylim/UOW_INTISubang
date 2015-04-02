main: 			main.o Transaction.o Hardware.o
				g++ -o main main.o Transaction.o Hardware.o

main.o:			main.cpp Transaction.h Hardware.h
				g++ -c main.cpp

Transaction.o:	Transaction.cpp Transaction.h
				g++ -c Transaction.cpp

Hardware.o:		Hardware.cpp Hardware.h
				g++ -c Hardware.cpp

clean:			
				rm *.o