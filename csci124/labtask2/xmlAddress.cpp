//This function is used to read in xml files and search the data from struct.
//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
#include <fstream>
#include <cstring>
#include "xmlAddress.h"
using namespace std;

int readAddress(list contact[]){
	int i=0; //for total number of element in Array
	char file[50];
	//For testing purpose, use file below,
	//char file[] = "address.xml";
	cout << "Please enter filename: ";
	cin >>file;
	ifstream read(file);

	//check file, if the file is not available
	//or didn't contain ".xml", terminate the program
	if(!read){
		cout << "File not found!" << endl;
		// return value -1 to main(), so that main can return to 0
		return -1;
	}else if(strstr(file, ".xml") == NULL){
		cout << "File is not in XML format" << endl;
		return -1;
	}

	cout << "Reading data of the xml file." << endl;
	char check[50]; //to check and assign value into correct element of array
	char * loc; //to find the location of '<'
	while(!read.eof()){
		//read in data to check[] until it reach <contact>
		for(int x=0; x<4; x++){
			read.getline(check, 50);
			if(strcmp(check, "\t<contact>") == 0){
				//assign the proper data to check, eliminate <tag>
				read.ignore(12, '>').getline(check, 50);
				//check the location for </tag>
				loc = strchr(check, '<');
				//pass the data to correct element of array of struct without </tag> 
				for (int x=0; x < loc-check; x++){
					contact[i].name[x] = check[x];
				}
				read.ignore(12, '>').getline(check, 50);
				loc = strchr(check, '<');
				for (int x=0; x < loc-check; x++){
					contact[i].street[x] = check[x];
				}
				read.ignore(12, '>').getline(check, 50);
				loc = strchr(check, '<');
				for (int x=0; x < loc-check; x++){
					contact[i].city[x] = check[x];
				}
				read.ignore(12, '>').getline(check, 50);
				loc = strchr(check, '<');
				for (int x=0; x < loc-check; x++){
					contact[i].state[x] = check[x];
				}
				read.ignore(12, '>').getline(check, 50);
				loc = strchr(check, '<');
				for (int x=0; x < loc-check; x++){
					contact[i].postcode[x] = check[x];
				}
				i++;
				break;
			}
		}
	}
	read.close();
	//For checking the xml file output in terminal
	//for(int x=0; x<i; x++){
	// 	cout << endl << "===" << x <<"===" << endl;
	// 	cout << contact[x].name <<endl;
	// 	cout << contact[x].street<<endl;
	// 	cout << contact[x].city<<endl;
	// 	cout << contact[x].state<<endl;
	// 	cout << contact[x].postcode<<endl;
	// }
	//For checking the output in files
	//to check whether got insufficient lines or other errors
	//ofstream outFile;
	//outFile.open("abc");
	//for(int x=0; x<i; x++){
	//	outFile << contact[x].name << "\n" << contact[x].street
	//				<< "\n" << contact[x].city << "\n" << contact[x].state
	//				<< "\n" << contact[x].postcode;
		//prevent extra line of data
	//	if(x != i-1){
	//		outFile << "\n"; 
	//	}
	//}
	//outFile.close();
	return i; //return the total number of row of the array to main()
}

void searchPostcode(int num, list contact[]){
	char postcode1[10], postcode2[10];
	cout << "Please enter the range of postcode," << endl;
	cout << "From Postcode: ";
	cin >> postcode1;
	cout << "To postcode: ";
	cin >> postcode2;

	cout << "\t== Search Results ==\n" << endl;
	cout << "Postcode in range of " << postcode1 << " to " << postcode2 << ":" << endl;
	//check whether there is postcode inside contact is in the middle of postcode1 and postcode2
	//if available, print out the details of contact[]
	for(int i=0; i<num; i++){
		if (strcmp(contact[i].postcode, postcode1) >= 0 && strcmp(contact[i].postcode, postcode2) <= 0){
			cout << "\nName\t:" << contact[i].name
				<< "\nStreet\t:" << contact[i].street
				<< "\nCity\t:" << contact[i].city
				<< "\nState\t:" << contact[i].state
				<< "\nPostcode:" << contact[i].postcode << endl;
		} 
	}
	cout << "\n\t== End of Results =="<< endl;
}

void searchCity(int num, list contact[]){
	char city[20];
	cout << "Please enter the City name: ";
	cin.ignore();
	cin.getline(city, 20);

	cout << "\t== Search Results ==" << endl;
	//check whether the city name is same as contact[].city
	//if same, print out the info of contact[]
	for(int i=0; i<num; i++){
		if(strcmp(contact[i].city, city) == 0){
			cout << "\nName\t:" << contact[i].name
				<< "\nStreet\t:" << contact[i].street
				<< "\nCity\t:" << contact[i].city
				<< "\nState\t:" << contact[i].state
				<< "\nPostcode:" << contact[i].postcode << endl;
		}
	}
	cout << "\n\t== End of Results =="<< endl;
}