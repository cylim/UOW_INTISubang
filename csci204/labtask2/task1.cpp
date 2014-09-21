//This is a program with a function to store club member data
//Writen by Lim Chee Yeong INTI: J14016414 or UOW: 4933643

#include <iostream>
using namespace std;

class ClubMember{
	string clubName;
	string memberName;
	int memberID;
	const static int fee;

public:
	void setClubName(string);
	void setMemberName(string);
	void setMemberID(int);
	void display();
};
//implementation class function section:
//set function is used to let driver function to set
//value into private variable in class.
void ClubMember::setClubName(string name){
	clubName = name;
}

void ClubMember::setMemberName(string name){		
	memberName = name;
}

void ClubMember::setMemberID(int id){
	memberID = id;
}

//set value for member fee
const int ClubMember::fee = 25; 

//this function act as a bridge to let 
//driver function to display private data from class
void ClubMember::display(){
	cout << "Club Name: " << clubName << endl
		<< "Member Name: " << memberName << endl
		<< "Member ID: " << memberID << endl
		<< "Fees: RM" << fee << endl;
}

//driver function to try whether the class work:
//For testing purpose, the value is set automatically
int main(){
	ClubMember member;
	member.setClubName("Googley");
	member.setMemberName("Googler");
	member.setMemberID(666);
	member.display();
}