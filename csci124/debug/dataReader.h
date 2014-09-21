#ifndef STUDENT
#define STUDENT
struct student{
	short totalStudent;
	char studentID[50][10];
	char studentName[50][30];
	float studentScore[50];
};
#endif

struct subject{
	short totalSubject;
	char subjectCode[8];
	char subjectName[40];
};

short readSubject(subject[]);
short readStudent(student[], subject[]);
void saveInfo(student[]);