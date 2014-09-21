#ifndef STUDENT
#define STUDENT
struct student{
	short totalStudent;
	char studentID[10];
	char studentName[30];
	float studentScore;
};
#endif
//this struct is used to store subjects.txt file data
struct subject{
	short totalSubject;
	char subjectCode[8];
	char subjectName[40];
};

short readSubject(subject[]); //read subjects.txt file and import all the data
short readStudent(student[][50], subject[]); //read each subject txt files and import the data
void saveInfo(student[][50], subject[]); // save each subject to respective txt files