//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Task		:3
//This program is to test the different between dafualt and non-default construtor

#include <iostream>
using namespace std;
//class declaration
class Address{
	string houseNum;
	string street;
	string city;
	string state;
	int postcode;
public:
	Address();
	Address(string, string, string, string, int);
	void display();
};
//class function implementation:
//default constructor
Address::Address(){
	houseNum = "12";
	street = "Jalan Pinang";
	city = "Georgetown";
	state = "Pulau Pinang";
	postcode = 11000;
}
//non-default constuctor
Address::Address(string houseNum, string street, string city, string state, int postcode){
	this->houseNum = houseNum;
	this->street = street;
	this->city = city;
	this->state = state;
	this->postcode = postcode;
}
//display all info of the class variables.
void Address::display(){
	cout << houseNum << ", " << street << endl
		<< city << endl
		<< state << " " << postcode << endl;
}
//driver program, to test the program functionality
int main(){
	Address defaultAddress; //default constructor to create object
	int postcode;
	string houseNum, street, city, state;
	//ask user to input all nessasory data
	cout << "Enter House number: ";
	getline(cin, houseNum);
	cout << "Enter street: ";
	getline(cin, street);
	cout << "Enter city: ";
	getline(cin, city);
	cout << "Enter state: ";
	getline(cin, state);
	cout << "Enter postcode: ";
	cin >> postcode;
	//call non-default constructor with all the data user input
	Address nonDefaultAddress(houseNum, street, city, state, postcode);

	//print out both default and non-default constructor data info
	cout << "\nDisplay Default Contrustor Address," << endl;
	defaultAddress.display();
	cout << "\nDisplay non-default constructor address," <<endl;
	nonDefaultAddress.display();
}