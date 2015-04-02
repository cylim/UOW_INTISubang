//Author	:Lim Chee Yeong
//Student ID:J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Assignment:5
//Date		:November 21st, 2014

#include <iostream>
#include "Hardware.h"
#include "Transaction.h"
using namespace std;

int main(){
	//For Hardware variable declaration
	Hardware list;
	int barcode, quantity;
	char description[30];
	double price;

	//For Transaction class declaration
	Transaction cart;
	int invoice, invoices = 100, barcode1, quantity1;
	char cont;

	// The hardware.txt file order is:
	// barcode price quantity description //
	ifstream read("hardware.txt");
	if(!read){
		cout << "hardware.txt file is missing. Program terminated." << endl << endl;
		return 0;
	}
	while(read.good()){
		//read everything to program
		read >> barcode;
		read >> price;
		read >> quantity;
		read.getline(description, 30);
		if(!read.eof()){
			// save it to hardware binary search tree
			list.insert(barcode, description, price, quantity);
		}
	}
	read.close();

	int option;
	while(true){
		//show the menu title
		cout << "\t+++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\t+\tInventory Management\t+" << endl
			<< "\t+++++++++++++++++++++++++++++++++++++++++" << endl;
		//show the menu selection
		cout << "1. Update Hardware details" << endl
			<< "2. Add new Hardware" << endl
			<< "3. Display Hardware" << endl
			<< "4. Sell Hardware" << endl
			<< "5. Remove Sales Transaction" << endl
			<< "6. Edit Sales Transaction" << endl
			<< "7. Display Total Sales" << endl
			<< "0. Exit" << endl;
		cout << "Option: ";
		cin >> option;

		switch(option){
			case 1: // Edit Hardware price or quantity
				cout << "Enter Barcode: ";
				cin >> barcode;
				cout << "Quantity: ";
				cin >> quantity;
				cout << "Price: RM";
				cin >> price;
				list.update(barcode, price, quantity);
				break;
			case 2: // Add new Hardware
				cout << "Barcode: ";
				cin >> barcode;
				if(list.locate(barcode, description, price, quantity) == false){
					cin.ignore();
					cin.clear();
					cout << "Description: ";
					cin.getline(description, 30);
					cout << "Price: RM";
					cin >> price;
					cout << "Quantity: ";
					cin >> quantity;
					list.insert(barcode, description, price, quantity);
				} else {
					cout << "Sorry, the item is already available in the list." << endl;
				}
				break;
			case 3: // Display one or more Hardware
				cout << "1: Display All\n"
					<< "2: Display Selected Item" << endl;
				cout << "Option: ";
				cin >> option;
				if(option == 1){
					cout << "Barcode Price Quantity Description" << endl;
					list.inorder_traversal();
				} else if(option == 2){
					cout << "Enter Barcode: ";
					cin >> barcode;
					if(list.locate(barcode, description, price, quantity) == true){
						cout << "Barcode: " << barcode << endl
							<< "Description: " << description << endl
							<< "Price: RM" << price << endl
							<< "Quantity: " << quantity << endl << endl;
					} else {
						cout << "Item not found!" << endl << endl;
					}
				} else {
					cout << "Wrong input." << endl << endl;
				}
				break;
			case 4: // Perform sales, allow purchase several items
				cart.push_back(invoices);
				do{
					cout << "Barcode: ";
					cin >> barcode1;
					if(list.locate(barcode1, description, price, quantity) == true){
						cout << "Enter Quantity: ";
						cin >> quantity1;
						if(quantity1 <= quantity){
							quantity -= quantity1;
							list.update(barcode1, price, quantity);
							cart.add(invoices, barcode1, description, price, quantity1);
						} else {
							cout << "Item doesn't have enough quantity." << endl << endl;
						}
					} else {
						cout << "Item not found!" << endl << endl;
					}
					cout << "Continue to add items into cart(Y/N): ";
					cin >> cont;
				}while(cont == 'Y' || cont == 'y');
				invoices+=1;
				break;
			case 5: // Remove sales based on invoice
				cout << "Invoice Number: ";
				cin >> invoice;
				cart.remove(invoice);
				break; 
			case 6: // Edit sales item barcode and/or quantity
				cout << "Invoice Number: ";
				cin >> invoice;
				cout << "Barcode: ";
				cin >> barcode;
				cout << "New Barcode: ";
				cin >> barcode1;
				cout << "New Quantity: ";
				cin >> quantity1;
				cart.edit(invoice, barcode, quantity, barcode1, quantity1);
				list.updateQuantity(barcode,quantity);
				list.updateQuantity(barcode1,quantity1);
				break;
			case 7: // display all sales transaction and total amount
				cart.display();
				break;
			case 0:
				cout << "Thanks for using ^.^" << endl;
				return 0;
			default:
				cout << "Wrong input, please try again."<< endl << endl;
		}
	}
}