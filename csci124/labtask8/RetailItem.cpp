#include <iostream>
#include <cstring>
#include "RetailItem.h"
using namespace std;
//Class RetailItem
//Class Constructor
//set all member data when creating new object
RetailItem::RetailItem(int ID, char description[], int unit, double price){
	this->ID = ID;
	strcpy(this->description, description);
	this->unit = unit;
	this->price = price;
}
//Mutator Function
void RetailItem::setID(int ID){
	this->ID = ID;
}
void RetailItem::setDescription(char description[]){
	strcpy(this->description, description);
}
void RetailItem::setUnit(int unit){
	this->unit = unit;
}
void RetailItem::setPrice(double price){
	this->price = price;
}
//Accessor Function
int RetailItem::getID(){
	return ID;
}
int RetailItem::getUnit(){
	return unit;
}
int RetailItem::getPrice(){
	return price;
}
//Display function
//display all data member in the function
void RetailItem::display(){
	cout << "ID: " << ID << endl
		<< "Description: " << description << endl
		<< "Unit: " << unit << endl
		<< "Price: RM" << price << endl;
}
//Operational Function
//take input from user and deduct from unit.
void RetailItem::sold(int unit){
	if(this->unit < unit){
		cout << "Sorry, not enough stock for this purchase." << endl;
	} else {
		this->unit-=unit;
		cout << "Price: RM" << this->price*unit << endl << endl;
	}
}