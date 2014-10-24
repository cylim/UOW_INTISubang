//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:7
//Date		:October 9th, 2014
//This program try to read data from binary file into Dynamic array of struct 
//then perform sorting for the ease of user searching the customer by ID.

#include "customer.h" // import customer.h header files.

int main(){
	Cust *cust; // create a pointer of Cust struct
	//prompt user to enter the file name for the data
	char file[20];
	cout << "Enter filename: ";
	cin >> file;
	//For testing purpoose,
	// char file[] = "cust.dat";

	int total = checkTotal(file); //check the total record of the file.
	//cout << total << endl; // see the value of total
	//if there is an error in the checkTotal function, terminate the program
	if(total == -1){
		return 0;
	}
	cust = new Cust[total]; //place the cust pointer with Cust struct with the total size

	read(cust, file); //read the data from binary file to cust.
	cout << "The data have successfully read." << endl;
	//For checking purposes,
	// for(int i=0; i< total; i++){
	// 	cout << "ID: " << cust[i].id << endl
	// 		<< "Name: " << cust[i].firstName << " " << cust[i].lastName << endl
	// 		<< "Contact: " << cust[i].contact << endl;
	// }

	sort(cust, total); //sort the array of struct in ascending order 
	//For checking purposes,
	// for(int i=0; i< total; i++){
	// 	cout << "ID: " << cust[i].id << endl
	// 		<< "Name: " << cust[i].firstName << " " << cust[i].lastName << endl
	// 		<< "Contact: " << cust[i].contact << endl;
	// }

	//infinite loop to prompt user input customer ID, and perform the binary search
	int option;
	while(true){
		cout << "Enter customer ID(0 for exit): ";
		cin >> option;
		//when user input 0, the program will terminate.
		if(option == 0){
			cout << "Thank you for using. Program terminated." << endl;
			return 0;
		}
		search(cust, total, option); //call the search function to search the target ID inputted by user.
	} 
}