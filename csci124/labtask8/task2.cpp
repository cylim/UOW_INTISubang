//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:7 - 2
//Date		:October 9th, 2014
//This program

// The function sold() should reduce the units on hand (if available)
//  depending on the quantity sold and display the total price for 
//  the sold item. If the units on hand are not sufficient, 
//  do not deduct the quantity and display a message indicating 
//  it is out of stock.

// Use appropriate interface and implementation file for your code. 
// Write a driver program that creates a RetailItem object. 
// Then provide three options to the user – 
// change the item’s information, display the item’s information, 
// or sell the item. 
// To sell the item, prompt the user to enter the quantity.


#include <iostream>
#include "RetailItem.h"
using namespace std;

int main(){
	int option;
	char description[50];
	double price;
	RetailItem item;

	//infinite loop to perform menu
	while(true){
		//show the menu
		cout << "\t\tItem Menu"<< endl
			<< "1. Change Item Information " << endl
			<< "2. Display Item Information, " << endl
			<< "3. Sell Item, " << endl
			<< "0. Exit Program" << endl;
		cout << "Option: ";
		cin >> option; //read input from user
		switch(option){
			case 1: //To update Item Information
				//prompt user to input respective information 
				//and use Mutator to change the attribute value in the class object.
				cout << "Enter ID: ";
				cin >> option;
				item.setID(option);
				cout << "Enter Description: ";
				cin.ignore();
				cin.getline(description,50);
				item.setDescription(description);
				cout << "Enter quantity: ";
				cin >> option;
				item.setUnit(option);
				cout << "Enter price: RM";
				cin >> price;
				item.setPrice(price);
				break;
			case 2: //To display Item information
				item.display(); // call class function to display
				break;
			case 3: //To perform purchase function
				cout << "Enter quantity for purchase: ";
				cin >> option;
				item.sold(option);
				break;
			case 0:	//Exit program
				cout << "Thank you for using." << endl;
				return 0;
			default: //reprompt menu
				cout << "Sorry, wrong input. Please try again!" << endl;
		}
	}
}