//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:7 - 1
//Date		:October 9th, 2014
//This program is to test student basic understanding in Object-Oriented Porgraming

#include <iostream>
#include "Circle.h"
using namespace std;

int main(){
	Circle * cir = new Circle[2]; //create two Circle object
	double radius;
	for(int x = 0; x < 2; x++){
		cout << "Enter radius for circle " << x+1 << ": ";
		cin >> radius; // prompt user to input the radius
		cir[x].setRadius(radius); //set it to the circle
		//print out all information of the Circle
		cout << "Circle " << x+1 << ",\n" 
			<< "Area: " << cir[x].calArea() << endl
			<< "Diameter: " << cir[x].calDiameter() << endl
			<< "Circumference: " << cir[x].calCircumference() << endl;
	}
}