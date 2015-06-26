main		:	Main.o Scheduler.o
				g++ -o main Main.o Scheduler.o

Main.o		:	Main.cpp Scheduler.h
				g++ -c Main.cpp

Scheduler.o	:	Scheduler.cpp Scheduler.h
				g++ -c Scheduler.cpp

clean		:	
				rm *.o