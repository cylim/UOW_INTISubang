//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
	string password; //store password
	char pass[100]; //for verification purpose
	int lower=0, upper=0, digit=0;// counter
	//prompt user to input password
	cout << "Enter password: ";
	cin >> password;
	//copy password as constant char to pass
	strcpy(pass, password.c_str());

	//search the password in pass
	for(int i = 0; i< password.length(); i++){
		//check uppercase
		if(pass[i] <= 'Z' && pass[i] >= 'A')
			upper++;
		//check lowercase
		if(pass[i] <= 'z' && pass[i] >= 'a')
			lower++;
		//check digit
		if(pass[i] <= '9' && pass[i] >= '0')
			digit++;
	}
	//verification process
	//check password length
	if(password.length() < 6){
		cout << "Your password must have at least SIX characters." << endl;
	}
	//validate counter upper for uppercase checking 
	else if(upper < 1){
		cout << "Your password must contain at least ONE UPPERCASE letter." << endl;
	}
	//validate counter lower for lowercase checking
	else if(lower < 1){
		cout << "Your password must contain at least ONE LOWERCASE letter." << endl;
	}
	//validate counter digit for digit checking
	else if(digit < 1){
		 cout << "Your password must contain at least ONE DIGIT." << endl;
	}
	//if the password pass all above checking
	else	
		cout << "Password Accepted." << endl;
}