//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI124
//Assignment: 2
//Date		: Sept 23rd, 2014
#include <cstdio>
#include <cmath>
#include "customerHandler.h"
//add new customer into the file
void addCustomer(char file[]){
	customer cust; //create a struct to store data temporarily
	//prompt user to imput the id they wanted to add
	cout << endl << "Adding new customer," << endl;
	cout << "Customer ID: ";
	cin >> cust.id;
	cin.ignore();

	//initialize require items to check whether the id is available in the binary file
	bool found = false; //for checking purpose
	int id; //to store id from binary file for comparison
	ifstream bin(file, ios::binary); //open file in binary mode
	bin.seekg(0, ios::beg); //set the location point to the beginning of the file
	//when the binary file is without eofbit or other bit, 
	//read id from file to int id, and compare it to cust.id
	while(bin.good()){
		bin.read((char*)&id, sizeof(int));
		if(id == cust.id){
			found = true;
			break;
		}
		bin.seekg(sizeof(customer)-sizeof(int), ios::cur); //move the location point to next record
	}
	bin.close(); //close  binary file

	//if the id is found to be same, tell user that the id is exist, else perform add new customer
	if(found == true){
		cout << "ID is already exist in the system." << endl;
	} else {
		//get all required data from user
		cout << "First Name: ";
		cin.getline(cust.firstName, 14);
		cout << "Last Name: ";
		cin >> cust.lastName;
		cout << "Loan Amount: RM";
		cin >> cust.amount;
		cout << "Duration of payment(month): ";
		cin >> cust.duration;
		do{
			cout << "Interest rates: ";
			cin >> cust.interest;
		}while(cust.interest > 100); //interest rates must not greater than 100%
		do{
			cout << "Total paid amount: RM";
			cin >> cust.totalPaid;
		}while(cust.totalPaid > cust.amount); //paid amount must not greater than loan amount
	
		ofstream bin(file, ios::app | ios::binary); //open file in append mode, for adding record 
		bin.write((char*)&cust, sizeof(customer)); //add record into it
		bin.close(); //close file
	}
}
//add monthly payment to particular customer
void modifyCustomer(char file[]){
	//prompt user to input id
	int id;
	cout << endl << "Customer payment portal," << endl;
	cout << "Customer ID: ";
	cin >> id;

	//for checking the id from binary file
	int found = -1; 
	int location = 0;
	ifstream bin(file, ios::binary); //open binary files
	bin.seekg(0, ios::beg); //set location to begining of file
	customer cust; // create a struct to store data temporarily
	while(bin.good()){
		location = bin.tellg(); // save the location of the record
		//cout << location; // to see the location
		bin.read((char*)&cust, sizeof(customer)); //read data from file to struct
		//set found to true if the user input id same as the id in file, then break out of the loop
		if(id == cust.id){
			found = 1;
			break;
		}
	}
	bin.close();
	//when the customer paid bill is higher or equal to the customer loan, 
	//customer don't have to pay anymore, back to menu.
	if(cust.totalPaid >=cust.amount){
		cout << "The customer had cleared the payment." << endl;
		found = 0;
	}

	//when it found, perform modify action, if not found then print out customer not found
	if(found == 1){
		//print out the customer details
		cout << endl << "\tCustomer Details" << endl;
		cout << "Customer ID:\t" << cust.id << endl
			<< "Customer Name:\t" << cust.firstName << " " << cust.lastName << endl
			<< "Loan Amount:\tRM" << cust.amount << endl
			<< "Loan Period:\t" << cust.duration << "(months)" << endl
			<< "Interest Rate:\t" << cust.interest << "\%" << endl
			<< "Paid Amount:\tRM" << cust.totalPaid << endl
			<< "Outstanding:\tRM" << cust.amount - cust.totalPaid << endl;
		//declare and calculate the monthly payment
		float ratem = cust.interest / 1200.00;
		//cout << ratem << endl; //to see the value of ratem
		float expm = 1.0 + ratem;
		//cout << expm << endl; //to see the value of expm
		float monthlyPayment = (ratem * pow(expm, cust.duration) * cust.amount) / (pow(expm, cust.duration) - 1.0);

		//prompt user to input the payment value, if payment less than expected payment, print out a warning
		float pay;
		char cont = 'Y';
		//show the expected payment value
		cout << "The customer have to pay RM" << monthlyPayment << "for this month." << endl;
		do{
			cont = 'Y';
			cout << "Payment: RM";
			cin >> pay; // request input from user
			//warning user if payment less than expected payment
			if(pay < 0){
				cout << "Invalid payment!" << endl; //if payment less than 0, invalid
			} else if(pay < monthlyPayment){
				cout << "The payment is less than system requested monthly payment." << endl;
				cout << "Continue?(Y/N): ";
				cin >> cont;
			}
		}while(pay < 0 || cont == 'N' || cont == 'n');
		
		cust.totalPaid += pay; // save the payment to total paid
		fstream bin(file, ios::in | ios::out | ios::binary); //open file in update mode
		bin.seekp(location, ios::beg); //set the location to respective customer
		bin.write((char*)&cust, sizeof(customer)); //write the record
		bin.close(); //close file
	} 
	//when the customer id can't be found in the binary file, print below statement
	else if(found == -1) {
		cout << "Customer not found!" << endl;
	}
}
//display particular customer information, All paid customer or all unpaid customer
void displayCustomer(char file[], int choice){
	customer cust; //create a struct to store data temporarily
	ifstream bin(file, ios::binary); //open binary file in input mode
	bin.seekg(0, ios::beg); //set location at beginning of the file
	if(choice == 1){
		//declare id for user to choose the customer id which they wanted to display
		int id; 
		cout << "Customer ID: ";
		cin >> id;

		bool found = false; //for checking purpose, if not found, then print customer not found
		while(bin.good()){
			bin.read((char*)&cust, sizeof(customer));//read data from binary to struct
			//if the cust.id found, set boolean to true and print out customer details
			if(id == cust.id){
				found = true; //set found to true if user founded
				cout << endl << "\tCustomer Details" << endl;
				cout << "Customer ID:\t" << cust.id << endl
					<< "Customer Name:\t" << cust.firstName << " " << cust.lastName << endl
					<< "Loan Amount:\tRM" << cust.amount << endl
					<< "Loan Period:\t" << cust.duration << "(months)" << endl
					<< "Interest Rate:\t" << cust.interest << "\%" << endl
					<< "Paid Amount:\tRM" << cust.totalPaid << endl
					<< "Outstanding:\tRM" << cust.amount - cust.totalPaid << endl;
				break;
			}
		}
		//if user doesn't found, print customer not found
		if(found == false){
			cout << "Customer ID not found!"<< endl;
		}
	}
	//this part is to display customer that already paid all the loan
	else if(choice == 2){
		cout << "Customer cleared their loan," << endl;
		cout << "ID\t" << "Customer Name\t" << "Loan(RM)" << endl;
		cout << "--\t" << "-------------\t" << "--------" << endl;
		while(bin.good()){
			bin.read((char*)&cust, sizeof(customer)); //read data from binary file
			if(!bin.eof()){
				//if loan amount same as paid amount, print out the details
				if(cust.amount <= cust.totalPaid){ 
					cout << cust.id << "\t"
						<< cust.firstName << " " << cust.lastName << "\t"
						<< cust.amount << endl;
				}
			}
		}
	}
	//this part is to display customer which still havent clean the loan
	else if(choice == 3){
		cout << "Customer haven't cleared their loan," << endl;
		cout << "ID\t" << "Customer Name\t" << "Loan(RM)\t" << "Period " << "Outstanding(RM)" << endl;
		cout << "--\t" << "-------------\t" << "--------\t" << "------ " << "---------------" << endl;
		while(bin.good()){
			bin.read((char*)&cust, sizeof(customer)); //read data from binary file
			if(!bin.eof()){
				//when loan amount is greater than paid amount, pring the customer data
				if(cust.amount > cust.totalPaid){
					cout << cust.id << "\t"
						<< cust.firstName << " " << cust.lastName << "\t"
						<< cust.amount << "\t\t"
						<< cust.duration << "\t" 
						<< cust.amount - cust.totalPaid << endl;
				}
			}
		}
	}
	//this happen when user input is not 1 or 2 or 3
	else{
		cout << "Wrong input, back to menu." << endl;
	}
	bin.close(); //close the file
}
//perform delete a customer record function in the binary file
void delCustomer(char file[]){
	//declare id for user to input
	int id;
	cout << endl << "Delete customer record," << endl;
	cout << "Customer ID: ";
	cin >> id;

	bool found = false; //for checking whether the customer id exist
	ifstream bin(file, ios::binary); //open binary file in input mode
	ofstream temp(".temp.bin", ios::app | ios::binary); //open temporary file in output append mode
	bin.seekg(0, ios::beg); //set location point at the begining of binary file
	customer cust;
	while(bin.good()){
		bin.read((char*)&cust, sizeof(customer));
		if(!bin.eof()){
			//when the user input id is different than the customer id, write it into temporary file
			if(id != cust.id){
				temp.write((char*)&cust, sizeof(customer));
			}
			//if founded the id, then dont write it into write and set boolean to true 
			else if(id == cust.id) {
				found = true;
			}
		}
	}
	//if customer id not found, print out the info
	if(found != true)
		cout << "Customer ID not found!" << endl;

	temp.close(); //close temporary file
	bin.close(); // close binary file
	remove(file); // remove binary file
	rename(".temp.bin", file); //rename temporary file to binary file name
}