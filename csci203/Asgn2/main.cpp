// \file main.cpp
// \brief a print job simulation program
// \author Lim Chee Yeong 4933643
// \date May, 2015

#include <iostream>
#include <fstream>
#include <iomanip>
#include "priorityQueue.h"


using namespace std;

const int size = 100; // size of the total printJob
printJob jobs[size]; 	// declaration the printJob object
printJob job;	// current job the program is working on
priorityQueue pQueue;
int maxWaitJob;	// the job which waited the longest
int currentJob = 0;	// current job count that has been serviced
bool busy = false;
float processTime = 0.0;
float endCurrentServiceTime = 0.0;	// keep track service end time of current job
float nextArrivalTime = 0.0;	// keep track next arrival time of job
float waitTime = 0.0;	// keep track of total waiting time of job 
float previousTime = 0.0;

// populate data into the printJob object
bool populateData(){
	ifstream in("print_jobs.txt");	// open file name 'print_jobs.txt' as in
	// if the file is not exist, terminate the program.
	if(!in){
		cout << "File not found, program terminated." << endl;
		return false;	// to indicate that the function doesn't work properly
	}

	int counter = 0;	// to indicate the right location to store in the printJob object
	string temp;
	getline(in, temp);	// to eliminate the first line
	// if it is not end of the file, proceed read in the data to printJob object
	while(!in.eof()){
		in >> jobs[counter].ID;
		in >> jobs[counter].priority;
		in >> jobs[counter].arrivalTime;
		in >> jobs[counter].printTime;
		jobs[counter].waitTime = 0;

		counter++;	// increase the counter, to indicate next object
	}

	in.close();	// close the file
	return true;	// to indicate that the function run properly
}

// Queue customer if server is busy
void queueUp(){
	if (pQueue.getSize() > 0){
		waitTime = waitTime + ((processTime - previousTime) * pQueue.getSize());
	}
	pQueue.insert(job);

	// formatting to show the output nicely
	cout << fixed << setprecision(2) 
		<< processTime << "\t " << job.ID << " queue up\t " 
		<< waitTime << "\t\t " << endCurrentServiceTime << "\t\t";
	pQueue.showQueue(processTime - previousTime);
	cout << endl;
}

// Start to process customer if server is not busy
void processArrival(){
	if(busy){
		queueUp();
	} else {
		busy = true;
		endCurrentServiceTime = processTime + job.printTime;

		// formatting to show the output nicely
		cout << fixed << setprecision(2) 
			<< processTime << "\t " << job.ID << " starts\t " 
			<< waitTime << "\t\t " << endCurrentServiceTime << "\t\t";
		pQueue.showQueue();
		cout << endl;
	}
}

// Finish servicing current customer
void processCompleted(){
	previousTime = processTime;
	processTime = endCurrentServiceTime;
	busy = false;
	currentJob++;

	if(!pQueue.isEmpty()){
		waitTime = waitTime +((processTime - previousTime) * pQueue.getSize());
		// calculate the wait time for each job when it finished
		jobs[currentJob-1].waitTime = processTime - jobs[currentJob-1].printTime - jobs[currentJob-1].arrivalTime;
		// compare to get the longest wait time print job.
		if(jobs[maxWaitJob-1].waitTime < jobs[currentJob-1].waitTime){
			maxWaitJob = currentJob;
		}
	}

	// formatting to show the output nicely
	cout << fixed << setprecision(2) 
		<< processTime << "\t " << currentJob << " completes\t " 
		<< waitTime << "\t\t " << endCurrentServiceTime << "\t\t";
	pQueue.showQueue(processTime - previousTime);
	cout << endl;
}

int populateFiveMinutesCount(){
	int fiveMinutesCount = 0;
	for(int i=0; i<size; i++){
		if(jobs[i].waitTime >= 5){
			fiveMinutesCount += 1;
		}
	}
	return fiveMinutesCount;
}

int main(){
	if(!populateData()){ return 0; }	// populate data into printJob object, if fail terminate the program
	
	int count = 0;
	// formatting to show the output nicely
	cout << "Time\t Event\t\t Waiting Time\t Service Time\t Queue" << endl;
	cout << "============================================================================" << endl;
	cout << fixed << setprecision(2) 
		<< processTime << "\t " << "---\t\t " 
		<< waitTime << "\t\t " << endCurrentServiceTime << "\t\t";
	pQueue.showQueue();
	cout << endl;

	do{
		if(!busy){ //if server is free
			if(pQueue.isEmpty()){	//if queue is empty
				job = jobs[count];
				nextArrivalTime = job.arrivalTime;
				previousTime = processTime;
				processTime = nextArrivalTime;
			} else { //if got customer in the queue
				pQueue.remove(job);
			}
			processArrival();
			count++;
		} else { //if server is busy
			if(count < size){ //if still got customers to process
				job = jobs[count];
				nextArrivalTime = job.arrivalTime;
				//if current customer finish first before the next arrival
				if(endCurrentServiceTime <= nextArrivalTime){ 
					processCompleted();
					if(pQueue.isEmpty()){
						job = jobs[count];
						nextArrivalTime = job.arrivalTime;
						previousTime = processTime;
						processTime = nextArrivalTime;
					} else {
						pQueue.remove(job);
					}
					processArrival();
				} else {
				//if current customer finish after the next arrival
					previousTime = processTime;
					processTime = nextArrivalTime;
					processArrival();
					count++;
				}
			} else {//no more new customer
				processCompleted();
			}
		}
	} while((count < size) || (busy == true) || (pQueue.isEmpty() == false));

	cout << "\nThe average waiting time is " << waitTime / size << " minutes." << endl;
	cout << "The maximum waiting time job is " << maxWaitJob << ", which is " << jobs[maxWaitJob-1].waitTime << " minutes." << endl;
	cout << "The probability of waiting time more than 5 minutes is " << populateFiveMinutesCount() / float(size) << "." << endl << endl;

	return 0;
}