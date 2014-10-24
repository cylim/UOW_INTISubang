#include "check.h"

invalidMonth::invalidMonth(string month) throw(){
	this->month = month;
}
string invalidMonth::getMonth(){
	return month;
}
const char* invalidMonth::what() const throw (){
	return "Month out of range!";
}

invalidDay::invalidDay(string day) throw(){
	this->day = day;
}
string invalidDay::getDay(){
	return day;
}
const char* invalidDay::what() const throw (){
	return "Day out of range!";
}

invalidYear::invalidYear(string year) throw(){
	this->year = year;
}
string invalidYear::getYear(){
	return year;
}
const char* invalidYear::what() const throw (){
	return "Year out of range!";
}