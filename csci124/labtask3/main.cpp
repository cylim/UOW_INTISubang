//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//This program read files into binary
//and provide various search funtion to search the chemical elements

#include <iostream>
#include "fileOperation.h"
#include "chemical.h"
using namespace std;

int main(){
	ChemicalElement list[150];
	int num; //size of array
	char input; //user input for selecting the option of search
	num = readToBinary(list);
	//when there is problems in readToBinary(), terminate the program
	if(num == -1){
		return 0;
	}
	//let user to choose the search method they wanted
	//if wrong input or 'e', terminate the program.
	cout << "Search Method: " << endl;
	cout << "(N)ame or symbol, (M)ass, (A)tomic number, (E)xit" << endl;
	cout << "Options: ";
	cin >> input;
	switch(input){
		case 'N':
		case 'n':
			search(list, num); //goto function for searching name or symbol
			break;
		case 'M':
		case 'm':
			greaterMass(list, num); //goto function for searching mass
			break;
		case 'A':
		case 'a':
			rangeNumber(list, num); //goto function for search the range of atomic number
			break;
		default:
			cout << "Wrong input, ";
		case 'E':
		case 'e':
			cout << "Program terminated!" << endl;
 			return 0;
	}	
}