//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:9 - 1
//Date		:November 9th, 2014

#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;

//class template to count the type occured and display.
class Counter{
	int countTypes[10], num, total;
	string types[10];
public:
	Counter(){ num = 0; total = 0; };
	//template functionto take an arbitrary type, and store it
	template<class V> void CountMe(V variable){
		bool valid = false;
		string temp = typeid(variable).name();
		//if there is no arbitrary type in the data, assign it.
		if(num == 0){
			types[num] = temp;
			countTypes[num] = 1;
			num+=1;
			total+=1;
		} else if(num <= 10){ // if there is less than 10 types
			//check the types with the data, if same, add together
			for(int i=0; i<num; i++){
				if(types[i] == temp){
					countTypes[i]+=1;
					total+=1;
					valid = true;
					break;
				}
			}
			// if can't find in data, add new one.
			if(valid == false && num !=10){
				types[num] = temp;
				countTypes[num] = 1;
				num+=1;
				total+=1;
			}
		} else { //when there is more than 10 types.
			cout << "The objects can't handle more than 10 types." << endl;
		}
	}
	void display(){
		//print out the infor about the arbitrary type in data.
		cout << "There is " << total << " objects passed in." << endl;
		cout << "Types\tAppear" << endl;
		for(int i=0;i<num;i++){
			cout << types[i] << '\t' << countTypes[i] << endl;
		}
	}
};

//Test class 1
class Student{
	int id;
	string name;
public:
	Student(int id, string name){
		this->id = id;
		this->name = name;
	}
	int getID(){ return id; };
	string getName(){ return name; };
};

//Test class 2
class Phone{
	string phoneNum;
	int lengthCall;
	double rates;
public:
	Phone(){
		phoneNum= "0123456789";
		lengthCall = 20;
		rates = 0.15;
	}
	string getPhoneNum(){ return phoneNum; }
	int getLengthCall(){ return lengthCall; }
	double getRates(){ return rates; }
};


int main(){
	Phone phone, *p1;
	Student StudentA(1001, "Des");

	Counter count; // create the class with template function
	count.CountMe(phone.getRates()); // double
	count.CountMe(phone.getPhoneNum()); // String
	count.CountMe(phone.getLengthCall()); // int
	count.CountMe(StudentA.getID()); // int
	count.CountMe(StudentA.getName()); // String
	count.CountMe(phone); //class
	count.CountMe(p1); //pointer of class

	count.display(); // display the data
}