#ifndef STUDENT
#define STUDENT
struct student{
	short totalStudent;
	char studentID[10];
	char studentName[30];
	float studentScore;
};
#endif

void addStudent(student[]); //Add new student to particular subjects
void deleteStudent(student[]); //Delete student from particular subjects
void modifyScore(student[]); //change students mark in particular subjects
void generateReport(student[]); //list the students details in particular subjects