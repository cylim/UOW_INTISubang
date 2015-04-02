//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:10 - 1
//Date		:November 17th, 2014

#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;
// function convert char[] to int
int toDigit(char num[]){
	int result = 0;
	// cout << num << endl; // to check whether the code come into here
	for(int x=0; num[x] != '\0'; x++){
		result = (result * 10) + (num[x] - '0');
		// cout << result << endl; // to check whether the code come into here
	}
	return result;
}

int main(){
	char check;
	do{
		char filename[30];
		cout << "File name: ";
		cin >> filename;
		ifstream ins(filename);
		//If filename not found in the system, re-prompt.
		while(!ins){
			ins.close();
			cout << "File not found!" << endl;
			cout << "File name: ";
			cin >> filename;
			ifstream ins(filename);
		}

		stack s;
		char input[5] = {0};
		int operand1, operand2, result;
		cout << "Postfix expression is : ";
		while(!ins.eof()){
			ins >> input;
			cout << input << ' ';
			// Check the input from files whether contain "+-*/", if contain do the math, else convert char[] to int
			if(input[0] == '+'){
				s.pop(operand1);
				s.pop(operand2);
				// cout << endl <<  operand2 << '+' << operand1 << endl; // to check whether the code come into here
				s.push(operand2 + operand1);
			} else if(input[0] == '-'){
				s.pop(operand1);
				s.pop(operand2);
				// cout << endl << operand2 << '-' << operand1 << endl; // to check whether the code come into here
				s.push(operand2 - operand1);
			} else if(input[0] == '*'){
				s.pop(operand1);
				s.pop(operand2);
				// cout << operand2 << '*' << operand1 << endl; // to check whether the code come into here
				s.push(operand2 * operand1);
			} else if(input[0] == '/'){
				s.pop(operand1);
				s.pop(operand2);
				// cout << operand2 << '/' << operand1 << endl; // to check whether the code come into here
				s.push(operand2 / operand1);
			} else {
				s.push(toDigit(input));
			}
		}
		s.pop(result);
		cout << endl << "Result is " << result << endl << endl;

		cout << "Do you wish to continue? (Y/N) : ";
		cin >> check;
		ins.close();
	} while (check == 'Y' || check == 'y');
}