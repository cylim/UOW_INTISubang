#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//buffer struct to hold the data temporary
struct customer{
	int id;
	char firstName[15];
	char lastName[10];
	double amount;
	int duration;
	float interest;
	double totalPaid;
};

void addCustomer(char[]); //add new customer
void modifyCustomer(char[]); //modify customer record
void displayCustomer(char[], int); //display customer information
void delCustomer(char[]); // delete particular customer information