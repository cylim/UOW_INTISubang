#include "class.h"

City::City(string name, float distance){
	this->name = name;
	this->distance = distance;
}
float City::getDistance(){
	return distance;
}
void City::setDistance(float distance){
	this->distance = distance;
}
City City::operator+(City &c){
	City city;
	city.name = this->name + " to " + c.name;
	return city;
}
void City::display(){
	cout << "Location: " << name
		<< "\nDistance: " << distance << " KM." << endl;
}

Planet::Planet(string name, float distance){
	this->name = name;
	this->distance = distance;
}
float Planet::getDistance(){
	return distance;
}
void Planet::setDistance(float distance){
	this->distance = distance;
}
Planet Planet::operator+(Planet &p){
	Planet planet;
	planet.name = this->name + " to " + p.name;
	return planet;
}
void Planet::display(){
	cout << "Location: " << name
		<< "\nDistance: " << distance << " millions KM." << endl;
}