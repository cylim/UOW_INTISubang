//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:4
//Date		:September 4th, 2014
//This program prompt user to input data, and save into binary file.
//then perform search with seekg, seekp function.

#include <iostream>
#include "rainfallData.h"
using namespace std;

int main(){
	Rainfall data;
	int input;
	setRainfallData(data); //call function to read date from user
	while(true){
		cout << "\n\tMenu of Rainfall Anaylsis System\n" << endl;
		cout << "(1) Highest Average Rainfall\n(2) Highest Rainfall days in Month\n(3) Search by Record number\n(4) Search by Month\n(0) Exit the program" << endl;
		cout << "Options: ";
		cin >> input;
		switch(input){
			case 1:
				displayRainfall(data); //display highest average rainfall
				break;
			case 2:
				displayDay(data); //display month having hisghest rainfall
				break;
			case 3:
				searchRecord(data); //search by record number
				break;
			case 4:
				searchMonth(data); //search by month
				break;
			case 0:
				cout << "Thank you for using, program terminated!\n" << endl;
				return 0;
			default:
				cout << "Wrong Input. Please try again!\n" << endl;
		}
	}
}