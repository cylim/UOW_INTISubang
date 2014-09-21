//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:September 2nd, 2014
//This cpp file is used to read all data into to the program and 
//to save it back to repective files.
#include <iostream>
#include <fstream>
#include <cstring>
#include "dataReader.h"
using namespace std;

short readSubject(subject generalSubject[]){
	//char file[30];
	//cout << "Please enter filename: ";
	//cin >>file;
	//ifstream read(file);
	//for testing purpose, use line below,
	ifstream read("Subject/subjects.txt");

	if(!read){
		cout << "File not found!" << endl;
		// return value -1 to main(), so that main can return to 0
		return -1;
	}
	if(!read.eof()){
		read >> generalSubject[0].totalSubject;
		for(int x = 0; x < generalSubject[0].totalSubject; x++){
			read >> generalSubject[x].subjectCode;
			read.getline(generalSubject[x].subjectName, 40);
		}
	}
	read.close();

	//For testing purpose, check the output of the struct
	//for(int i = 0; i < generalSubject[0].totalSubject; i++){
	//	cout << generalSubject[i].subjectCode << "\t" << generalSubject[i].subjectName << "\n";
	//}

	return generalSubject[0].totalSubject;
}

short readStudent(student CSCI[], subject generalSubject[]){
	char subject[50];
	for(int t = 0; t < generalSubject[0].totalSubject; t++){
		//based on the subject code in subjects.txt,
		//open files for student in particular subjects.
		strcpy(subject, "Subject/");
		strcat(subject, generalSubject[t].subjectCode);
		strcat(subject, ".txt");
		ifstream read(subject);
		//if the files not found, terminated the program.
		if(!read){
			cout << subject << " not found!" << endl;
			// return value -1 to main(), so that main can return to 0
			return -1;
		}
		if(read.good()){
			read >> CSCI[t].totalStudent;
			//For testing purpose, to see how many record in the file.
			//cout << CSCI[t].totalStudent << endl;
			for(int x = 0; x < CSCI[t].totalStudent; x++){
				read >> CSCI[t].studentID[x];
				read.getline(CSCI[t].studentName[x], 30);
				read >> (CSCI[t].studentScore[x]);
				//For testing purpose, check the record correctness
				cout << CSCI[t].studentID[x] << '\t' << CSCI[t].studentName[x] << '\t' << CSCI[t].studentScore[x] << endl;
			}
		}
		read.close();
	}
	return 0;
}

void saveInfo(student CSCI[]){

}