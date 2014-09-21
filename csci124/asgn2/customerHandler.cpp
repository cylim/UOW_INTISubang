//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI204
//Assignment: 2
//Date		: Sept 21st, 2014
#include "customerHandler.h"

void addCustomer(fstream& bin){
	customer cust;
	int id;
	bool found = false;
	cout << endl << "Adding new customer," << endl;
	cout << "Customer ID: ";
	cin >> cust.id;
	bin.seekg(0, ios::beg);
	while(bin.good()){
		cout << "test" << '\t';
		bin.read((char*)&id, sizeof(int));
		if(id == cust.id){
			found = true;
			break;
		}
		bin.seekg(sizeof(customer)-sizeof(int), ios::cur);
	}
	if(found == true){
		cout << "ID is already exist in the system." << endl;
	} else {
		cout << "First Name: ";
		cin >> cust.firstName;
		cout << "Last Name: ";
		cin >> cust.lastName;
		cout << "Loan Amount: ";
		cin >> cust.amount;
		cout << "Duration of payment: ";
		cin >> cust.duration;
		cout << "Interest rates: ";
		cin >> cust.interest;
		cout << "Total paid amount: ";
		cin >> cust.totalPaid;
		bin.seekp(0, ios::end);
		bin.write((char*)&cust, sizeof(customer));
	}
}
void modifyCustomer(fstream& bin){

}
void displayCustomer(fstream& bin){

}
void delCustomer(fstream& bin){

}