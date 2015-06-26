#include "Match.h"
#include <iostream>

using namespace std;

match::match()
{
	numOfMatches = 10;
	// winning positions
	node[0] = WIN; node[3] = WIN; node[4] = WIN; node[5] = WIN;  
	// losing positions
	node[1] = LOSE; node[2] = LOSE;  
	// draw oisitions
	node[10] = DRAW; node[9] = DRAW; node[8] = DRAW; node[7] = DRAW; node[6] = DRAW;

	edge[0][0] = F;
	edge[0][1] = T;
	edge[0][2] = F;
	edge[0][3] = F;
	edge[0][4] = F;
	edge[0][5] = F;
	edge[0][6] = F;
	edge[0][7] = F;
	edge[0][8] = F;
	edge[0][9] = F;
	edge[0][10] = F;
	
	edge[1][0] = F;
	edge[1][1] = F;
	edge[1][2] = F;
	edge[1][3] = F;
	edge[1][4] = F;
	edge[1][5] = F;
	edge[1][6] = F;
	edge[1][7] = F;
	edge[1][8] = F;
	edge[1][9] = F;
	edge[1][10] = F;
	
	edge[2][0] = T;
	edge[2][1] = F;
	edge[2][2] = F;
	edge[2][3] = T;
	edge[2][4] = F;
	edge[2][5] = F;
	edge[2][6] = F;
	edge[2][7] = F;
	edge[2][8] = F;
	edge[2][9] = F;
	edge[2][10] = F;

	edge[3][0] = T;
	edge[3][1] = T;
	edge[3][2] = F;
	edge[3][3] = F;
	edge[3][4] = T;
	edge[3][5] = F;
	edge[3][6] = F;
	edge[3][7] = F;
	edge[3][8] = F;
	edge[3][9] = F;
	edge[3][10] = F;
	
	edge[4][0] = F;
	edge[4][1] = T;
	edge[4][2] = T;
	edge[4][3] = F;
	edge[4][4] = F;
	edge[4][5] = T;
	edge[4][6] = F;
	edge[4][7] = F;
	edge[4][8] = F;
	edge[4][9] = F;
	edge[4][10] = F;

	edge[5][0] = F;
	edge[5][1] = F;
	edge[5][2] = T;
	edge[5][3] = T;
	edge[5][4] = F;
	edge[5][5] = F;
	edge[5][6] = T;
	edge[5][7] = F;
	edge[5][8] = F;
	edge[5][9] = F;
	edge[5][10] = F;

	edge[6][0] = F;
	edge[6][1] = F;
	edge[6][2] = F;
	edge[6][3] = T;
	edge[6][4] = T;
	edge[6][5] = F;
	edge[6][6] = F;
	edge[6][7] = T;
	edge[6][8] = F;
	edge[6][9] = F;
	edge[6][10] = F;

	edge[7][0] = F;
	edge[7][1] = F;
	edge[7][2] = F;
	edge[7][3] = F;
	edge[7][4] = T;
	edge[7][5] = T;
	edge[7][6] = F;
	edge[7][7] = F;
	edge[7][8] = T;
	edge[7][9] = F;
	edge[7][10] = F;

	edge[8][0] = F;
	edge[8][1] = F;
	edge[8][2] = F;
	edge[8][3] = F;
	edge[8][4] = F;
	edge[8][5] = T;
	edge[8][6] = T;
	edge[8][7] = F;
	edge[8][8] = F;
	edge[8][9] = T;
	edge[8][10] = F;

	edge[9][0] = F;
	edge[9][1] = F;
	edge[9][2] = F;
	edge[9][3] = F;
	edge[9][4] = F;
	edge[9][5] = F;
	edge[9][6] = T;
	edge[9][7] = T;
	edge[9][8] = F;
	edge[9][9] = F;
	edge[9][10] = T;

	edge[10][0] = F;
	edge[10][1] = F;
	edge[10][2] = F;
	edge[10][3] = F;
	edge[10][4] = F;
	edge[10][5] = F;
	edge[10][6] = F;
	edge[10][7] = T;
	edge[10][8] = T;
	edge[10][9] = F;
	edge[10][10] = F;
}

void match::startGame()
{
	char ans;
	cout << "The Match Game\n";
	cout << "==============\n";
	cout << "There are 10 matches on the table. At each turn, player can take 2 or 3 matches\n";
	cout << "OR return 1 match (if the total matches is less than 10). Game is going on till\n";
	cout << "1 match remains on the table. The winner is the guy who left this match.\n\n";
	cout << "Do you want to start first ? (y/n) ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y')
		humanTurn = true;
	else
		humanTurn = false;

	cout << "The game start now...Good luck !\n\n";
	do {
		cout << "Matches remaining : " << numOfMatches << endl;
		if (humanTurn) {
			if (numOfMatches == 10) 
				do {	
					cout << "Take 2 or 3 matches : ";
					cin >> take;
				} while (take != 2 && take != 3) ;
			else if (numOfMatches == 2)
				do {	
					cout << "Take 2 matches or return 1 match (use -1): ";				
					cin >> take;
				} while (take != 2 && take != -1) ;
			else if (numOfMatches < 2)
				do {
					cout << "You can only return 1 match (use -1): ";
					cin >> take;
				} while (take != -1);
			else
				do {
					cout << "Take 2 or 3 matches or return 1 match (use -1): ";
					cin >> take;
				} while (take != 2 && take != 3 && take != -1);

			humanTurn = false;
			if (endGame ()) {
				cout << "Matches remaining : " << numOfMatches << endl;
				cout << "Congratulation ! You won the game !\n";
			}
		}
		else { // Computer turn
			take = computerTurn ();
			if (take == -1)
				cout << "I return 1 match.\n";
			else
				cout << "I take " << take << " matches.\n";
			humanTurn = true;
			if (endGame ()) {
				cout << "Matches remaining : " << numOfMatches << endl;
				cout << "Sorry, I beat you this time.\n";
			}
		}
	} while (numOfMatches != 1);
}

bool match::endGame ()
{
	numOfMatches = numOfMatches - take;
	if (numOfMatches == 1)
		return true;
	else
		return false;
}
 
int match::computerTurn ()
{
	int m, dec;
	// searching for losing position
	// take matches in a way that forcing human player to losing position
	for (m=10; m>=0; m--) {
		if (edge[numOfMatches][m] == T && node[m] == LOSE) { 
			dec = numOfMatches - m;
			return dec;
		}
	}

	// if cannot move to losing position
	// then try any drawing position
	for (m=10; m>=0; m--) {
		if (edge[numOfMatches][m] == T && node[m] == DRAW) { 
			dec = numOfMatches - m;
			return dec;
		}
	}

	// if still cannot find a move 
	// then try any winning position
	for (m = 10; m >= 0; m--) {
		if (edge[numOfMatches][m] == T && node[m] == WIN) {
			dec = numOfMatches - m;
			return dec;
		}
	}

}