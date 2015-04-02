#include "fstream"
#include "cyber.h"
// This function Log in new user
void login(char ***lab, int total, int station[], User *&user, int &size){
	User *newUser = new User; //create a struct to store the new user temporarily
	bool valid = false;
	//read data from user
	while(valid == false){
		valid = true;
		cout << "Enter 5-digit ID: ";
		cin >> newUser->id;
		//if the id is existed in the user[]
		for(int x=0;x<size;x++){
			if(strcmp(newUser->id, user[x].id) == 0){
				//inform client and reprompt
				cout << "ID existed, please try again." << endl;
				valid = false;
				break;
			}
		}
	}
	valid = false;
	char *empty;
	empty = (char*)&"empty";
	while(valid == false){
		cout << "Enter Lab: ";
		cin >> newUser->lab;
		cout << "Enter Station: ";
		cin >> newUser->station;
		//check for the lab
		for(int x=0; x<total; x++)
			if(newUser->lab == x+1)
				//check for the station
				for(int y=0; y<station[x]; y++)
					if(newUser->station == y+1)
						//when the station is empty, then only assign it to user.
						if(strcmp(lab[x][y], empty) == 0){
							lab[x][y] = newUser->id;
							valid = true;
						} else {
							cout << "The Lab Station Computer is occupied.\n";
						}
	}
	valid = false;
	//ask client to input the login time
	while(valid == false){
		cout << "Login Time(HH MM): ";
		cin >> newUser->inHour >> newUser->inMin;
		valid = true;
		if(newUser->inHour > 23 || newUser->inMin > 59){
			valid = false;
			cout << "The time is in 24hours format. please try again." << endl;
		}
	}
	//when user[] is null, perform if
	//if there is info in id, perform else
	if(strcmp(user[0].id, "") == 0){
		user[0] = *newUser;
	} else {
		size+=1; //increase size
		User *temp = new User[size]; //create temp User struct
		for(int x=0; x<size;x++){
			temp[x] = user[x]; //assign all old user[] data to temp[]
			if(x == size-1){
				temp[size-1] = *newUser; //last location for the new user
			}	
		}
		user = temp; //assign the data to user[]
	}
}
// This function is used to Log out user that is leaving
void logout(char ***lab, User *&user, int &size, double &totalCharge){	
	int target;
	char id[6];
	bool valid = false;
	//read id from user
	while(valid == false){
		cout << "Enter 5-digit ID: ";
		cin >> id;
		for(int x=0;x<size;x++){
			if(strcmp(id, user[x].id) == 0){
				target = x; //when the user is found, set x to target
				valid = true;
				break;
			}
		}
	}
	valid = false;
	//prompt client to input the log out time
	while(valid == false){
		cout << "Logout Time(HH MM): ";
		cin >> user[target].outHour >> user[target].outMin;
		valid = true;
		if(user[target].outHour > 23 || user[target].outMin > 59){
			valid = false;
			cout << "The time is in 24hours format. please try again." << endl;
		}
	}
	//edit the lab table
	strcpy(lab[user[target].lab-1][user[target].station-1], (char*)&"empty");
	//calculate charges in minutes, each minutes = RM0.02
	int login = user[target].inHour *60 + user[target].inMin;
	int logout = user[target].outHour *60 + user[target].outMin;
	// if the logout time is smaller than login time, 
	//logout time have to add 24hours as it had passed a day
	if(logout < login){
		logout = logout + (24 * 60);
	}
	user[target].price = (logout - login) * 0.02;
	//print the payment details
	cout << "Payment Amount: RM" << user[target].price << endl << endl;
	//increase total charge
	totalCharge += user[target].price;
	//write the logout info to log file.
	ofstream logfile("log.txt", ios::app);
	logfile << "\n" << user[target].id << ":"
			<< user[target].lab << ":"
			<< user[target].station << ":"
			<< user[target].inHour << "." << user[target].inMin << ":"
			<< user[target].outHour << "." << user[target].outMin << ":"
			<< user[target].price;
	logfile.close();

	//set the user[] smaller
	size-=1;
	// create a temp User struct to store the data without logout user
	User *temp = new User[size];
	for(int x=0; x<size;x++){
		temp[x] = user[x];
		if(x >= target){
			temp[x] = user[x+1];
		}
	}
	user = temp; // user User struct point to temp User struct.
}
// This function is used to Search user by the user id
void search(User user[], int &size){
	char id[6];
	bool valid = false;
	//read data from user
	cout << "Enter 5-digit ID: ";
	cin >> id;
	//search from the user[], if the id matched, print out the user current session info
	for(int x=0;x<size;x++){
		if(strcmp(id, user[x].id) == 0){
			cout << "User ID: " << user[x].id << endl
				<< "Lab:\t" << user[x].lab << endl
				<< "Station: " << user[x].station << endl
				<< "Login Time: " << user[x].inHour << ":" << user[x].inMin << endl << endl;
			valid = true;
			break;	
		}
	}
	//if the id is not found in the user[], tell client.
	if(valid == false){
		cout << "User ID: " << id << " not found!" << endl << endl;
	}
}

//This function allow the user to choose particular lab for display purposes.
void list(char ***lab, int total, int station[]){
	int num;
	//prompt user to enter lab number
	cout << "Enter Lab number: ";
	cin >> num;
	//if the lab number is not in range, reprompt.
	while(num > total || num <= 0){
		cout << "Lab number not found!" << endl;
		cout << "There is " << total << " lab in this cyber cafe." << endl;
		cout << "Enter Lab number: ";
		cin >> num;
	}
	//formating - Lab: Stations
	cout << "Lab Number\tComputer Stations" << endl
		<<	"----------\t--------------------------------------------" << endl;
	cout << '\t' << num << '\t'; // display lab
	for(int y=0; y<station[num-1]; y++){
		cout << y+1 << ": " << lab[num-1][y] << '\t'; //display station
	}
	cout << endl <<	"----------\t--------------------------------------------" << endl;
}

//This function is used to display total charges of the cyber cafe at particular session
void displayTotal(double totalCharge){
	cout << "Total charges of this session is RM" << totalCharge << endl << endl;
}

//This function is used to display the full details of the cyber cafe
void displayLab(char ***lab, int total, int station[]){
	//formating - Lab: Stations
	cout << "Lab Number\tComputer Stations" << endl
		<<	"----------\t--------------------------------------------" << endl;
	for(int x=0; x<total; x++){
		cout << '\t' << x+1 << '\t'; // display lab
		for(int y=0; y<station[x]; y++){
			cout << y+1 << ": " << lab[x][y] << '\t'; //display station
		}
		cout << endl;
	}
	cout <<	"----------\t--------------------------------------------" << endl;
}