//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:2 - 1
//Date		:October 2nd, 2014
//This console program is about friend function and operator overloading.
#include "Bank.h"

void deposit(BankAccount[], int);
void withdraw(BankAccount[], int);
void compareBalance(BankAccount[], int);

int main(){
	int total = 5;
	BankAccount* acc = new BankAccount[total]; //create Bank Account object dynamically

	int input;
	//infinite loop for menu, to do specific operation
	while(true){
		cout << "\t\tBank Menu" << endl
			<< "1. Display Account Info," << endl
			<< "2. Create Account," << endl
			<< "3. Deposit to Account, " << endl
			<< "4. Withdraw from Account, " << endl
			<< "5. Compare Account Balance, " << endl
			<< "6. Display all Account Details," << endl
			<< "0. Terminate Program." << endl;
		cout << "Options: ";
		cin >> input;
		//Using If statement to perform the menu due to Switch statement is not suitable.
		if(input == 1){ //Display one account information
			// This selection prompt user to input account number, and then based on account number
			//display the details of partcular account, if account number not found, feedback to user.
			bool valid = false;
			cout << "Enter Account Number: ";
			cin >> input;
			for(int x=0; x<total;x++){
				if(acc[x].getID() == input){
					cout << acc[x];
					valid = true;
				}
			}
			if(valid == false){
				cout << "Account Number not found!" << endl << endl;
			}
		} else if(input == 2){ //create new Account
			//This selection prompt user to enter a new account number, if the account number exist, back to menu
			//else, ask user to input balance and increase the BankAccount[].
			int ID;
			double balance;
			bool valid = true;
			cout << "Enter Account Number: ";
			cin >> ID;
			BankAccount *newAcc = new BankAccount; //create object temporary store the new account details
			newAcc->setID(ID);
			//If id matched with the data, back to menu
			for(int x=0; x < total; x++){
				if(acc[x] == *newAcc){
					cout << "Sorry, ID existed!" << endl << endl << endl;
					valid = false;
					break;
				}
			}
			//if not matched, ask user input balance,
			//then move acc[] to temp[] with the newAcc,
			//delete acc[], and then point acc to temp.
			if(valid == true){
				cout << "Enter Balance: RM";
				cin >> balance;
				newAcc->setBalance(balance);
				total = total+1; // increase the total size
				BankAccount* temp = new BankAccount[total];
				for (int i=0; i<total; i++) {
					temp[i] = acc[i];	// copy values to new array.
					if(i == total-1){
						temp[i] = *newAcc; // copy newAcc to last location of temp
						delete [] newAcc; //delete newAcc
					}
				}
				delete [] acc; // delete old acc[]
				acc = temp; // point acc to temp
			}
		} else if(input == 3){ //deposit to Account
			deposit(acc, total);
		} else if(input == 4){ //withdraw from Account
			withdraw(acc, total);
		} else if(input == 5){ //compare balance(greater)
			compareBalance(acc, total);
		} else if(input == 6){ //display all account information
			for(int x=0; x< total; x++){
				cout << "Bank Account " << x+1 << "," << endl;
				cout << acc[x];
			}
		} else if(input == 0){ //delete acc and terminate program
			cout << "Thank you for using, program terminated." << endl;
			delete [] acc;
			return 0;
		} else { //wrong input warning.
			cout << "Wrong Input, Please try again." << endl;
		}
	}
}

// this function prompt user to input account number
// and based on account number, request user to input the deposit amount
// add the balance and deposit together.
// if account number not found, back to main menu.
void deposit(BankAccount acc[], int total){
	int input;
	double deposit;
	bool valid = false;
	cout << "Enter Account Number: ";
	cin >> input;
	//check whether the account number is available
	for(int x=0; x<total;x++){
		if(acc[x].getID() == input){
			cout << "Deposit: RM";
			cin >> deposit;
			acc[x] += deposit; // perform the adding.
			cout << "Account balance successfully updated to RM" << acc[x].getBalance() << endl << endl;
			valid = true;
		}
	}
	if(valid == false){
		cout << "Account Number not found!" << endl << endl;
	}
}

// this function prompt user to input account number
// and based on account number, request user to input the withdraw amount
// minus the balance with the withdraw amount.
// if account number not found, back to main menu.
void withdraw(BankAccount acc[], int total){
	int input;
	double withdraw;
	bool valid = false;
	cout << "Enter Account Number: ";
	cin >> input;
	//check whether the account number is available
	for(int x=0; x<total;x++){
		if(acc[x].getID() == input){
			cout << "Withdraw: RM";
			cin >> withdraw;
			acc[x] -= withdraw; // perform the deduction.
			cout << "Account balance updated to RM" << acc[x].getBalance() << endl << endl;
			valid = true;
		}
	}
	if(valid == false){
		cout << "Account Number not found!" << endl << endl;
	}
}

// this function compare two account number balance and return which one is greater
void compareBalance(BankAccount acc[], int total){
	int accA, accB, indexA = -1, indexB = -1;
	cout << "Enter First Account Number: ";
	cin >> accA;
	cout << "Enter Second Account Number: ";
	cin >> accB;
	//check whether both account number is exist,
	for(int x=0; x<total;x++){
		if(acc[x].getID() == accA){
			indexA = x;
		}
		if(acc[x].getID() == accB){
			indexB = x;
		}
	}
	//if one of the account is not exist, inform user that account is not found
	//if first account greater, print first account greater
	//if second account is greater, print second accoutn is greater
	//if doesn't match with either situation, print balance is same
	if(indexA == -1 || indexB == -1){
		cout << "Account not found!" << endl << endl;
	} else if(acc[indexA] > acc[indexB]){
		cout << "Account: " << accA << " balance is greater." << endl << endl;
	} else if(acc[indexA] < acc[indexB]) {
		cout << "Account: " << accB << " balance is greater." << endl << endl;
	} else {
		cout << "The balance of both account is same." << endl << endl;
	}
}