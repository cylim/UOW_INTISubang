//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI204
//Assignment: 2
//Date		: Sept 21st, 2014

#include "customerHandler.h"

int main(){
	int input;
	char file[30];
	//cout << "Enter Binary Filename: ";
	//cin >> file;
	//For testing purpose, use the file below,
	strcpy(file, "example.bin");
	fstream bin(file, ios::in | ios::out | ios::binary);
	if (!file){
		cout << "Files not found." << endl;
		return 0;
	}
	while(true){
		cout << "\tBank Loan Information" << endl << endl;
		cout << "1) Add Customer Record" << "\n"
			<< "2) Modify Customer Record" << "\n"
			<< "3) Delete Customer Record" << "\n"
			<< "4) Display Customer Record" << "\n"
			<< "0) Teminate Program" << endl;
		cout << "Option: ";
		cin >> input;
		switch(input){
			case 1:
				addCustomer(bin);
				break;
			case 2:
				modifyCustomer(bin);
				break;
			case 3:
				displayCustomer(bin);
				break;
			case 4:
				delCustomer(bin);
				break;
			case 0:
				bin.close();
				cout << "Thank you for using, program terminated." << endl;
				return 0;
			default:
				cout << "Wrong input, please try again." << endl;
		}
	}
}