main:				main.o dataReader.o studentHandler.o
					g++ -o main main.o dataReader.o studentHandler.o

main.o:				main.cpp dataReader.h studentHandler.h
					g++ -c main.cpp

dataReader.o:		dataReader.cpp dataReader.h
					g++ -c dataReader.cpp

studentHandler.o:	studentHandler.cpp studentHandler.h
					g++ -c studentHandler.cpp

clean:
					rm *.o