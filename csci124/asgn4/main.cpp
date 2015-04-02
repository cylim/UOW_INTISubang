//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Assignment:4
//Date		:October 16th, 2014
//This driver program is the main menu of a Training institution Management system 
//to manage their course and the participants for each courses.

#include <iostream>
#include <fstream>
#include <cstring>
#include "Training.h"
using namespace std;

//Function Decalaration
bool addParticipant(int, Training *); // Register a new participant
bool delParticipant(int, Training *); // Remove a participant from a training session
bool modifyCourse(int, Training *); // Modify a Training details
bool display(int, Training *); // Display a Training details
void save(char[], int, Training *); // To save details back into file

int main(){
	char file[50];
	cout << "Please enter filename: ";
	cin >> file;
	// For testing purpose, use below line,
	// strcpy(file, "log.txt");
	ifstream read(file);
	//check if the file is not found, terminate the program.
	if(!read){
		cout << "File not found!" << endl;
		return 0;
	}
	cout << "Loading Training details from file..." << endl;
	int total;
	read >> total; //read first element from file as total record
	Training *course = new Training[total];
	//Read all record into class object
	for(int x=0; x<total; x++){
		int pTotal;
		char id[6], description[51], date[31], trainingTime[16], charges[8];
		read >> id;
		read.ignore();
		read.getline(description, 50);
		read.getline(date, 30);
		read.getline(trainingTime, 15);
		read >> charges;
		course[x].setCourse(id, description, date, trainingTime, charges);
		read >> pTotal;
		course[x].setTotal(pTotal);
		char pid[15], firstName[10], lastName[10];
		for(int y=0; y<pTotal; y++){
			read >> pid;
			read >> firstName;
			read >> lastName;
			course[x].setParticipant(y, pid, firstName,lastName);
		}
	}
	read.close();
	int option;
	//infinite loop for the menu
	while(true){
		//show the menu title
		cout << "\t+++++++++++++++++++++++++++++++++" << endl
			<< "\t+\tTraining Mangement\t+" << endl
			<< "\t+++++++++++++++++++++++++++++++++" << endl;
		//show the menu selection
		cout << "1. Register a new participant" << endl
			<< "2. Remove a participant from a training session" << endl
			<< "3. Modify a Training details" << endl
			<< "4. Display a Training details" << endl
			<< "0. Exit" << endl;
		cout << "Option: ";
		cin >> option;
		switch(option){
			case 1: // Register a new participant
				addParticipant(total, course);
				break;
			case 2: // Remove a participant from a training session
				delParticipant(total, course);
				break;
			case 3: // Modify a Training details
				modifyCourse(total, course);
				break;
			case 4: // Display a Training details
				display(total, course);
				break;
			case 0: // Exit
				save(file, total, course);
				delete [] course;
				cout << "Program terminated." << endl << endl;
				return 0;
			default: // Input doesn't match one of the cases
				cout << "Wrong input, please try again."<< endl << endl;
		}
	}
}

//Function implementation
// Register a new participant
bool addParticipant(int total, Training *course){
	//prompt user to enter id
	char id[6];
	cout << "Enter Training ID: ";
	cin >> id;
	//compare training id with different class object training id
	for(int x=0; x<total; x++){
		//if the training id is same, continue to add new participant
		if(strcmp(id, course[x].getID()) == 0){
			//variable declaration
			int pTotal;
			char pid[15], firstName[10], lastName[10];

			//prompt user to enter required information
			cout << "Enter Participant ID: ";
			cin >> pid;
			//if the participant id already exist, warn user and back to menu.
			for(int y=0; y<course[x].getTotal(); y++){
				if(strcmp(pid, course[x].getPID(y)) == 0){
					cout << "Participant ID existed!" << endl << endl;
					return -1;
				}
			}
			cout << "Enter Participant First Name: ";
			cin >> firstName;
			cout << "Enter Participant Last Name: ";
			cin >> lastName;
			pTotal = course[x].getTotal(); // set participant total as total from the course
			// perform adding to the training course object
			course[x].setParticipant(pTotal, pid, firstName, lastName);
			course[x].setTotal(pTotal+1);
			return 0;
		}
	}
	cout << "Training Course ID not found!" << endl << endl;
	return -1;
}
// Remove a participant from a training session
bool delParticipant(int total, Training *course){
	//prompt user to enter id
	char id[6];
	cout << "Enter Training ID: ";
	cin >> id;
	//compare training id with different class object training id
	for(int x=0; x<total; x++){
		//if the training id is same, continue
		if(strcmp(id, course[x].getID()) == 0){
			char pid[15];
			cout << "Enter Participant ID: ";
			cin >> pid;
			//if the participant id is same , perform delete operation
			for(int y=0; y<course[x].getTotal(); y++){
				if(strcmp(pid, course[x].getPID(y)) == 0){
					course[x].delParticipant(y);
					return 0;
				}
			}
			cout << "Participant ID not exist!" << endl << endl;
			return -1;
		}
	}
	cout << "Training ID not exist!" << endl << endl;
	return -1;
}
// Modify a Training details
bool modifyCourse(int total, Training *course){
	// prompt user to enter training id
	char id[6];
	cout << "Enter Training ID: ";
	cin >> id;
	// find the training id for this training course
	for(int x=0; x<total; x++){
		// if the id matched, prompt user to enter new details
		if(strcmp(id, course[x].getID()) == 0){
			char description[51], date[31], trainingTime[16], charges[8];
			cout << "Enter new Training Course ID: ";
			cin >> id;
			//if the id matched with any training id, warn users that it is existed
			for(int y=0; y<total; y++){
				if(strcmp(id, course[y].getID()) == 0){
					cout << "Training Course ID existed!" << endl << endl; 
					return -1;
				}
			}
			cin.ignore();
			cout << "Enter new description: ";
			cin.getline(description, 50);
			cout << "Enter new Date: ";
			cin.getline(date, 30);
			cout << "Enter new Time: ";
			cin.getline(trainingTime, 15);
			cout << "Enter new Charges: RM";
			cin >> charges;
			// re-set the course details for the object
			course[x].setCourse(id, description, date, trainingTime, charges);
			return 0;
		}
	}
	cout << "Training Course ID not found!" << endl << endl;
	return -1;
}
// Display a Training details
bool display(int total, Training *course){
	//prompt user to enter id
	char id[6];
	cout << "Enter Training ID: ";
	cin >> id;
	//compare training id with different class object training id
	for(int x=0; x<total; x++){
		//if the training id is same, print out the details
		if(strcmp(id, course[x].getID()) == 0){
			course[x].display();
			return 0;
		}
	}
	cout << "Training Course ID not found!" << endl << endl;
	return -1;
}
// Save details to file
void save(char file[], int total, Training *course){
	//open file and write total into it
	ofstream write(file);
	cout << "Writing Training details to file..." << endl;
	write << total;
	write.close();
	//for each Training object, write append in the file
	for(int x=0;x<total;x++){
		course[x].save(file);
	}
}