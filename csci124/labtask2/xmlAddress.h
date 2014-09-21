//This header file act as a media to connect main.cpp and xmlAddress.cpp
//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

struct list{
	char name[25];
	char street[25];
	char city[15];
	char state[15];
	char postcode[10];
};

int readAddress(list[]); //read address into struct
void searchPostcode(int, list[]); //search by postcode
void searchCity(int, list[]); //search by city