//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI204
//Task		: 8 -2
//Date		: October 28th, 2014
//To test the uses of templete function
#include <iostream>
using namespace std;

template <class T>
void addSymbol(T input, int num, char symbol){
	// print out the user requested symbol before
	for(int x=0; x<num; x++){
		cout << symbol;
	}
	cout << input; //print the message
	// print out the user requested symbol after
	for(int x=0;x<num;x++){
		cout << symbol;
	}
	cout << endl;
}

int main(){
	//testing four different variable type of function
	addSymbol('A', 2, 'x');
	addSymbol(47, 3, '*');
	addSymbol(39.25, 3, '0');
	addSymbol("Bob", 4, 'a');
}