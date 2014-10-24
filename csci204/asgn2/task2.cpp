//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:2 - 2
//Date		:October 2nd, 2014
//This driver console program to add crate into Container in Container.cpp
#include "Container.h"

int main(){
	int input, total =6;
	ShippingContainer * ship[total];// Create array of pointer pointing to ShippingContainer Class
	cout << "Number of Manual Shipping Container: ";
	cin >> input;
	//for each of the pointer, create new object with different class.
	for(int x=0; x<total; x++){
		if(x<input){
			ship[x] = new ManualShippingContainer;
		} else {
			ship[x] = new RFIDShippingContainer;
		}
	}

	int option, count =0;
	while(true){
		//Menu for the program
		cout << "\t\tShipping Container Menu" << endl
			<< "1. Set Container ID" << endl
			<< "2. Record items" << endl
			<< "3. Display items" << endl
			<< "0. Exit" << endl;
		cout << "Options: ";
		cin >> option;
		if(option == 1){ // To change ship container ID
			int num;
			bool valid = true;
			//prompt user to input container position
			cout << "Enter Container position: ";
			cin >> num;
			//if user-input greater than total Container, re-prompt user to input
			while(num >= total){
				cout << "Position of Container must be less than " << total << endl;
				cout << "Position: ";
				cin >> num;
			}
			//ask user to input new container ID
			cout << "Enter Container ID: ";
			cin >> option;
			//if container ID already exist, inform user.
			for(int x=0; x < total; x++){
				if(ship[x]->getID() == option){
					cout << "Sorry, Container ID existed!" << endl << endl;
					valid = false;
					break;
				}
			}
			//if not exist, use setID() function to change the ID.
			if(valid == true){
				ship[num]->setID(option);
			}
			count = 0; //reset the terminate count // To change the container ID
		} else if(option == 2){ // To add record into container
			int num;
			bool valid = false;
			//prompt user to input container ID
			cout << "Enter Container ID: ";
			cin >> option;
			cin.ignore();
			//check the id, if found set num to id
			for(int x=0; x < total; x++){
				if(ship[x]->getID() == option){
					num = x;
					valid = true;
					break;
				}
			}
			//if not found, print out ID not found
			//else use compare the ID with input 
			//to determine it is Manual or RFID container
			if(valid == false){
				cout << "Container ID not found!" << endl << endl;
			} else {
				string manifest;
				if(num < input){
					//if it is Manual Container, use setManifest
					cout << "Enter item: ";
					getline(cin, manifest);
					dynamic_cast<ManualShippingContainer*>(ship[num])->setManifest(manifest);
				} else {
					//if it is RFID Container, use add until user input 'exit'
					while(manifest != "exit"){
						cout << "Enter item(enter 'exit' to stop): ";
						getline(cin, manifest);
						if(manifest != "exit"){
							dynamic_cast<RFIDShippingContainer*>(ship[num])->add(manifest);
						}					
					}
				}
			}
			count = 0; //reset the terminate count
		} else if(option == 3){ // To display record from container
			bool valid = false;
			//prompt user to enter the container ID
			cout << "Enter Container ID: ";
			cin >> option;
			//check for the ID, if ID exist print out.
			for(int x=0; x < total; x++){
				if(ship[x]->getID() == option){
					cout << ship[x]->getManifest() << endl << endl;
					valid = true;
					break;
				}
			}
			//else return ID not found.
			if(valid == false){
				cout << "Container ID not found!" << endl;
			}
			count = 0; //reset the terminate count
		} else if(option == 0){ //terminate the program
			cout << "Program terminated." << endl;
			return 0;
		} else { //prompt user to retry, for certain amount of time then terminate the program.
			if(count < 3){
				cout << "Wrong input, please try again!" << endl << endl;
			} else {
				cout << "Program terminated." << endl;
				return 0;
			}
			count += 1;
		}
	}
}