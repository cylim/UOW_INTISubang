//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//Date		:September 11th, 2014
//This is the class function files for driver program, which handle all sort of function needed.
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "Supermarket.h"
using namespace std;

//Item class implementation:
//Constructor for Item class
Item::Item(){
	name = " ";
	itemCount = 0;
	price = 0;
	weight = 0;
	description = " ";
}
Item::Item(string name, int itemCount, float price, int weight, string description){
	setName(name);
	setItemCount(itemCount);
	setPrice(price);
	setWeight(weight);
	setDescription(description);
}

float Item::totalValue(){
	return itemCount*price;
}
void Item::display(){
	cout << name<< '\t' << itemCount<< "\t\t" << price<< "\t\t" << weight<< "\t\t" << description << endl;
}

//Supermarket class implementation:
//Constructor for Supermarket class
//This constructor read in Stock.txt and save the data into Supermarket object.
Supermarket::Supermarket(){
	total = 0;
	ifstream read("Stock.txt");
	if(!read){
		cout << "Problem of reading Stock.txt file, please ensure the file is in same directory." << endl;
		terminate(); //terminated the program
	}
	if(read.good()){
		getline(read, name, ':');
		read >> total;
		read.get(); // use of get() to take the extra ':' symbol
		read >> cash;
		read.get();
		//For testing purpose, see the output of the Supermarket details.
		//cout << name << '\t' << total << '\t' << cash << endl;
		for(int x = 0; x < total; x++){
			string sName, description;
			int quantity, weight;
			float price;
			read.get(); //use of get() to take extran '\n'
			getline(read, sName, ':');
			read >> quantity;
			read.get();
			read >> price;
			read.get();
			read >> weight;
			read.get();
			getline(read, description, ':');
			setItem(x, sName, quantity, price, weight, description);
		}
	}
	read.close();
}
//this function is used to perform purchase action for specific customer
void Supermarket::shop(Customer& cust){
	cout << "Name: " << cust.getName() << '\t' << "Cash: RM" << cust.getCash() << endl; //show customer details
	string iName;
	int qty, totalPurchasedItem=0;
	bool check = true;
	while(check == true){
		cout << endl << "\"list\" to display purchased list," << endl
			<<	"\"checkout\" to check out," << endl
			<< "Enter Item name for adding new purchase item," <<endl
			<< "Input: ";
		//take user input and determine it action
		cin >> iName;
		if(iName == "list"){
			cust.displayPurchasedList(totalPurchasedItem); //display whole list of purchased item
		} 
		else if(iName == "checkout"){
			cust.displayPrice(totalPurchasedItem); // display the total price
			check = false; // when check =false, mean the function finish it mission
		} else {
			iName[0] = toupper(iName[0]); //change the first character to uppercase, due to all item in stock.txt first character is uppercase
			cout << "Enter Quantity: ";
			cin >> qty;
		
			for(int i=0; i< total; i++){
				//perform only when stock name is same as iName
				if(iName.compare(stock[i].getName()) == 0){
					//if customer don't have enough money, prompt not enough money
					if(cust.getCash() < stock[i].getPrice()*qty){
						cout << "Customer doesn't have enough cash!" << endl;
						break;
					}
					//if item in stock is lesser than customer needed, prompt not enough stock 
					else if(stock[i].getItemCount() < qty){
						cout << "Stock is not enough!" << endl;
						break;
					} else {
						cust.setPurchasedItem(totalPurchasedItem, stock[i].getName(), qty, stock[i].getPrice()); //set details for purchaseItem
						setCash(cash + stock[i].getPrice() * qty); //add cash to supermarket
						cust.setCash(cust.getCash() - stock[i].getPrice() * qty); //deduct cash from customer
						stock[i].setItemCount(stock[i].getItemCount() - qty); // deducct quantity from customer
						totalPurchasedItem +=1; //goto the element of array.
						break;
					}
				}
			}
		}
	}
}
//show all item detail line by line
void Supermarket::reportStock(){
	cout << "Name\tQuantity\tPrice(RM)\tWeight(g)\tDescription" << endl;
	for(int x=0; x<total; x++){
		stock[x].display();
	}
	cout << endl << endl;
}
//show cash and stock value of the supermarket
void Supermarket::reportFinancial(){
	float stockValue=0;
	for(int x=0; x<total; x++){
		stockValue = stockValue + stock[x].totalValue();
	}
	cout << "Supermarket:\t" << getName() << endl;
	cout << "Cash Value:\tRM" << getCash() << endl;
	cout << "Stock Value:\tRM" << stockValue << endl;
	cout << endl << endl;
}
//Destructor for Supermarket class
Supermarket::~Supermarket(){ 
	ofstream out("Stock.txt");
	out << getName() << ':'
		<< total << ':' 
		<< getCash() << ":\n";
	for(int i=0; i<total; i++){
		out << stock[i].getName() << ':'
			<< stock[i].getItemCount() << ':'
			<< stock[i].getPrice() << ':'
			<< stock[i].getWeight() << ':'
			<< stock[i].getDescription() << ":\n";
	}
	out.close();
}

//Customer Class implementation:
//Constructor for Customer class
Customer::Customer(){
	name = " ";
	cash = 0;
}
Customer::Customer(string name, float cash){
	setName(name);
	setCash(cash);
}

//To show the details of purchased item list
void Customer::displayPurchasedList(int totalPurchasedItem){
	cout << "Name" << '\t' << "Qty" << '\t' << "Unit(RM)" << '\t' << "Total(RM)" << endl;
	for(int i=0; i<totalPurchasedItem; i++){
		cout << purchasedItem[i].getName() << '\t'
			<< purchasedItem[i].getItemCount() << '\t'
			<< purchasedItem[i].getPrice() << "\t\t"
			<< purchasedItem[i].getItemCount() * purchasedItem[i].getPrice() << endl;	
	}
}
//To show the total price of certain purchase
void Customer::displayPrice(int totalPurchasedItem){
	float total =0;
	for(int i=0; i<totalPurchasedItem; i++){
		total += purchasedItem[i].getItemCount() * purchasedItem[i].getPrice();
	}
	cout << "Total Cost: RM" << total << endl;
}
//Destructor for customer class
Customer::~Customer(){ 
	cout << name << " customer out of scope" << endl;
}