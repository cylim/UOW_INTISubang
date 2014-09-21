/A program that asks the user for input to buy theater seats.

#include <iostream>
#include <iomanip>
using namespace std;

//Function Declarations
int Show_Menu ();			
void Show_Chart ();			 


const char FULL = '*';	//Seat taken
const char EMPTY = '#';	 //Seat open
const int rows = 15;	//Number of rows
const int columns = 30;		//Number of seats per row
char map [rows][columns]; //Array to hold seating chart
double price;
int total = 0;
int seat = 450;
int seat2 = 0;
int Quit = 1;



int main ()
{

const int Num_Rows = 15;
int price [Num_Rows];
int row2, column2, cost;
int answer;


	cout << "\t********************************************" << endl;
	cout << "\t*				           *" << endl;
	cout << "\t*       Welcome to The TGS Theater         *" << endl;
	cout << "\t*					   *" << endl;
	cout << "\t********************************************" << endl;

	cout << endl << endl;


//Sets the row prices.

	for (int count = 0; count < rows; count++)
		{
			cout << "Please enter the price for row " << (count + 1) << ": ";
				cin >> price [count];
			   
		}

	for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				map [i][j] = EMPTY;
		}


int choice;
	do
	{
		choice = Show_Menu();	  // Shows the main menu function.

		switch (choice)
		{
			case 1:
				cout << "View Seat Prices\n\n";
				
				for (int count = 0; count < rows; count++)
				{
					cout << "The price for row " << (count + 1) << ": ";
					cout << price [count] << endl;
				}

				break;

			case 2:
				cout << "Purchase a Ticket\n\n";

				do 
				{
					cout << "Please select the row you would like to sit in: ";
					cin >> row2;
					cout << "Please select the seat you would like to sit in: ";
					cin >> column2;

					if (map [row2] [column2] == '*')
						{
							cout << "Sorry that seat is sold-out, Please select a new seat.";
							cout << endl;
						}

					else 
					{
						cost = price [row2] + 0;
						total = total + cost;
						cout << "That ticket costs: " << cost << endl;
						cout << "Confirm Purchase? Enter (1 = YES / 2 = NO)";
						cin >> answer;
						seat = seat - answer;
						seat2 += answer;
						
						if (answer == 1)
						{ 
							cout << "Your ticket purchase has been confirmed." << endl;
							map [row2][column2] = FULL;
						}
						else if (answer == 2)
						{
							cout << "Would you like to look at another seat? (1 = YES / 2 = NO)";
							cout << endl;
							cin >> Quit;
						}
						
						cout << "Would you like to look at another seat?(1 = YES / 2 = NO)";
						cin >> Quit;
					}

				}
				while (Quit == 1);
					
				break;

			case 3:
				cout << "View Available Seats\n\n";
				Show_Chart ();
				break;

			case 4:
				cout << "View Seat Sales\n\n";
				break;

			case 5:
				cout << "quit\n";
				break;

			default : cout << "Error input\n";
		}

	} while (choice != 5);







return 0;
}

//********************************************************************************
//********************************************************************************
//**																			**
//**							  Define Functions.							 **
//**																			**
//********************************************************************************
//********************************************************************************



// Show Menu Function...

int Show_Menu()
{
	int MenuChoice;
		cout << endl << endl;
		cout << " \tMAIN MENU\n";
		cout << " 1. View Seat Prices.\n";
		cout << " 2. Purchase a Ticket.\n";
		cout << " 3. View Available Seats.\n";
		cout << " 4. View Ticket Sales.\n";
		cout << " 5. Quit the program.\n";
		cout << "_____________________\n\n";
		cout << "Please enter your choice: ";
		cin >> MenuChoice;
		cout << endl << endl;
	return MenuChoice;
}



//Show Seating Chart Function

void Show_Chart ()
{
	cout << "\tSeats" << endl;
	cout << "   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n";

		for (int count = 0; count < 15; count++)
		{
			cout << endl << "Row " << (count + 1);

			for (int count2 = 0; count2 < 30; count2++)
			{
				cout << " " <<  map [count] [count2];
			}
		}
			cout << endl;
}