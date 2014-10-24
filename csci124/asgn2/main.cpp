//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI124
//Assignment: 2
//Date		: Sept 23rd, 2014
//This is a driver program to provide a menu driven functionality
//to call certain function to read, edit a binary file data of a bank customer

#include "customerHandler.h" // include all bank function from the header files

int main(){
	//declare a file string for user to input the file they wanted to read from
	char file[30];
	cout << "Enter Filename: ";
	cin >> file;
	//For testing purpose, use the file below,
	//strcpy(file, "example.bin");
	//when the file not found in the system, terminate the program
	ifstream bin(file, ios::binary);
	if(!bin){
		cout <<"File not found!" << endl;
		return 0;
	}
	bin.close();

	//an infinite loop to perform the menu functionality for the user to choose the option
	int input;
	while(true){
		cout << endl << "\tBank Loan Information" << endl << endl;
		cout << "1) Add Customer Record" << "\n"
			<< "2) Display Customer Record" << "\n"
			<< "3) Modify Customer Record" << "\n"
			<< "4) Delete Customer Record" << "\n"
			<< "0) Teminate Program" << endl;
		cout << "Option: ";
		cin >> input;
		switch(input){
			//add new customer into the file
			case 1:
				addCustomer(file);
				break;
			//display particular customer information, All paid customer or all unpaid customer
			case 2:
				//prompt user to choose the display method
				cout << "Display, " << endl
					<< "1) Particular Customer record" << endl
					<< "2) Finished Payment Customer" << endl
					<< "3) Outstanding Payment Customer" << endl;
				cout << "Options: ";
				cin >> input;
				displayCustomer(file, input);
				break;
			//add monthly payment to particular customer
			case 3:
				modifyCustomer(file);
				break;
			//perform delete a customer record function in the binary file
			case 4:
				delCustomer(file);
				break;
			//terminate the program 
			case 0:
				cout << "Thank you for using, program terminated." << endl;
				return 0;
			//request user to re-choose the function, as the user input is invalid
			default:
				cout << "Wrong input, please try again." << endl;
		}
	}
}