//This is a program required user to key in rental car information
//based on the car type and engine cc, find out the rental fees
//and then print out full information
//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
using namespace std;

class RentalCar{
	string regNum;
	string model;
	string type;
	string engineNum;
	string chasisNum;
	float cc;
	int rentalPrice;
	const static int rental[3][3];
public:
	void setAll(string, string, int, string, string, float);
	void setType(int);
	void displayRates();
	void computeRental(int, float);
	void display();
};
//implementation class function
const int RentalCar::rental[3][3] = {{100,200,300},{0,300,500},{0,400,600}};

void RentalCar::displayRates(){
	//print out the car rental information with proper formatting.
	string type[3] = {"Medan","MPV","SUV"};
	cout << endl << "\t\t== CAR RENTAL INFORMATION ==" << endl << endl;
	cout << "Car Type" << "\tcc <= 1.5" << "\tcc <= 2.0" << "\tcc > 2.0" << endl;
	for(int x=0; x<3; x++){
		cout << type[x] << "\t\t";
		for(int y=0; y<3;y++){
			if(rental[x][y] == 0){
				cout << "N/A\t\t";
			}else{
		 		cout << rental[x][y] << "\t\t";
		 	}
		}
		cout << endl;
	}
}

void RentalCar::setAll(string regNum, string model, int type, string engineNum, string chasisNum, float cc){
	this->regNum = regNum;
	this->model = model;
	//based on value user input, set the car type to type.
	setType(type);
	this->engineNum = engineNum;
	this->chasisNum = chasisNum;
	this->cc = cc;
	//to find out the rental price for specific car type and cc
	computeRental(type, cc);
}

void RentalCar::setType(int type){
	//allocate the car type name based on user input.
	switch(type){
		case 0: 
			this->type = "Medan";
			break;
		case 1: 
			this->type = "MPV";
			break;
		case 2: 
			this->type = "SUV";
			break;
		default:
			cout << "Car type not found!"<< endl;

	}
}

void RentalCar::computeRental(int type, float cc){
	int num;
	//set the cc to array number according to the displayRates()
	//in order to locate the rental price of the car type and engine cc
	if(cc <=1.5){
		num = 0;
	}else if(cc <= 2.0){
		num = 1;
	}else{
		num = 2;
	}
		rentalPrice = rental[type][num];
}

void RentalCar::display(){
	cout << endl << "\t  == Car Rental Information ==" << endl << endl;
	if(rentalPrice == 0){
		cout << "Car type " << type << " doesn't have " << cc << "cc engine capacity." << endl;
	}else{
		cout << "Registration Number\t:" << regNum << endl
			<< "Vehicle Model\t\t:" << model << endl
			<< "Vehicle Type\t\t:" << type << endl
			<< "Engine Number\t\t:" << engineNum << endl
			<< "Chasis Number\t\t:" << chasisNum << endl
			<< "Engine Capacity(cc)\t:" << cc << endl
			<< "Rental Price\t\t:RM" << rentalPrice << endl;
	}
	cout <<endl << "\t\t== End of data =="<< endl << endl;
}

//driver program, to test the output
int main(){
	string regNum, model, engineNum, chasisNum;
	int type;
	float cc;
	RentalCar car;
	car.displayRates();
	for(int i=0; i<3; i++){
		cout << "Please enter Vehicle Registration Number(e.g. ABC1234): ";
		cin >> regNum;
		cout << "Please enter Vehicle Model(e.g. BMW): ";
		cin >> model;
		cout << "Please enter Vehicle type(0: Medan, 1: MPV, 2: SUV): ";
		cin >> type;
		//the input should accept 0,1 or 2 only,
		//other than that is invalid for the class function to set car type
		if(type < 0 || type > 2){
			cout << "Car type not found" << endl ;
			return 0;
		}
		cout << "Please enter Vehicle Engine Number(e.g. 1S-321-BA): ";
		cin >> engineNum;
		cout << "Please enter Vehicle Chasis Number(e.g. SAAMN12A0L0012355): ";
		cin >> chasisNum;
		cout << "Please enter Vehicle Engine Capacity(cc): ";
		cin >> cc;
		car.setAll(regNum, model, type, engineNum, chasisNum, cc);
		car.display();
	}
}