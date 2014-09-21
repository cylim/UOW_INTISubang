//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:August 31st, 2014
//This cpp file is used to read all data into to the program and 
//to save it back to repective files.
#include <iostream>
#include <fstream>
#include <cstring>
#include "dataReader.h"
using namespace std;

short readSubject(subject generalSubject[]){
	char file[30];
	cout << "Please enter filename: ";
	cin >> file;
	ifstream read(file);
	//for testing purpose, use line below,
	//ifstream read("Subject/subjects.txt");

	//if the file doesn't found, terminated the program
	if(!read){
		cout << "File not found!" << endl;
		// return value -1 to main(), so that main can return to 0
		return -1;
	}
	//read the first line as total subject, then go into loop to read each subject
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

short readStudent(student CSCI[][50], subject generalSubject[]){
	char subject[50];
	//A loop to call all subject from generalSubject[], and import the student data to respective location
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
		//read first line as total student
		read >> CSCI[t][0].totalStudent;
		//For testing purpose, to see how many students for each subject.
		//cout << CSCI[t][0].totalStudent << endl;

		//add student id, name and mark into array.
		for(int x = 0; x < CSCI[t][0].totalStudent; x++){
			read >> CSCI[t][x].studentID;
			read.ignore().getline(CSCI[t][x].studentName, 30);
			read >> CSCI[t][x].studentScore;
			//For testing purpose, check the record correctness
			//cout << CSCI[t][x].studentID << '\t' << CSCI[t][x].studentName << '\t' << CSCI[t][x].studentScore << endl;
		}
		read.close();
	}
	return 0;
}

void saveInfo(student CSCI[][50], subject generalSubject[]){
	char subject[50];
	//A loop to call all subject from generalSubject[], and export the student data to respective files
	for(int t = 0; t < generalSubject[0].totalSubject; t++){
		//based on the subject code in subjects.txt,
		//open files of student in particular subjects.
		strcpy(subject, "Subject/");
		strcat(subject, generalSubject[t].subjectCode);
		strcat(subject, ".txt");
		ofstream write(subject);
		//write the total students of the subject into file
		write << CSCI[t][0].totalStudent << '\n';
		//write each students details to file
		for(int x = 0; x < CSCI[t][0].totalStudent; x++){
			write << CSCI[t][x].studentID << '\n';
			write << CSCI[t][x].studentName << '\n';
			write << CSCI[t][x].studentScore << '\n';
		}
		write.close();
	}
}