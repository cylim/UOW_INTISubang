#include "customer.h"

// check the total record
int checkTotal(char file[]){
	ifstream bin(file, ios::binary | ios::ate); // open the file and start from the end
	//if the file name is not correct, print "file not found" and terminate the program
	if(!bin){
		cout << "The file not found!" << endl;
		return -1;
	}

	int location = bin.tellg(); // save the endpoint to the location
	//if there is size exceed the record, terminate the program
	if(location % sizeof(Cust) > 0){
		cout << "The size is not accurate!" << endl;
		return -1;
	}
	bin.close();
	return location / sizeof(Cust); // send total record back to main
}

// read data to array of struct
void read(Cust *cust, char file[]){
	int x=0;
	ifstream bin(file, ios::binary);
	bin.seekg(0, ios::beg); //start for beginning
	while(bin.good()){
		if(!bin.eof()){
			bin.read((char*)&cust[x], sizeof(Cust)); //read into struct
			x+=1;
			//cout << x << endl; //to see the location of storage
		}
	}
	bin.close();
}

// sort the array of struct
void sort(Cust *cust, int total){
	//set the current location at 1
	for(int c = 1; c < total; c++){
		Cust temp = cust[c]; //assign current location cust to temp
		int i =0;
		for(i = c-1; i>=0; i--){ //set the indicator to location less than current
			if (temp.id < cust[i].id){ //when indicate id is greater than temp id, sort it
				cust[i+1] = cust[i];
			} else {
				break;
			}
		}
		cust[i+1] = temp; //replace the cust with temp
	}
}

// perform search ooperation to find particular ID
void search(Cust *cust, int total, int target){
	int low = 0, high = total -1;
	bool valid = false;
	//when the lower part position is less that the high part position
	while (low <= high){
		int midpoint = (low + high) / 2;
		//when the target id is same as the midpoint id, print customer details
		if (target == cust[midpoint].id){
			valid = true;
			//print out the customer details. 
			cout << "ID: " << cust[midpoint].id << endl
		 		<< "Name: " << cust[midpoint].firstName << " " << cust[midpoint].lastName << endl
	 			<< "Contact: " << cust[midpoint].contact << endl;
		}
		//if the target id is less than the midpoint id, then set high part to midpoint, vice versa
		if (target < cust[midpoint].id) {
			high = midpoint - 1;
		} else {
			low  = midpoint + 1;
		}
	}
	//if the function didn't display any customer details, 
	//then tell the user that the id is not found.
	if(valid == false){
		cout << "Customer ID: " << target << " not found." << endl;
	}
}