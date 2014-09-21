//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
#include <string>
using namespace std;

char tableProperties(int&, int&, char[], char); //prompt user to input the properties of table
float calculatePrice(int, int, char); //based on table properties, calculate the price
void displayPrice(float, int, int, char[], char); //display the table properties and price

int main(){
	int chairs, tableSurface; //numbers of chairs and surface of table
	char chairColor[10], woodType; //chair colors and wood type for table
	float total; //for storing the price
	woodType = tableProperties(chairs, tableSurface, chairColor, woodType);
	total = calculatePrice(chairs, tableSurface, woodType);
	displayPrice(total, chairs, tableSurface, chairColor, woodType);
}

//function used to ask user to choose their table properties
char tableProperties(int &chairs, int &tableSurface, char chairColor[], char woodType){
	//prompt user to input number of chairs
	cout << "Enter the number of chairs for table: ";
	cin >> chairs;
	//let user type the color they wanted
	cout << "Enter the colour of the cushions: ";
	cin >> chairColor;
	//prompt user to choose the size of the table
	cout << "Enter the surface area of the table: ";
	cin >> tableSurface;
	//let user to choose the wood type the like from the list
	//if user input is invalid, ask user to input again
	for(;;){ //infinite loop, until user key in correct wood type
		cout << "Enter the type of wood - m for mahogany, o for oak, or p for pine: ";
		cin >> woodType;
		//return respective woodtype to the woodType in main()
		switch(woodType){
			case 'M':
			case 'm':
				return 'm';
			case 'o':
			case 'O':
				return 'o';
			case 'p':
			case 'P':
				return 'p';
			default:
				cout << "Error input, please try again." <<endl;
		}

	}
}
//function used to calculate price for the table
float calculatePrice(int n, int s, char woodType){
	int x; //variable to store the wood type price
	//intialize wood type price to variable x
	switch(woodType){
		case 'm': 
			x = 200;
			break;
		case 'o':
			x = 150;
			break;
		case 'p':
			x = 95;
			break;
	}
	//the price calculation is chair * 0.5 + surface size
	//then multiply by the wood type.
	return (x * (s + 0.5 * n));
}
//function to display the table properties and price
void displayPrice(float total, int chairs, int tableSurface, char chairColor[], char woodType){
	//woodType2 is to store the real name of woodType stand for
	string woodType2;
	if (woodType == 'm')
		woodType2 = "mahogany";
	if (woodType == 'o')
		woodType2 = "oak";
	if (woodType == 'p')
		woodType2 = "pine";
	//display the table properties and price
	cout << "You have chosen a " << woodType2 << " table with: " << endl
		<< "Surface area " << tableSurface << " and " << chairs << " chairs with " << chairColor << " cushions!" << endl
		<< "Price is $" << total <<endl;
}