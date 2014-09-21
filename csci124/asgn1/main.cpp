//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:August 31st, 2014
//This program read subjects.txt, and based on subjects.txt
//read in all subject specified, and provide the funciton to
//make changes to all this subject student.

#include <iostream>
#include <cctype>
#include <cstring>
#include "dataReader.h"
#include "studentHandler.h"
using namespace std;

int main(){
	subject generalSubject[10]; //Array to store subject
	student CSCI[10][50]; //2d Array to store students details in each subject
	char input, subCode[8]; //for choosing menu and subject to edit
	int total, subjectNum; //total subject and each subject number itself.
	bool check = false; //boolean to make checking
	//call readSubject() to read in subject info to struct generalSubject[]
	total = readSubject(generalSubject);
	//if reading the file have any problems, terminate the program.
	if(total == -1){
		return 0;
	}
	//call function readStudent() to read student info for each subject
	subjectNum = readStudent(CSCI, generalSubject);
	//if any issues occur when reading info, terminate the program
	if(subjectNum == -1){
		return 0;
	}

	cout << "\t+++++++++++++++++++++++++++++++++++++++\n" 
		<< "\t++ Subject Student Management System ++\n"
		<< "\t+++++++++++++++++++++++++++++++++++++++\n" << endl;
	//infinite loop function as the menu for edit students info in each subject.
	while (true){
		//print out every subjects details from generalSubject[]
		cout << "Code" << "\t\t" << "Name" << endl;
		for(int x = 0; x < total; x++){
			cout << generalSubject[x].subjectCode << ' '
				<< generalSubject[x].subjectName << endl;
		}
		//prompt user to choose subject
		cout << "Subject Code: ";
		cin >> subCode;
		//set first 4 character to uppercase, to eliminate case-sensitive erroe
		for(int x = 0; x < 4; x++){
			subCode[x] = toupper(subCode[x]);
		}
		//looking for the subject, store the subject number to subjectNum, set boolean to true
		for(int x = 0; x < total; x++){
			if (strcmp(subCode, generalSubject[x].subjectCode) == 0){
				subjectNum = x;
				check = true;
				break;
			}
		}
		//if input doesn't found, boolean is false, update the files then terminate the program
		if (check == false){
			cout << "Subject Not found, program terminated!\n" << endl;
			return 0;
		}
		//menu for editing student data in particular subject
		while(check == true){
			cout << "\n\tMenu of" << generalSubject[subjectNum].subjectName << endl;
			cout << "(A)dd Student\n(D)elete Student\n(M)odify Mark\n(L)ist Students Details\n(B)ack to Course Selection\n(E)xit Program" << endl;
			cout << "Options: ";
			cin >> input;
			cin.clear();
			cin.ignore();
			switch(input){
				//when user enter A or a, go into addStudent() function to add new student to particular subject
				case 'A':
				case 'a':
					addStudent(CSCI[subjectNum]); //call function addStudent()
					break;
				//when user enter D or d, perform delete student function
				case 'D':
				case 'd':
					deleteStudent(CSCI[subjectNum]); //call function deleteStudent()
					break;
				//when user entered M or m, let user to change student score
				case 'M':
				case 'm':
					modifyScore(CSCI[subjectNum]); //call function modifyScore()
					break;
				//when user entered G or g, list out the subject students information
				case 'L':
				case 'l':
					cout << "Subject Code: " << generalSubject[subjectNum].subjectCode << '\n' 
						<< "Subject Name: " << generalSubject[subjectNum].subjectName << endl;
					generateReport(CSCI[subjectNum]); //call function generateReport()
					break;
				//when user entered B or b, back to the subject choosing menu
				case 'B':
				case 'b':
					saveInfo(CSCI, generalSubject);
					cout << generalSubject[subjectNum].subjectCode << " saved.\n" << endl;
					check =false;
					break;
				//when user enter E or e, save all struct to files, then terminate the program
				case 'E':
				case 'e':
					saveInfo(CSCI, generalSubject); //call function saveInfo()
					cout << generalSubject[subjectNum].subjectCode << " saved." << endl;
					cout << "Thank you for using, program terminated!" << endl;
 					return 0;
 				//If user enter input don't matched with either one, ask user to retry.
 				default:
 					cout << "Please try again!\n" << endl;
			}
		}
	}
}