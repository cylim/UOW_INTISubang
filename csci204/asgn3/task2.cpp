//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:3 - 2
//Date		:November 21st, 2014

#include <iostream>
#include <fstream>
#include <deque>
#include <map>
using namespace std;

class Customer{
	int id, people;
public:
	Customer(int=0,int=0);
	int getID(){ return id; }
	int getPeople(){ return people; }
};

Customer::Customer(int id, int people){
	this->id = id;
	this->people = people;
}

// For the data of Map "table"
struct Table{
	int seat, customer;
	string status;
};

typedef map<int, Table> maptype; // create a map type for passing map to function
typedef deque<Customer> dequetype; // create a deque type for passing deque to function 

void addTable(maptype&, int, int);
void assignTable(maptype&, dequetype&);
void freeTable(maptype&, int);

int main(){
	map<int, Table> table;
	deque<Customer> cust;
	Customer *c;
	int id, people, tableNo, tablePpl;

	ifstream ins("table.txt");
	//If filename not found in the system. terminated the program
	if(!ins){
		cout << "File \"table.txt\" not found!" << endl;
		return 0;
	}
	//else read all the data from file to the program
	while(ins.good()){
		if(!ins.eof()){
			ins >> tableNo;
			ins >> tablePpl;
			addTable(table, tableNo, tablePpl);
		}
	}
	ins.close();
	
	//infinite loop for the menu
	int option;
	while(true){
		//show the menu title
		cout << "\t+++++++++++++++++++++++++++++++++" << endl
			<< "\t+\tRestaurant Mangement\t+" << endl
			<< "\t+++++++++++++++++++++++++++++++++" << endl;
		//show the menu selection
		cout << "1. New customer" << endl
			<< "2. Assign table for customer" << endl
			<< "3. New table" << endl
			<< "4. Customer finish dining" << endl
			<< "0. Exit" << endl;
		cout << "Option: ";
		cin >> option;
		switch(option){
			case 1: // New customer
				cout << "Customer ID: ";
				cin >> id;
				cout << "Customer people count: ";
				cin >> people;
				c = new Customer(id, people);
				cust.push_back(*c);
				delete[] c;
				break;
			case 2: // Assign Customer to table
				assignTable(table, cust);
				break;
			case 3: // Create new table
				cout << "Table Number: ";
				cin >> tableNo;
				cout << "Table Seat Capacity: ";
				cin >> tablePpl;
				addTable(table, tableNo, tablePpl);
				break;
			case 4: // Customer leaving
				cout << "Enter Table Number: ";
				cin >> tableNo;
				freeTable(table, tableNo);
				break;
			case 0: // Exit
				cout << "Program terminated." << endl << endl;
				return 0;
			default: // Input doesn't match one of the cases
				cout << "Wrong input, please try again."<< endl << endl;
		}
	}
}
// function to create table
void addTable(maptype& table, int tableNo, int tablePpl){
	pair< map<int, Table>::iterator, bool> retval;
	Table temp;
	temp.seat = tablePpl;
	temp.customer = 0;
	temp.status = "unoccupied";
	retval = table.insert(pair<int, Table>(tableNo, temp));
	if(retval.second == false){
		cout << "Sorry, Table " << tableNo << " exist. " << endl;
	} else {
		cout << "Record Table " << tableNo << " successed." << endl;
	}
}
// function to assign customer to table
void assignTable(maptype& table, dequetype& cust){
	int validate=-1;
	map<int, Table>::iterator p = table.begin();
	map<int, Table>::iterator e = table.end();
	// In order to check the assign first customer to any empty table first,
	// loop the Customer deque before loop the table map
	for(int i=0; i<cust.size(); i++){
		for(p; p!=e; p++){
			if(p->second.status == "unoccupied"){
				if(cust.at(i).getPeople() <= p->second.seat){
					p->second.customer = cust.at(i).getID();
					p->second.status = "Occupied";
					cust.erase(cust.begin() + i); // remove the customer from deque
					cout << "Table " << p->first << ", " // Table Number
						<< p->second.status // Table current status
						<< " by Customer ID: " << p->second.customer << endl << endl; // Customer ID
					validate = 0;
					break;
				}
			}
		}
		// Every time call the function only assign one customer to table
		if (validate == 0){
			break;
		}
	}
	// To know what issue happened.
	switch(validate){
		case 1:
			cout << "Sorry, no customer suitable for current table." << endl << endl;
			break;
		case 2:
			cout << "Sorry, table is fully occupied." << endl << endl;
			break;
		case -1:
			cout << "Sorry, table full or no more customer." << endl << endl;
			break;
	}
}
// function to remove customer from table
void freeTable(maptype& table, int tableNo){
	map<int, Table>::iterator p = table.begin();

	while ( p != table.end()){
		if(p->first == tableNo){
			p->second.customer = 0;
			p->second.status = "unoccupied";
			break;
		}
		p++;
	}
}