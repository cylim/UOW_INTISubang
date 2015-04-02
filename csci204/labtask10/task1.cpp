//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:10 - 1
//Date		:November 11th, 2014

#include <iostream>
#include <fstream> // import and output file
#include <cctype> // to convert char to uppercase
#include <stack> // for stack
#include <deque> // for deque
#include <vector> // for vector

using namespace std;

bool reverse(); // function to reverse the string
bool upper(); // function to capitalize the string
bool compare(); // function to compare two string

int main(){
	int option;
	while(true){
		//show the menu title
		cout << "\t+++++++++++++++++++++++++" << endl
			<< "\t+\tFile Management\t+" << endl
			<< "\t+++++++++++++++++++++++++" << endl;
		//show the menu selection
		cout << "1. Reverse file data" << endl
			<< "2. Uppercase file data" << endl
			<< "3. Compare file data" << endl
			<< "0. Exit program" << endl;
		cout << "Option: ";
		cin >> option;
		switch(option){
			case 1: // reverse the file data order
				reverse();
				break;
			case 2: // uppercase every character in file
				upper();
				break;
			case 3: // compare data inside two file.
				compare();
				break;
			case 0:
				cout << "Thanks for using. " << endl << endl;
				return 0;
			default:
				cout << "Wrong input, please try again." << endl << endl;
		}
	}
}
// function to reverse the string
bool reverse(){
	char filename[30];
	cout << "Enter import file name: ";
	cin >> filename;

	ifstream read(filename);
	if(!read){
		cout << "File not found!" << endl;
		return -1;
	}

	stack<char> reverse;
	while(read.good()){
		char temp = read.get();
		if(!read.eof()){
			reverse.push(temp);
		}
	}
	read.close();

	cout << "Enter export file name: ";
	cin >> filename;
	ofstream out(filename, ios::trunc);
	while(!reverse.empty()){
		out << reverse.top();
		reverse.pop();
	}
	out.close();
}
// function to capitalize the string
bool upper(){
	char filename[30];
	cout << "Enter file name: ";
	cin >> filename;

	ifstream read(filename);
	if(!read){
		cout << "File not found!" << endl;
		return -1;
	}

	deque<char> upper;
	while(read.good()){
		char temp = toupper(read.get());
		if(!read.eof()){
			upper.push_back(temp);
		}
	}
	read.close();


	cout << "Enter export file name: ";
	cin >> filename;
	ofstream out(filename, ios::trunc);
	while(!upper.empty()){
		out << upper.front();
		upper.pop_front();
	}
	out.close();
}
// function to compare two string
bool compare(){
	vector<char> compare[2];
	for(int x=0;x<2;x++){
		char filename[30];
		cout << "Enter file name: ";
		cin >> filename;

		ifstream read(filename);
		if(!read){
			cout << "File not found!" << endl;
			return -1;
		}

		while(read.good()){
			char temp = read.get();
			if(!read.eof()){
				compare[x].push_back(temp);
			}
		}
		cout << "File information recorded." << endl;
		read.close();
	}

	if(compare[0].size() != compare[1].size()){
		cout << "Sorry, the files are not same." << endl << endl;
		return -1;
	}

	for(int x=0;x<compare[0].size();x++){
		if(compare[0][x] != compare[1][x]){
			cout << "Sorry, the files are not same." << endl << endl;
			return -1;
		}
	}
	cout << "The files are identical." << endl << endl;
}