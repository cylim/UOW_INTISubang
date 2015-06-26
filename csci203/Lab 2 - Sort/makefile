main: 			main.o Sort.o
				g++ -o main main.o Sort.o

main.o:			main.cpp Sort.h
				g++ -c main.cpp

Sort.o:	Sort.cpp Sort.h
				g++ -c Sort.cpp

clean:			
				rm *.o