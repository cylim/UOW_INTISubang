//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:SAugust 31st, 2014
//This program makes update student data in particular subject easier
#include <iostream>
#include <cstring>
#include <cctype>
#include "studentHandler.h"
using namespace std;

//This function is used to add students in particular subjects
void addStudent(student CSCI[]){
	int total = CSCI[0].totalStudent; //assign total students to total
	char id[10], name[30];
	float score;
	bool check = true;
	cout << "Student ID: ";
	cin >> id;
	id[0] = toupper(id[0]); //make first character to uppercase, easy for validation
	//check if id match with the data, set the boolean to false,
	//if check is false, prompt to user that the id is already in the system.
	//if id not found then ask user to imput name and score, then store it to respective location
	for(int x = 0; x < total; x++){
		//if user-input id same as student id, check = false and print "ID in the system" 
		if(strcmp(id, CSCI[x].studentID) == 0){
			check = false;
		}
	}
	//by default check is true, will prompt user to input name and mark, store it.
	if(check==true){
		cout << "Student Name: ";
		cin.ignore().getline(name, 30);
		cout << "Student Mark: ";
		cin >> score;
		//store all user key in data to respective places.
		strcpy(CSCI[total].studentID, id);
		strcpy(CSCI[total].studentName, name);
		CSCI[total].studentScore = score;
		CSCI[0].totalStudent++; //increase total students.
	} else {
		cout << "Student ID: " << id << " is in the subject!\n" << endl;
	}
}
//This function is used to delete students in particular subjects
void deleteStudent(student CSCI[]){
	int total = CSCI[0].totalStudent;
	char id[10];
	bool check = false;
	cout << "Enter Student ID: ";
	cin >> id;
	id[0] = toupper(id[0]); // make sure 1st character is uppercase
	//if the student id same as user input, next element of array replace that element,
	//then set the last element in the array to empty, and minus total students by 1,
	//set check to true, so that doesn't go into false statement
	for(int x = 0; x < total; x++){
		if(strcmp(id, CSCI[x].studentID) == 0){
			//in this loop, move every element location in the array one location forward,
			for (int i = x; i < total; i++){
				strcpy(CSCI[i].studentID, CSCI[i+1].studentID);
				strcpy(CSCI[i].studentName, CSCI[i+1].studentName);
				CSCI[i].studentScore = CSCI[i+1].studentScore;
			}
			//set last element to Null and empty string.
			strcpy(CSCI[total-1].studentID, " ");
			strcpy(CSCI[total-1].studentName, " ");
			CSCI[total-1].studentScore = 0;
			//set boolean to true and total student minus 1
			check = true;
			CSCI[0].totalStudent--;
		}
	}
	if(check == false){
		cout << "Student ID: " << id << " not found!\n" << endl;
	}
}
//This function is used to modify students mark in particular subjects
void modifyScore(student CSCI[]){
	int total = CSCI[0].totalStudent;
	char id[10];
	float score;
	bool check = false;
	cout << "Enter Student ID:";
	cin >> id;
	id[0] = toupper(id[0]); //set first character to uppercase
	//check students id with user input
	for(int x = 0; x < total; x++){
		//prompt user to input new score, set boolean to true
		if(strcmp(id, CSCI[x].studentID)==0){
			cout << "Enter new score: ";
			cin >> score;
			CSCI[x].studentScore = score;
			check = true;
		}
	}
	//if boolean is false, print students not found.
	if(check == false){
		cout << "Student ID: " << id << " not found!\n" << endl;
	}
}
//This function is to generate list of students info including Grade in particular subjects
void generateReport(student CSCI[]){
	char grade[3]; //variable declaration for grade
	cout << "Student ID\tStudent Name\tMark\tGrade\n"
		<< "----------\t------------\t----\t-----" <<  endl;
	//use studentScore to check the grade for respective student, then assign to grade
	//then print out the student details with grade.
	for(int x = 0; x < CSCI[0].totalStudent; x++){
		if(CSCI[x].studentScore >= 85){
			strcpy(grade, "HD");
		} 
		else if(CSCI[x].studentScore >= 75){
			strcpy(grade, "D");
		}
		else if(CSCI[x].studentScore >= 65){
			strcpy(grade, "C");
		}
		else if(CSCI[x].studentScore >= 50){
			strcpy(grade, "P");
		} else {
			strcpy(grade, "F");
		}
		cout << CSCI[x].studentID << '\t' 
			<< CSCI[x].studentName << "\t"
			<< CSCI[x].studentScore << '\t'
			<< grade << endl;
	}
	cout << endl << endl;
}