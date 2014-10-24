#include <iostream>
#include <exception>
using namespace std;

class invalidMonth:public exception{
	string month;
public:
	invalidMonth(string);
	string getMonth();
	virtual const char* what() const throw();
	virtual ~invalidMonth() throw(){}
};

class invalidDay:public exception{
	string day;
public:
	invalidDay(string);
	string getDay();
	virtual const char* what() const throw();
	virtual ~invalidDay() throw(){}
};

class invalidYear:public exception{
	string year;
public:
	invalidYear(string);
	string getYear();
	virtual const char* what() const throw();
	virtual ~invalidYear() throw(){}
};