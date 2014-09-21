//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
#include <fstream>
using namespace std;
//A struct declaration for storing sales person information and transaction information
//for transaction information, the first, mid and last name is not used.
struct list{
		int sid; //sales id
		char firstName[10];
		char midName[10];
		char lastName[10];
		float sales; //sales amount
};

int readTransaction(list[], float &); //function to read in transaction details
int readMaster(list[]); //function to read in sales person details
int calSales(int, int, list[], list[]); //add transcation to respective sales person
void updateMaster(list[], int, float &); //create new file to store updated details
void displayMaster(char[], float, float &); //display new record from the file

int main(){
	list salesPerson[100], transaction[100]; //create array of struct for sales person and transaction
	float weekSales=0; // calculate and store total week sales

	//The purpose of this program is to create new record file,
	//call update master list function which required the combination of transaction file and masterfile
	updateMaster(salesPerson,calSales(readMaster(salesPerson), 
		readTransaction(transaction, weekSales), transaction, salesPerson), weekSales);
}

//This function prompt user to input a transaction file name
//then validate the file, and pass the data from file into the program
int readTransaction(list transaction[], float &weekSales){
	char transFile[50];
	int i=0;
	//read in transaction file by asking user to input the file name,
	//for testing and shortcut purpose, can use the code below,
	//ifstream trans("transactionlist");
	cout << "Enter transaction file name: ";
	cin >> transFile;
	ifstream trans(transFile);

	//validate the transaction file,
	//if not found, terminate the program.
	if(!trans){
		cout << "File not found!" <<endl;
		terminate();
	}

	//Read the transaction record from file and put into struct of transaction
	cout << "Reading Transaction List data..." << endl;
	while(!trans.eof()){
		trans >> transaction[i].sid;
		trans >> transaction[i].sales;
		weekSales += transaction[i].sales;
		i++;
	}
	trans.close();
	//return the total numbers of transaction to calSales function
	//for controlling the read in cycle and prevent false data
	return i; 
}

//This function prompt user to input a master list file name
//then validate the file, and pass the data from file into the program
int readMaster(list salesPerson[]){
	char masterFile[50];
	int i=0;
	//read in sales person file by asking user to input the file name,
	//for testing and shortcut purpose, can use the code below,
	//ifstream master("masterlist");
	cout << "Enter master file name: ";
	cin >> masterFile;
	ifstream master;
	master.open(masterFile, ios::in);

	//validate the file,
	//if not found, terminate the program.
	if (!master){
		cout << "File not found!" << endl;
		terminate();
	}

	//Read the transaction record from file and put into struct of salesPerson
	cout << "Reading Master List data..." << endl;
	while(!master.eof()) {
		master >> salesPerson[i].sid;
		master >> salesPerson[i].firstName;
		master >> salesPerson[i].midName;			
		master >> salesPerson[i].lastName;
		master >> salesPerson[i].sales;
		i++;
	}
	master.close();
	//return the total numbers of salesPerson to calSales function
	//to control the read in cycle and prevent false data
	return i;
}

//This function is to update the sales person sales from transactions list
//if sales ID is not in the sales person list, prompt user to input the name of new sales person
int calSales(int num, int trans, list transactions[], list salesPerson[]){
	bool newPerson; //check whether the sid is new

	//nested for loop to checking each transaction data sid with sales person sid
	//if matched, add sales to the sales person, not match go to add new sales person
	cout << "Calculating new sales amount..." << endl;
	for(int i = 0; i<trans;i++){
		for(int j=0; j<num; j++){
			if(transactions[i].sid == salesPerson[j].sid){
				salesPerson[j].sales += transactions[i].sales;
				newPerson = false;
				break;
			} else {
				newPerson = true;
			}
		}
		//prompt user to input name for new sales person
		//and automatically update with his/her sales record
		if(newPerson == true){
			salesPerson[num].sid = transactions[i].sid;
			cout << "New ID: " << salesPerson[num].sid << ", Please enter the name: ";
			cin >> salesPerson[num].firstName 
				>> salesPerson[num].midName >> salesPerson[num].lastName;
			salesPerson[num].sales = transactions[i].sales;
			num++; //expand the reading and writing salesPerson list 
		}
	}
	//return the new total of salesPerson to update new record
	//new total must be accurate to prevent false data
	return num;
}

void updateMaster(list salesPerson[], int num, float &weekSales){
	char masterFile[50];
	float total = 0;
	//prompt user to input the filename they wanted to store new master list
	cout << "Enter new master file name: " << endl;
	cin >> masterFile;
	ofstream newMaster;
	newMaster.open(masterFile);

	//pass salesPerson info to the file
	cout << "Storing to new Master List..." << endl;	
	for(int i=0; i<num; i++){
		newMaster << salesPerson[i].sid << "\t" << salesPerson[i].firstName
					<< " " << salesPerson[i].midName << " " << salesPerson[i].lastName
					<< "\t" << salesPerson[i].sales;
		total+=salesPerson[i].sales;
		//prevent extra line of data
		if(i != num-1){
			newMaster << "\n"; 
		}
	}
	newMaster.close();
	
	displayMaster(masterFile, total, weekSales); //call display function to display the passed details
}

void displayMaster(char masterFile[], float total, float &weekSales){
	//declare for display the data from file
	int sid;
	float sales;
	char firstName[10], midName[10], lastName[10];

	ifstream display(masterFile); //open file from the filename user typed in updateMaster function

	//set the value from file to the variable declared
	cout << "Display data from new Master List..." << endl;
	cout << "SID \t Name \t\t Sales(RM)" << endl;
	while(display.good()) {
		if(!display.eof()){
			display >>sid;
			display >>firstName;
			display >>midName;
			display >>lastName;
			display >> sales;
			//display info, line by line
			cout << sid << "\t" << firstName << " " << midName
				<< " " << lastName << "\t" << sales << "\n";
		}
	}
	//display total sales and weekly sales
	cout << "Week sales: " << weekSales << endl;
	cout << "Total sales: " << total << endl;
	display.close();
}