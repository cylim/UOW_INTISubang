//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//This program provide various search funtion to search the chemical elements

#include "iostream"
#include "cstring"
#include "cctype" // to convert array[0] to uppercase
#include "chemical.h"

using namespace std;

void search(ChemicalElement list[], int num){
	char searchName[20];
	bool check = false; //to check whether there is any search result
	cout << "Please enter chemical element name or symbol: ";
	cin >> searchName;
	searchName[0] = toupper(searchName[0]); //convert first letter to uppercase
	cout << "Search Result: " << endl;
	cout << "Num\tSymbol\tMass\tName" <<endl;
	//if the length of characters user input is shorter than 3, perform search on symbol
	//else perform search by name
	if(strlen(searchName) < 3){
		for(int i = 0; i < num; i++){
			if(strcmp(list[i].symbol, searchName) == 0){
				cout << list[i].atomicNumber << "\t" 
					<< list[i].symbol << "\t"
					<< list[i].mass << "\t"
					<< list[i].name << endl;
				check = true;
			}
		}
	} else {
		for(int i = 0; i < num; i++){
			if(strcmp(list[i].name, searchName) == 0){
				cout << list[i].atomicNumber << "\t" 
					<< list[i].symbol << "\t"
					<< list[i].mass << "\t"
					<< list[i].name << endl;
				check = true;
			}
		}
	} 
	//if the search doesn't produce any result, display not found.
	if(check == false) {
		cout << "Atomic name or symbol " << searchName << " not found!\n";
	}
}

void greaterMass(ChemicalElement list[], int num){
	float searchMass;
	bool check = false; //to check whether there is any search result
	cout << "Please enter atomic mass greater than: ";
	cin >> searchMass;
	cout << "Search Result: " << endl;
	cout << "Num\tSymbol\tMass\tName" <<endl;
	for(int i = 0; i < num; i++){
		//only greater than mass input by user is display thru this function
		if(list[i].mass >= searchMass){
			cout << list[i].atomicNumber << "\t" 
					<< list[i].symbol << "\t"
					<< list[i].mass << "\t"
					<< list[i].name << endl;
			check = true;
		}
	} 
	//if the search doesn't produce any result, display not found.
	if(check == false) {
		cout << "Atomic Mass greater than " << searchMass << " not found!\n";
	}
}

void rangeNumber(ChemicalElement list[], int num){
	int lowRange, highRange;
	bool check = false; //to check whether there is any search result
	cout << "Search by atomic number range, " << endl; 
	cout << "From range: ";
	cin >> lowRange;
	cout << "To range: ";
	cin >> highRange;
	cout << "Search Result: " << endl;
	cout << "Num\tSymbol\tMass\tName" <<endl;
	for(int i = 0; i < num; i++){
		//compare the number <= and >=, take the value in the middle and print out
		if(list[i].atomicNumber >= lowRange && list[i].atomicNumber <= highRange){
			cout << list[i].atomicNumber << "\t" 
					<< list[i].symbol << "\t"
					<< list[i].mass << "\t"
					<< list[i].name << endl;
			check = true;
		}
	} 
	//if the search doesn't produce any result, display not found.
	if(check == false) {
		cout << "Atomic number in range " << lowRange << " and " << highRange << " not found!\n";
	}
}