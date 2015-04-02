#include <iostream>
#include <cstring>
using namespace std;

struct User{
	char id[6];
	int lab, station, inHour, inMin, outHour, outMin;
	float price; 
};

void login(char***, int, int[], User*&, int&); // Log in
void logout(char***, User*&, int&, double&); // Log out
void search(User[], int&); // Search user
void list(char***, int, int[]); // List Lab
void displayTotal(double); // Display total charges
void displayLab(char***, int, int[]); // Display the computer lab info