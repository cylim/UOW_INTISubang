//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Task		:3
//This program is to pass three class object 
//into one class static variable, and display the total

#include <iostream>
using namespace std;
//class declaration
class HotDogStand{
	string ID;
	int sold;
	static int total;
public:
	HotDogStand(string, int);
	void justSold();
	//void displaySold();
	int getSold();
	static void setTotal(int, int, int);
	static int displayTotal();
};
//class function implemantation:
int HotDogStand::total = 0; //set total to 0
//Construtor, used to set id and sales amount
HotDogStand::HotDogStand(string ID, int sold){
	this->ID = ID;
	this->sold = sold;
}
//function that increase sales by 1
void HotDogStand::justSold(){
	sold +=1;
}
//For testing purpose, display the sales
//void HotDogStand::displaySold(){
//	cout << "\nStall " << ID << " Sales :" << sold << endl;
//}
//Accessor method, to access the sales
int HotDogStand::getSold(){
	return sold;
}
//static function, which add up all class value
void HotDogStand::setTotal(int a, int b, int c){
	total = a+b+c;
}
//static function, display the total amount of all added
int HotDogStand::displayTotal(){
	return total;
}
//driver program to test the system
int main(){
	//declare three classes object
	HotDogStand stallA("A123", 100);
	HotDogStand stallB("B456", 200);
	HotDogStand stallC("C789", 300);
	//increment of the sales for all classes object
	for(int i=0; i < 100; i++){
		stallA.justSold();
		if(i == 50){
			for(int x=0; x < 50; x++){
				stallB.justSold();
				stallC.justSold();
			}
		}
	stallC.justSold();
	}	
	//For testing purpose, show each stall sales
	//stallA.displaySold();
	//stallB.displaySold();
	//stallC.displaySold();

	//add all total together and print it out
	HotDogStand::setTotal(stallA.getSold(), stallB.getSold(), stallC.getSold());
	cout << "Total sales: " << HotDogStand::displayTotal() << endl;
}