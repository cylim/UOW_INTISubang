//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab task	:5 - 3
//Date		:September 30th, 2014
//This program is a special inheritance that a sub-class inherit two base class
#include <iostream>
using namespace std;

//class declaration
class House{ //base class
	string address;
	float size;
public:
	House(string, float);
	void display();
};
class Investment{ //base class 
	float initial, current, profit, profitPercent;
public:
	Investment(float, float);
	void display();
};
//class HouseInvest inherited House and Investment base class
class HouseInvest: public House, public Investment{
public:
	HouseInvest(string, float, float, float);
	void display();
};

//class function implementation
//House class function implementation
//non-Default Constructor
House::House(string address, float size){
	this->address = address;
	this->size = size;
}
//This function display the address and size 
void House::display(){
	cout << "Address: " << address << endl
		<< "Size   : " << size << " square meter" << endl;
}

//Investment class construtor
//non-Default Constructor
Investment::Investment(float initial, float current){
	this->initial = initial;
	this->current = current;
	profit = current - initial;
	profitPercent = (profit / initial) *100;
}
//This function is used to display the data from Investment class
void Investment::display(){
	cout << "Initial: RM" << initial << endl
		<< "Current: RM" << current << endl
		<< "Profit : RM" << profit << endl
		<< "Percent: " << profitPercent << "\%" << endl;
}

//Investment class construtor
//non-Default Constructor, which use House and Investment to initialize data
HouseInvest::HouseInvest(string address, float size, float initial, float current)
:House(address, size), Investment(initial, current){ }
//This function display all data from House class 
void HouseInvest::display(){
	cout << "Invested house details," << endl;
	House::display();
	Investment::display();
}

//driver function to create HouseInvest object
int main(){
	HouseInvest houseA("Koi Kinrara", 1024, 400000, 450000);
	houseA.display();
}