//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:5
//Date		:September 18th, 2014
//This program is a mini game to guess the letter in a word from wordlist.

#include <iostream> //cin and cout
#include <fstream> // input file for reading
#include <cstdlib> // rand() function
#include <cstring> // strlen for the length of array of char
#include <cctype> // copy date into array of char
using namespace std;

int main(){
	//For testing purpose, use the file directly
	//ifstream in("hiddenWords.txt");
	//Ask user to enter filename for opening file
	char file[30];
	cout << "Enter filename: ";
	cin >> file;
	ifstream in(file);
	//check if the file available, if not available terminate the program
	if(!in){
		cout << "File not found, program terminated." << endl;
		return 0;
	}
	//variable declaration for storing file data
	//total = total word availble
	//wordList[total] = each word store into one of the array of char
	int total;
	char ** wordList = new char*[total];
	in >> total;
	for(int x=0; x< total; x++){
		wordList[x] = new char[21];
		in >> wordList[x];
	}
	in.close(); //close file
	//check the correctness of data from file
	// cout << total << endl;
	// for(int i=0;i<total;i++){
	// 	cout << wordList[i] << endl;
	// }

	//randomize the word appear order, set length to the word
	//assign '*'to secretWord according to the length
	int random = rand() % total;
	int length = strlen(wordList[random]);
	char secretWord[21];
	for(int i=0; i<length; i++){
		secretWord[i] = '*';
	}
	int count = 0; //to count how many attempt user tried to get the word
	char userInput; //to store user input for comparison
	bool validate = false; //to check whether the letter is available in the word.
	//infinite loop to perform the word guessing part, user can terminate the program by enter '*'
	//check the userInput with targeted word, if available then assign the letter to it
	//else print out the wrong message and asked user to try again
	//if the user input all the letter correctly, asked user whether want to play again with another word
	while(true){
		count+=1; // increase 1 every attempt
		validate = false; //set to false for validation purposes
		cout << "Guess letter in the secret word: " << secretWord << endl;
		cout << "Enter letter(* to quit): ";
		cin >> userInput;
		//compare the userInput with targeted word, if same assign the letter
		for(int i=0; i<total; i++){
			if (userInput == *(*(wordList + random) + i)){
				secretWord[i] = wordList[random][i];
				validate = true;
			}
		}
		//if there is no same input, print following statement
		if(validate == false && userInput != '*'){
			cout << "Nice guess, but it is not inside the word." << endl;
		}
	//when user finished the word, congratulate the user and told him how many time he attempted
		if(strcmp(secretWord, wordList[random]) == 0){
			cout << "Good Job!" << endl;
			cout << "You have guessed the word " << secretWord 
				<< " in " << count << " tries." << endl;
			userInput = '*';
		}
		//asked user whether wanted to continue
		if (userInput == '*'){
			cout << "Would you like to play the game again(Y/N)";
			cin >> userInput;
			switch(userInput){
				case 'Y':
				case 'y':
					//reset the targeted word.
					strcpy(secretWord, "");
					random = rand() % total;
					length = strlen(wordList[random]);
					for(int i=0; i<length; i++){
						secretWord[i] = '*';
					}
					secretWord[length] = '\0';
					count = 0;
					break;
				default:
					cout << "Wrong Input, ";
				case 'N':
				case 'n':
					cout << "Thank you for playing the game!" << endl;
					return 0;
			}	
		}
	}
}