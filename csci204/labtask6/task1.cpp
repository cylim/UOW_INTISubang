//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:6 - 1
//Date		:October 7th, 2014
//This console program is about dynamic classes object allocation, inheritance and polymorphism.
#include <iostream>
using namespace std;

//Class declaration
//Class Ship
class Ship{
protected:
	string name, year;
public:
	Ship(string = "None", string = "None");
	inline void setName(string name){ this->name = name; }
	inline void setYear(string year){ this->year = year; }
	inline string getName(){ return name; }
	inline string getYear(){ return year; }
	virtual void print();
};
//Class Cruiseship, inherit Ship
class CruiseShip: public Ship{
	int passenger;
public:
	CruiseShip(string = "None", string = "None", int = 0);
	inline void setPassenger(int passenger){ this->passenger = passenger; }
	inline int getPassenger(){ return passenger; }
	virtual void print();
};
//Class Cargoship, inherit Ship
class CargoShip: public Ship{
	float capacity;
public:
	CargoShip(string = "None", string = "None", float = 0);
	inline void setCapacity(float capacity){ this->capacity = capacity; }
	inline float getCapacity(){ return capacity; }
	virtual void print();
};
//Class funtion implementation
//Class Ship
//Accessor and Mutator is inside Class Declaration
//Construtor
Ship::Ship(string name, string year){
	this->name = name;
	this->year = year;
}
//display function
void Ship::print(){
	cout << endl << "Ship Information," << endl;
	cout << "Name\t: " << name << endl
		<<"Year\t: " << year << endl;
}
//Class CruiseShip
//Accessor and Mutator is inside Class Declaration
//Construtor
CruiseShip::CruiseShip(string name, string year, int passenger)
:Ship(name, year){
	this->passenger = passenger;
}
//display funtion
void CruiseShip::print(){
	cout << endl << "Cruise ship Information," << endl;
	cout << "Name\t: " << name << endl
		<< "Passenger: " << passenger << " people" << endl; 
}
//Class CargoShip
//Accessor and Mutator is inside Class Declaration
//Construtor
CargoShip::CargoShip(string name, string year, float capacity)
:Ship(name, year){
	this->capacity = capacity;
}
//display funtion
void CargoShip::print(){
	cout << endl << "Cargo ship Information," << endl;
	cout << "Name\t: " << name << endl
		<< "Capacity: " << capacity << " ton" << endl;
}

//driver program to test the output.
int main(){
	Ship *pointerShip[3]; // Create array of pointer pointing to Ship Class
	//for each of the pointer, create new object with different class.
	for(int x=1; x<4; x++){
		if(x%10 == 1){
			pointerShip[x-1] = new Ship("SHIP", "1994");
		} else if(x%10 == 2){
			pointerShip[x-1] = new CruiseShip("Cruise", "1990", 250);
		} else if(x%10 == 3){
			pointerShip[x-1] = new CargoShip("Cargo", "1975", 2500);
		}
	}
	//for each of the pointer, call the print() function to display the details
	for(int x=0; x<3; x++){
		pointerShip[x]->print();
	}
}