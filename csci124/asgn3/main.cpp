//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Assignment:3
//Date		:October 2nd, 2014
//This driver program is the main menu of a simulated cyber cafe system
#include "cyber.h"

int main(){
	int total, station[total], size=1;
	User *user = new User[size];
	cout << "Enter Total Lab Number: ";
	cin >> total;
	char *** lab = new char **[total];
	for(int x=0; x<total; x++){
		cout << "Enter total computer in Lab " << x+1 << ": ";
		cin >> station[x];
		lab[x] = new char *[station[x]];
		for(int y=0; y<station[x]; y++){
			//strcpy(lab[x][y], "empty"); //segmentation error
			lab[x][y] = (char*)&"empty"; 
		}
	}

	//Display the computer lab info
	displayLab(lab, total, station);

	double totalCharge = 0;
	int option;
	while(true){
		//Display the menu in proper formatting
		cout << "\t\tCyber Cafe Menu" << endl
			<< "1. Log in" << endl
			<< "2. Log out" << endl
			<< "3. Search user" << endl
			<< "4. List lab" << endl
			<< "5. Display total charges" << endl
			<< "0. Exit" << endl;
		cout << "Option: ";
		cin >> option; // read choice from user
		switch(option){
			case 1: // Log in
				login(lab, total, station, user, size);
				displayLab(lab, total, station); //Display the computer lab info
				break;
			case 2: // Log out
				logout(lab, user, size, totalCharge);
				break;
			case 3: // Search user
				search(user, size);
				break;
			case 4: // List Lab
				list(lab, total, station);
				break;
			case 5: // Display total charges
				displayTotal(totalCharge);
				break;
			case 0: // close the program
				cout << "Program terminated." << endl << endl;
				return 0;
			default: // re-prompt user the menu
				cout << "Wrong input, please try again." << endl << endl;
		}
	}
}