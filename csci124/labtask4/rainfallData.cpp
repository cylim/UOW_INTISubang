//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:4
//Date		:September 4th, 2014
//This program prompt user to input data, and save it into binary file.
#include <fstream>
#include <iostream>
#include <cstring>
#include <cctype>
#include "rainfallData.h"
using namespace std;

void setRainfallData(Rainfall data){
	char check;
	//int total=0; //for checking the binary file
	ofstream bin("data.bin", ios::out | ios::binary);

	cout << "Add Rainfall Record," << endl;
	do{
		cout <<	"Month: ";
		cin >> data.month;
		for(int i=0; i<10;i++){
			data.month[i] = toupper(data.month[i]);
		}

		do{
			cout << "Days with rain: ";
			cin >> data.daysWithRain;
		} while(data.daysWithRain < 1 || data.daysWithRain > 31);

		cout << "Average Rainfall: ";
		cin >> data.avgRainfall;

		cout << "Continue add record? (Y/N)";
		cin >> check;
		bin.write((char*)&data, sizeof(Rainfall));
		//total+=1; //for checking the binary file
	}while(check == 'y' || check == 'y');
	bin.close();	
	//For testing purpose, to see whether retrieve from binary is correct
	// ifstream in("data.bin", ios::in | ios::binary);
	// for(int i = 0; i < total; i++){
	//  	in.read((char*)&data, sizeof(Rainfall));
	//  	cout << data.month << '\t'
	//  		<< data.daysWithRain << '\t'
	//  		<< data.avgRainfall << endl;
	// }
	// in.close();
}
void displayRainfall(Rainfall data){
	ifstream in("data.bin", ios::in | ios::binary); //open binary files
	char month[10];
	int daysWithRain;
	float avgRainfall =0;
	while(in.read((char*)&data, sizeof(Rainfall))){
		//check if the avarage rainfall lower than data, if so update it.
		if (data.avgRainfall > avgRainfall){
			strcpy(month, data.month);
			daysWithRain = data.daysWithRain;
			avgRainfall = data.avgRainfall;
		}
	}
	//print out the record with highest average rainfall
	cout << "Month: " << month << endl
	 	<< "Days: " << daysWithRain << endl
	 	<< "Average Rainfall: " << avgRainfall << endl; 
	cout << endl << endl;
	in.close(); //close file
}
void displayDay(Rainfall data){
	ifstream in("data.bin", ios::in | ios::binary); //open binary files
	char month[10];
	int daysWithRain = 0;
	float avgRainfall;
	//check if the raining days lower than data, if so update it.
	while(in.read((char*)&data, sizeof(Rainfall))){
		if (data.daysWithRain > daysWithRain){
			strcpy(month, data.month);
			daysWithRain = data.daysWithRain;
			avgRainfall = data.avgRainfall;
		}
	}
	//print out the record with highest rainfall days.
	cout << "Month: " << month << endl
	 	<< "Days: " << daysWithRain << endl
	 	<< "Average Rainfall: " << avgRainfall << endl; 
	cout << endl << endl;
	in.close(); //close file
}
void searchRecord(Rainfall data){
	short record;
	int size;
	ifstream in("data.bin", ios::in | ios::binary); //open binary files
	in.seekg(0, ios::end);
	size = in.tellg() / sizeof(Rainfall);  //to know how many record in file
	//check if the record enter by user is correct or wrong.
	cout << "There is " << size << " record in the file." << endl;
	do{
		cout << "Record Number: ";
		cin >> record;
	}while(record < 1 || record > size);
	in.seekg((record-1)*sizeof(Rainfall), ios::beg); //change the location to that record
	in.read((char*)&data, sizeof(Rainfall)); //read that record
	//print out the record user wanted.
	cout << "Month: " << data.month << endl
	 	<< "Days: " << data.daysWithRain << endl
	 	<< "Average Rainfall: " << data.avgRainfall << endl; 
	cout << endl << endl;
	in.close(); //close file
}
void searchMonth(Rainfall data){
	char month[10];
	cout << "Enter Month: ";
	cin >> month;
	for(int i=0; i<10;i++){
		month[i] = toupper(month[i]);
	}
	ifstream in("data.bin", ios::in | ios::binary); //open binary files
	cout << "Month\tDays\tAverage Rainfall\n";
	//check if the user input month same as the month in file, is so print out.
	while(in.read((char*)&data, sizeof(Rainfall))){
		if(strcmp(month, data.month) == 0){
			cout << data.month << '\t'
	 			<< data.daysWithRain << '\t'
	 			<< data.avgRainfall << endl;
		}
	}
	cout << endl << endl;
	in.close(); //close file
}