#include "Bank.h"

//constructor implementation, by default, balance is 100
BankAccount::BankAccount(int ID, double balance){
	if(ID == 0){
		this->ID = accountNumber; //set ID as accountNumber
		accountNumber+=1; //increment one for accountNumber, so that other object wont get same ID
	} else {
		this->ID = ID;
	}
	//for new object, balance must be at least 100,
	if (balance < 100){
		cout << "Balance must be greater than RM100." << endl;
		this->balance = 100;
	}else{
		this->balance = balance;
	}
}
//implemantation of operator -= overloading
void BankAccount::operator-=(double amount){
	//check if amount small than balance, balance minus amout
	//else print out balance not enough
	if(balance > amount){
		balance -= amount;
	} else {
		cout << ID << " balance not enough." << endl;
	}
}

//this operator used to print out all details of an object
ostream& operator<<(ostream& out, const BankAccount &a){
	out << "Account Number: " << a.ID << endl
		<< "Balance\t: RM" << a.balance << endl;
	return out;
}

//Initialize static member of class BankAccount
int BankAccount::accountNumber = 22600;
