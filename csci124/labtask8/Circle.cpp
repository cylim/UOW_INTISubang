#include "Circle.h"

//Class implementation
//initialize value for const double member type
const double Circle::pi = 3.14159265359;

//Constructor
Circle::Circle(){
	radius = 0.0;
}
//Mutator Function
void Circle::setRadius(double radius){
	this->radius = radius;
}
//Accessor Function
double Circle::getRadius(){
	return radius;
}
//Operational Function
//to count area of circle
double Circle::calArea(){
	return pi * (radius * radius);
}
//to count diameter of circle
double Circle::calDiameter(){
	return radius * 2.0;
}
//to count circumference of circle
double Circle::calCircumference(){
	return 2.0 * pi * radius;
}