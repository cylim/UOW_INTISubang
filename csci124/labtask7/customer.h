#include <iostream>
#include <fstream>
using namespace std;

struct Cust{
	int id;
	char firstName[51];
	char lastName[51];
	char contact[21];
};

int checkTotal(char[]); // check the total record
void read(Cust*, char[]); // read data to array of struct
void sort(Cust*, int); // sort the array of struct
void search(Cust*, int, int); // perform search ooperation to find particular ID