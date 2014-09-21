//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:4 - 2
//Date		:September 9th, 2014
//This program make use of operator overloading
#include <iostream>
using namespace std;

class Length{
	//insertion and excertion operator overload
	friend ostream& operator<<(ostream&, const Length&);
	friend istream& operator>>(istream&, Length&);
private:
	int meter, centimeter, millimeter;
public:
	bool operator<(Length&);
	Length operator+(Length&);
};
//this operator overload is used to compare the millimeter, centimeter and meter from two object
bool Length::operator<(Length& l){
	//when the meter is less than another object meter, return true,
	//if same, check centimeter, if same again check millimeter.
	//if the first object is not lesser than second object, then return false.
	if (meter < l.meter){
		return true;
	}
	else if(meter == l.meter){
		if(centimeter < l.centimeter){
			return true;
		}
		else if (centimeter == l.centimeter){
			if (millimeter < l.millimeter){
				return true;
			}
		}
	} 
	return false;
}
//This overload operator used to add two object into one object
Length Length::operator+(Length &l){
	//add two object together
 	Length total;
 	total.millimeter = millimeter + l.millimeter;
 	total.centimeter = centimeter + l.centimeter;
 	total.meter = meter + l.meter;
 	
 	//if the value over the value should take, perform needed mathematic to correct the data.
 	total.centimeter += total.millimeter/10;
 	total.millimeter %= 10;
 	total.meter += total.centimeter/100;
 	total.centimeter %= 100;
 	return total;
}
//this operator used to print out all details of an object
ostream& operator<<(ostream& out, const Length &l){
	out << "Meter: " << l.meter << endl
		<< "Centimeter: " << l.centimeter << endl
		<< "millimeter: " << l.millimeter << endl;
	return out;
}
//this operator used to read in all data of an object
istream& operator>>(istream& in, Length &l){
	cout << "Enter Meter: ";
	in >> l.meter;
	cout << "Enter Centimeter: ";
	in >> l.centimeter;
	cout << "Enter millimeter: ";
	in >> l.millimeter;
	return in;
}
int main(){
	//create two object
	Length a,b;
	//read data for first object
	cout << "Enter length for object A," << endl;
	cin >> a;
	//read data for second object
	cout << "Enter length for object B," << endl;
	cin >> b;
	//if first object lesser than second object, first object = first + second object
	if (a < b){
		cout << "Object A shorter than Object B, A+B," << endl;
		a = a + b;
		//PRINT OUT updated object.
		cout << a;
	}
}