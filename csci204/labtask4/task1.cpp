//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:4 - 1
//Date		:September 9th, 2014
//This program use friend function to show the details of two class.

#include <iostream>
using namespace std;

class HotelRoom; // class declaration
class Guest{
	// to display object from two different class
	friend void display(Guest, HotelRoom);
private:
	string name;
	string ID;
public:
	Guest(string, string);
	//Accessor and Mutator using inline function
	inline void setName(string name){ this->name = name;}
	inline void setID(string ID){ this->ID = ID; }
	inline string getName(){ return name; }
	inline string getID(){ return ID;}
};
//construtor for Guest info
Guest::Guest(string name, string ID){
	setName(name);
	setID(ID);
}

class HotelRoom{
	// to display object from two different class
	friend void display(Guest, HotelRoom);
private:
	string name;
	string room;
	float rate;
public:
	HotelRoom(string, string, float);
	//Accessor and Mutator using inline function
	inline void setName(string name){ this->name = name; }
	inline void setRoom(string room){ this->room = room; }
	inline void setRate(float rate){ this->rate = rate; }
	inline string getName(){ return name; }
	inline string getRoom(){ return room; }
	inline float getRate(){ return rate; }
};
//constructor for hotel room
HotelRoom::HotelRoom(string name, string room, float rate){
	setName(name);
	setRoom(room);
	setRate(rate);
}
//friend function to display both object details
void display(Guest g, HotelRoom h){
	cout << "Guest Details," << endl
		<< "Name\t:" << g.getName() << endl
		<< "ID\t:" << g.getID() << endl;
	cout << "Room Details," << endl
		<< "Name\t:" << h.getName() << endl
		<< "Room\t:" << h.getRoom() << endl
		<< "Rate\t:RM" << h.getRate() << endl;
}

int main(){
	//create Guest object
	Guest g("Byron Lim", "J14016414");
	//create HotelRoom object
	HotelRoom h("ABC Hotel", "F402", 98.8);
	//display both object
	display(g,h);
}