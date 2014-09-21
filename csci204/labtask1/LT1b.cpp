//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
using namespace std;

int main(){
	int num[3]; // array declaration for storing 3 integer value 
	int *pointer = &num[3]; // pointer point to array of num
	//prompt user to input value to the pointer
	cout << "input numbers, " << endl;
	for(int i= 0; i<3; i++)
		cin >> pointer[i];
	//display the value from the pointer
	cout << "the numbers are, " << endl;
	for(int i= 0; i<3; i++)
		cout << pointer[i] << endl;
}