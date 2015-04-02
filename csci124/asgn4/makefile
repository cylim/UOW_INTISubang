main:		main.o Training.o
			g++ -o main main.o Training.o

main.o:		main.cpp Training.h
			g++ -c main.cpp

Training.o:	Training.cpp Training.h
			g++ -c Training.cpp

clean:		
			rm *.o