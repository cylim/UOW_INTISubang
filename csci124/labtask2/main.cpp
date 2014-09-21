//This is a program that read in xml files and generate output
//based on user search method, there is two search function included
//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643


#include <iostream>
#include "xmlAddress.h"
using namespace std;

int main(){
	list contact[100];
	int num=0;
	int userInput;
	num = readAddress(contact);
	//if the array returned -1, terminate the program
	if (num==-1)
		return 0;
	//Let user choose which search method wanted to be use,
	//if input is not 1 or 2, then terminate the program
	cout << "\t== Search Contacts Details ==" << endl << endl;
	cout << "1: Search by City, 2: Search by Postcode, 0: Exit" << endl
		<< "Please choose the search method: ";
	cin >> userInput;
	switch(userInput){
		case 1: 
			searchCity(num, contact);
			break;
		case 2: 
			searchPostcode(num, contact);
			break;
		default:
			cout << "Wrong Input!" << endl;
		case 0:
			cout << "Program terminated..." << endl;
			return 0;
	}
}