//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
using namespace std;

int main(){
	int num[3]; //array declaration for storing 3 inteeger number
	//prompt user to input 3 integer number
	cout << "input numbers, " << endl;
	for(int i= 0; i<3; i++)
		cin >> num[i];
	//display all 3 integer number in array
	cout << "the numbers are, "<< endl;
	for(int i= 0; i<3; i++)
		cout << num[i] << endl;
}