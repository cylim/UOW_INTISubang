//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:10 - 2
//Date		:November 11th, 2014

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

typedef map<int, string>::iterator mapit;
typedef map<int, string> maptype;

void populatemap(maptype& taxrecords, ifstream& ins);
mapit findrecord(maptype& taxrecords, int key);

int main(){
	map<int, string> taxrecord;

	char filename[30];
	cout << "File name: ";
	cin >> filename;
	ifstream ins(filename);
	//If filename not found in the system. terminated the program
	if(!ins){
		cout << "File not found!" << endl;
		return 0;
	}
	//else read all the data from file to the program

	populatemap(taxrecord, ins);
	ins.close(); // close file
	
	findrecord(taxrecord, 213233); // found
	findrecord(taxrecord, 110010); // not found
	findrecord(taxrecord, 212221); // found
}

void populatemap(maptype& taxrecord, ifstream& ins){
	pair< map<int, string>::iterator, bool> retval;
	int id;
	string name;
	while(ins.good()){
		if(!ins.eof()){
			ins >> id;
			ins.get();
			getline(ins, name);
			retval = taxrecord.insert(pair<int, string>(id, name));
			if(retval.second == false){
				cout << "Sorry, Tax ID " << id << " exist. " << endl;
			} else {
				cout << "Record " << id << " successed." << endl;
			}
		}
	}
}

mapit findrecord(maptype& taxrecord, int key){
	map<int, string>::iterator p = taxrecord.begin();

	while ( p != taxrecord.end()){
		if(p->first == key){
			cout << p->first << " " << p->second << endl;
			return p;
		}
		p++;
	}
	return taxrecord.end();
}