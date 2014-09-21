//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:1
//This program read files into binary

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "fileOperation.h"
using namespace std;

int readToBinary(ChemicalElement list[]){
	int num=0; //size of struct array
	//For testing purpose, use file below,
	//char file[] = "chemicalElements.txt";
	//open the file for reading required information
	char file[50];
	cout << "Please enter filename: ";
	cin >>file;
	ifstream read(file);
	//check file, if the file is not available
	if(!read){
		cout << "File not found!" << endl;
		// return value -1 to main(), so that main can return to 0
		return -1;
	}
	//Read all information from the file to struct
	while(!read.eof()){
		read >> list[num].mass;
		read >> list[num].name;
		read >> list[num].symbol;
		read >> list[num].atomicNumber;
		num++;
	}
	read.close();
	//For testing purpose, check the total line and output of the struct
	//cout << num;
	//for(int i =0; i < num; i++){
	//	cout << list[i].mass << "\t" << list[i].name << "\t" << list[i].symbol << "\t" << list[i].atomicNumber << "\n";
	//}

	//create an output file
	cout << "Enter a filename for binary output: ";
	cin >> file;
	ofstream bin(file, ios::out | ios::binary);
	//For testing purpose, use example.bin
	//ofstream bin("example.bin", ios::out | ios::binary);
	for(int i=0; i<num; i++){
		bin.write((char*)&list[i], sizeof(ChemicalElement));
	}
	bin.close();

	//For testing purpose, to see whether retrieve from binary is correct
	//ifstream in("example.bin", ios::in | ios::binary);
	//for(int i = 0; i < num; i++){
	//	in.read((char*)&list[i], sizeof(ChemicalElement));
	//	cout << list[i].atomicNumber << '\t'
	//		<< list[i].name << '\t'
	//		<< list[i].symbol << '\t'
	//		<<list[i].mass << endl;
	//}
	//in.close();
	return num; //return the size of the struct array
}