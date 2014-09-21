//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:September 11th, 2014
//This driver file is used to test the functionality of the Supermarker.cpp.
//It has been used as a supermarket console program which allow customer to shop for item.
#include <iostream>
#include <fstream>
#include "Supermarket.h"
using namespace std;

int main(){
	short input, num, tCust; // total Customer;
	string name;
	float cash;
	bool check = false;
	Supermarket market;
	Customer cust[5];
	//read Customer.txt file from directory, put the data into Customer array objects.
	ifstream read("Customer.txt");
	if(!read){
		cout << "Can't load Customer.txt, please ensure the file is in same directory." << endl;
		return 0;
	}
	if(read.good()){
		read >> tCust;
		for(num=0;num<tCust;num++){
			read.get();
			getline(read, name, ':');
			read >> cash;
			read.get();
			cust[num] = Customer(name, cash);
		}
	}
	read.close();
	//Menu to call all sort of function from the class function.
	while(true){
		//print out the choicce for user to choose the function they needed.
		cout << "\tMenu of " << market.getName() << endl << endl;
		cout << "1) Shop\n2) Display Financial Report\n3) Display Stock Report\n4) Exit" << endl;
		cout << "Options: ";
		cin >> input;
		switch(input){
			case 1: 
				cout << "Enter Customer Name: ";
				cin.ignore();
				getline(cin, name);
				//if found the customer details, set Check to true, so it wont add new user
				for(num=0; num<tCust; num++){
					if(name.compare(cust[num].getName()) == 0){
						check = true;
						break;
					}
				}
				//if the customer name is not inside Customer.txt, add new customer with the cash he have.
				if(check == false){
					num = tCust;
					cout << "Customer " << name << " not found, record as new customer," << endl;
					cout << "Please enter Customer cash value: RM";
					cin >> cash;
					cust[num] = Customer(name, cash);
					tCust++; // increase the total customer size
				}
				//set the check to false again, to eliminate wrong result.
				check = false;
				//go to shop() function in market object, this function is used to let customer purchase items.
				market.shop(cust[num]);
				break;
			case 2:
				//go to reportFinancial() function in market object, 
				//this function is used to print out the market object cash value and stock value. 
				market.reportFinancial();
				break;
			case 3:
				//go to reportStock() function in market object, this function is used to print out every item with details.
				market.reportStock();
				break;
			default:
				//reprompt user to choose the menu
				cout << "Wrong input, please try again!" << endl << endl;
				break;
			case 4:
				//This is used to store all customer information info Customer.txt and terminate the program.
				ofstream out("Customer.txt");
				out << tCust << '\n';
				for(int i=0;i<tCust; i++){						out << cust[i].getName() << ':' 
						<< cust[i].getCash() << ":\n";
				}
				out.close();
				cout << "Thank you for using, system terminated." << endl;
				return 0;	
		}
	}
}