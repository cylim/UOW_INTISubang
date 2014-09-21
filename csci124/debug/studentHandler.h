#ifndef STUDENT
#define STUDENT
struct student{
	short totalStudent;
	char studentID[50][10];
	char studentName[50][30];
	float studentScore[50];
};
#endif

void addStudent(student);
void deleteStudent(student);
void modifyScore(student);
void generateReport(student);