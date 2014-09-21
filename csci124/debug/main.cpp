//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:September 2nd, 2014
//This program makes update student data in particular subject easier

#include <iostream>
#include <cctype>
#include <cstring>
#include "dataReader.h"
#include "studentHandler.h"
using namespace std;

int main(){
	subject generalSubject[10];
	student CSCI[5];
	char input, subCode[8];
	int total, subjectNum;
	bool check = false;

	total = readSubject(generalSubject);
	if(total == -1){
		return 0;
	}
	subjectNum = readStudent(CSCI, generalSubject);
	if(subjectNum == -1){
		return 0;
	}
	cout << "\t+++++++++++++++++++++++++++++++++++++++\n" 
		<< "\t++ Subject Student Management System ++\n"
		<< "\t+++++++++++++++++++++++++++++++++++++++\n" << endl;
	while (true){
		cout << "Code" << "\t\t" << "Name" << endl;
		for(int x = 0; x < total; x++){
			cout << generalSubject[x].subjectCode << ' '
				<< generalSubject[x].subjectName << endl;
		}
		cout << "Subject Code: ";
		cin >> subCode;
		for(int x = 0; x < 4; x++){
			subCode[x] = toupper(subCode[x]);
		}
		for(int x = 0; x < total; x++){
			if (strcmp(subCode, generalSubject[x].subjectCode) == 0){
				subjectNum = x;
				check = true;
				break;
			}
		}
		if (check == false){
			cout << "Subject Not found!\n" << endl;
			return 0;
		}
		cout << "(A)dd student, (D)elete student, (M)odify mark, (G)enerate report, (E)xit" << endl;
		cout << "Options: ";
		cin >> input;
		cin.clear();
		cin.ignore();
			switch(input){
			case 'A':
			case 'a':
				addStudent(CSCI[subjectNum]);
				break;
			case 'D':
			case 'd':
				deleteStudent(CSCI[subjectNum]);
				break;
			case 'M':
			case 'm':
				modifyScore(CSCI[subjectNum]);
				break;
			case 'G':
			case 'g':
				cout << "Subject Code: " << generalSubject[subjectNum].subjectCode << '\n' 
					<< "Subject Name: " << generalSubject[subjectNum].subjectName << endl;
				generateReport(CSCI[subjectNum]);
				break;
			case 'E':
			case 'e':
				saveInfo(CSCI);
				cout << "Thank you for using, program terminated!" << endl;
 				return 0;
 			default:
 				cout << "Please try again!\n" << endl;
			}
		check = false;
	}
}