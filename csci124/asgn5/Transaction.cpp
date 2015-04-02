#include "Transaction.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Constructor, create empty list
Transaction::Transaction(){
	head = NULL;
	totalPrice = 0;
}
//Destructor to delete all dynamic object.
Transaction::~Transaction(){
	ofstream write("log.txt", ios::app);
	nodeptr curr;
	curr = head;
	while (head != NULL){
		head = curr->next;
		write << curr->invoice << '\n';
		for(int x=0; x < curr->totalType; x++){
			write << curr->barcode[x] << '\t'
				<< curr->price[x] << '\t'
				<< curr->quantity[x] << '\t'
				<< curr->description[x] << '\n';
		}
		delete curr;
		curr = head;
	}
	write << "Total Sales in this period: RM" << totalPrice << '\n';
	head = NULL;
	write.close();
}
// check whether head is empty
bool Transaction::isempty(){
	if (head == NULL){
		return true;
	} else {
		return false;
	}
}
// add Transaction at the back of the list
void Transaction::push_back(int invoice){
	nodeptr tmp, curr;
	tmp = new node;
	tmp->invoice = invoice;
	tmp->next = NULL;
	tmp->totalType = 0;
	if(!isempty()){
		curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = tmp;
	} else {
		head = tmp;
	}
}

// add new item into the transaction
void Transaction::add(int invoice, int barcode, char description[], double price, int quantity){
	nodeptr curr;
	curr = head;
	while(curr!=NULL && invoice != curr->invoice){
		curr = curr->next;
	}
	if(curr==NULL){
		cout << "Invoice not found!" << endl << endl;
	} else {
		if(curr->totalType < 10){
			curr->barcode[curr->totalType] = barcode;
			strcpy(curr->description[curr->totalType], description);
			curr->price[curr->totalType] = price;
			curr->quantity[curr->totalType] = quantity;
			totalPrice = totalPrice + (price * quantity);
			curr->totalType+=1;
			cout << "Invoice: " << invoice << " added" << description << " to the list." << endl << endl;
		} else {
			cout << "Cart limit, please perform another transaction." << endl << endl;
		}
		
	}
}

//Remove selected invoice from the list
void Transaction::remove(int invoice){
	nodeptr curr, prev;
	curr = head;
	prev = NULL;
	while(curr!=NULL && invoice != curr->invoice){
		prev = curr;
		curr = curr->next;
	}
	if(curr==NULL){
		cout << "Invoice not found!" << endl << endl;
	} else if(prev) { 
		prev->next = curr->next;
		for(int x=0; x < curr->totalType; x++){
			totalPrice = totalPrice - (curr->price[x] * curr->quantity[x]);
		}
		delete curr;
		cout << "Invoice: " << invoice << " removed from the list." << endl << endl;
	} else {
		head = curr->next;
		for(int x=0; x < curr->totalType; x++){
			totalPrice = totalPrice - (curr->price[x] * curr->quantity[x]);
		}
		delete curr;
		cout << "Invoice: " << invoice << " removed from the list." << endl << endl;
	}
}

//Remove selected invoice from the list
void Transaction::edit(int invoice, int& barcode, int& quantity, int& barcode1, int& quantity1){
	nodeptr curr;
	curr = head;
	while(curr!=NULL && invoice != curr->invoice){
		curr = curr->next;
	}
	if(curr==NULL){
		cout << "Invoice not found!" << endl << endl;
	} else {
		for(int x=0; x < curr->totalType; x++){
			if(barcode == curr->barcode[x]){
				if(barcode == barcode1){
					// remove the old price from total price
					totalPrice = totalPrice - (curr->price[x] * curr->quantity[x]);
					curr->quantity[x] = quantity1;
					if(quantity1 > quantity){
						quantity = quantity1;
					} else {
						quantity1 = quantity;
					}
				} else {
					// Get the quantity back to main, update new barcode and quantity into cart
					quantity = curr->quantity[x];
					curr->quantity[x] = quantity1;
					curr->barcode[x] = barcode1;
				}
				totalPrice = totalPrice + (curr->price[x] * curr->quantity[x]);
			}
		}
	}
}

//Display all Transaction in waiting list
void Transaction::display(){
	nodeptr tmp;
	if (!isempty()){
		int count = 1;
		tmp = head;
		while(tmp){
			cout << "Invoive: " << tmp->invoice << endl;
			cout << "Barcode Price Quantity Description" << endl;
			for(int x=0; x < tmp->totalType; x++){
				cout << tmp->barcode[x] << '\t'
					<< tmp->price[x] << '\t'
					<< tmp->quantity[x] << '\t'
					<< tmp->description[x] << endl;
			}
			cout << endl;
			tmp = tmp->next;
		}
		cout << "Total sales amount: RM" << totalPrice << endl << endl;
	} else {
		cout << "The list is empty." << endl << endl;
	}
}