//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:6 - 2
//Date		:October 7th, 2014
//This console program is about abstract class and how to make use of it
#include <iostream>
#include <cctype>
using namespace std;

//Class declaration of A,B,C
class A{
	string AFood;
public:
	inline void setAFood(string food){ AFood = food; }
	virtual void output() = 0;
};
class B: public A{
	string BFood;
public:
	B(string= "none", string= "none");
	void output();
};
class C: public B{
	string CFood;
public:
	C(string= "none", string= "none", string = "none");
	void output();
};
//class implementation
//class A, display function
void A::output(){
	cout << "A is for " << AFood << endl;
}
//class B
//Constructor
B::B(string a, string b){
	setAFood(a);
	BFood = b;
}
//display function
void B::output(){
	A::output();
	cout << "B is for " << BFood << endl; 
}
//Class C
//Constructor
C::C(string a, string b, string c): B(a,b){
	CFood = c;
}
//display function
void C::output(){
	B::output();
	cout << "C is for " << CFood << endl;
}

//Driver function to test the functionality of the classes
int main(){
	// create nessesary variable for storing and checking purposes
	string name, a, b , c;
	bool check = false;
	a = "none", b = "none"; // set a and b to "none"
	cout << "Enter fruit name start with 'A' and 'B'," << endl;
	while(check == false){
		cout << "Enter fruit name: ";
		cin >> name; //ask user to input a name
		name[0] = toupper(name[0]); // change the first char to CAPITAL
		if(name[0] == 'A'){ //check if it start with 'A', if so assign to a
			a = name;
		} else if(name[0] == 'B'){ //check if it start with 'B', if so assign to b
			b = name;
		} else { //If it is neither start with 'A' or 'B', tell user to re-input
			cout << "Fruit name isn't start with 'A' or 'B'." << endl;
		}
		//when both a and b is not equal to "none", exit the loop
		if(a != "none" && b != "none"){
			check = true;
		}
	} 
	B two(a,b); //create class B object with that two value

	check = false; //set check to false again
	a = "none", b = "none", c = "none"; // make a,b and c "none"
	cout << endl << endl << "Enter fruit name start with 'A', 'B' and 'C'," << endl;
	while(check == false){
		cout << "Enter fruit name: ";
		cin >> name;
		name[0] = toupper(name[0]); //CAPITAL first char
		//check if the input start with 'A', 'B' and 'C', assign to respective variable.
		//else inform user that the input is incorrect, and ask user to re-input.
		if(name[0] == 'A'){
			a = name;
		} else if(name[0] == 'B'){
			b = name;
		} else if(name[0] == 'C'){
			c = name;
		} else {
			cout << "Fruit name isn't start with 'A', 'B' or 'C'." << endl;
		}
		//If all a,b and c assigned with user input, exit the loop
		if(a != "none" && b != "none" && c != "none"){
			check = true;
		}
	} 
	C three(a,b,c); //create C object with all the data

	cout << "Output of A and B," << endl;
	two.output(); //output B
	cout << "Output of A, B and C," << endl;
	three.output(); //output C
}