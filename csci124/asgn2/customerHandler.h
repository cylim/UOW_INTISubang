#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct customer{
	int id;
	char firstName[15];
	char lastName[10];
	double amount;
	int duration;
	float interest;
	double totalPaid;
};

void addCustomer(fstream&);
void modifyCustomer(fstream&);
void displayCustomer(fstream&);
void delCustomer(fstream&);