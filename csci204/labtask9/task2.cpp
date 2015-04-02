//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:9 - 2
//Date		:November 9th, 2014

#include <iostream>
using namespace std;

//template class to hold an object and number of elements.
template<class T>
class Info{
	T object;
	int num;
public:
	Info(){ this->num = object.getNum(); }
	void display(){
		cout << "You will be ask to enter " << num << " details." << endl;
	}
};

//Test Class 1
class Student{
	int id, num;
	string name;
public:
	Student(){ num=2; }
	int getNum(){ return num; }
};
//Test Class 2
class Event{
	string name, date, venue;
	int headCount, num;
public:
	Event(){ num=4; }
	int getNum(){ return num; }
};


int main(){
	Info<Student> studentA;
	Info<Event> eventA;

	cout << "Student Class, " << endl;
	studentA.display();
	cout << "Event Class, " << endl;
	eventA.display();
}