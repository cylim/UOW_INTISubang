//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:September 2nd, 2014
//This program makes update student data in particular subject easier

#include <iostream>
#include <cstring>
#include "studentHandler.h"
using namespace std;


void addStudent(student CSCI){

}
void deleteStudent(student CSCI){

}
void modifyScore(student CSCI){

}
void generateReport(student CSCI){
	char grade[3];
	cout << "Student ID\tStudent Name\tMark\tGrade\n"
		<< "----------\t------------\t----\t-----" <<  endl;
	for(int x = 0; x < CSCI.totalStudent; x++){
		if(CSCI.studentScore[x] >= 85){
			strcmp(grade, "HD");
		} 
		else if(CSCI.studentScore[x] >= 75){
			strcmp(grade, "D");
		}
		else if(CSCI.studentScore[x] >= 65){
			strcmp(grade, "C");
		}
		else if(CSCI.studentScore[x] >= 50){
			strcmp(grade, "P");
		} else {
			strcmp(grade, "F");
		}
		cout << CSCI.studentID[x] << '\t' 
			<< CSCI.studentName[x] << '\t'
			<< CSCI.studentScore[x] << '\t'
			<< grade << endl << endl;
	}
}
