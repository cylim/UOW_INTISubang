#include <iostream>
using namespace std;

class City{
	string name;
	float distance;
public:
	City(string="none", float=0);
	float getDistance();
	void setDistance(float);
	City operator+(City&);
	void display();
};

class Planet{
	string name;
	float distance;
public:
	Planet(string="none", float=0);
	float getDistance();
	void setDistance(float);
	Planet operator+(Planet&);
	void display();
};