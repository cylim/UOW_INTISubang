#include <iostream>
#include <cstring>
#include <fstream>
#include "Training.h"
using namespace std;
//Class Training Implementation
//Accessor function implementation inside header.
//Mutator function implementation
void Training::setCourse(char id[],char description[],char date[],char trainingTime[],char charges[8]){
	strcpy(this->id,id);
	strcpy(this->description, description);
	strcpy(this->date, date);
	strcpy(this->trainingTime, trainingTime);
	strcpy(this->charges, charges);
}
void Training::setTotal(int total){
	this->total = total;
}
void Training::setParticipant(int num, char pid[], char firstName[], char lastName[]){
	strcpy(this->pid[num], pid);
	strcpy(this->firstName[num], firstName);
	strcpy(this->lastName[num], lastName);
}
//delete participant from object
void Training::delParticipant(int del){
	total-=1;
	strcpy(pid[del], pid[total]);
	strcpy(firstName[del], firstName[total]);
	strcpy(lastName[del], lastName[total]);
}
//display every details
void Training::display(){
	cout << "Course ID: " << id << endl
		<< "Title: " << description << endl
		<< "Date: " << date << endl
		<< "Time: " << trainingTime << endl
		<< "Charges: RM" << charges << endl
		<< "Participant details," << endl
		<< "Name\t\tParticipant ID" << endl
		<< "------------\t--------------" << endl;
	for(int x=0; x< total; x++){
		cout << firstName[x] << " " << lastName[x] << "\t" << pid[x] << endl;
	}
	cout << endl;
}
//save objects into file
void Training::save(char file[]){
	//Open file and write everything into it
	ofstream write(file, ios::app);
	write << '\n' << id;
	write << '\n' << description;
	write << '\n' << date;
	write << '\n' << trainingTime;
	write << '\n' << charges;
	write << '\n' << total;
	//check how many participant for the course is available, and write into file
	for(int x=0; x<total; x++){
		write << '\n' << pid[x];
		write << '\n' << firstName[x];
		write << '\n' << lastName[x];
	}
	write.close();
}