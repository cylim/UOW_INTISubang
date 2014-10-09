
//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab task	:5 - 1
//Date		:September 30th, 2014
//This program built a better understanding in inheritance.

#include <iostream>
using namespace std;

//class declaration
class Publication{
	string title;
	float price;
public:
	Publication();
	void getData();
	void showData();
};
//class Book inherited  Publication
class Book: public Publication{
	int page;
public:
	Book();
	void getData();
	void showData();
};
//class Disk inherited Publication
class Disk: public Publication{
	char type;
public:
	Disk();
	void getData();
	void showData();
};


//class function implementation
//Publication class function implementation
//Default Constructor
Publication::Publication(){
	title = "";
	price = 0;
}
//getData() function, which require user to input data
void Publication::getData(){
	cout << "Title: ";
	cin >> title;
	cout << "Price: RM";
	cin >> price;
}
//showData() function, which print out the information of the base class
void Publication::showData(){
	cout << "Title\t:" << title << endl;
	cout << "Price\t:RM" << price << endl;
}

//Book class construtor
//Default Constructor
Book::Book(){
	page = 0;
}
//getData() function, which require user to input data
void Book::getData(){
	cout << "Book Information," << endl;
	Publication::getData(); //call base class getData() function
	cout << "Page: ";
	cin >> page;
}
//showData() function, which print out the information of the book class information included base class information
void Book::showData(){
	Publication::showData(); //call base class showData() function, to display the information from base class 
	cout << "Page\t:" << page << endl;
}

//Disk class construtor
//Default Constructor
Disk::Disk(){
	char type;
}
//getData() function, which require user to input data
void Disk::getData(){
	cout << "Disk Information," << endl;
	Publication::getData(); //call base class getData() function
	cout << "Disk type(C = CD/ D =DVD): ";
	cin >> type;
}
//showData() function, which print out the information of the book class information included base class information
void Disk::showData(){
	Publication::showData(); //call base class showData() function, to display the information from base class
	//check the inputed 'type' details and show the full name of the type
	switch(type){
		case 'c':
		case 'C':
			cout << "Type\t:CD" << endl;
			break;
		case 'd':
		case 'D':
			cout << "Type\t:DVD" << endl;
			break;
		default:
			cout << "Type\t:invalid";
	}
}

//driver program to test the object inheritance
int main(){
	Book book; //create Book object
	Disk disk; //create Disk object

	book.getData(); //get the data of Book from user
	disk.getData(); //get the data of Disk from user

	//Show the Book information,
	cout << "Book Information," << endl;
	book.showData();
	//Show the Disk information,
	cout << "Disk Information," << endl;
	disk.showData();
}