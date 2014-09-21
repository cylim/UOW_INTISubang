//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Task		:3
//This program is to test the uses of copy constructor

#include <iostream>
using namespace std;

class PhoneCall{
	string phoneNum;
	int lengthCall;
	float rates;
public:
	PhoneCall();
	PhoneCall(string, int = 0, float = 0);
	PhoneCall(const PhoneCall& copy);
	~PhoneCall();
	void setPhoneNum(string);
	void setLengthCall(int);
	void setRates(float);
	string getPhoneNum();
	int getLengthCall();
	float getRates();
	float calCharges();
};
//Class function implementation:
//Default Constructor
PhoneCall::PhoneCall(){
	setLengthCall(0);
	setRates(0);
}
//non-default constructor
PhoneCall::PhoneCall(string phoneNum, int lengthCall, float rates){
	setPhoneNum(phoneNum);
	setLengthCall(lengthCall);
	setRates(rates);
}
//copy constructor
PhoneCall::PhoneCall(const PhoneCall &copy){
	setLengthCall(copy.lengthCall);
	setRates(copy.rates);
}
//Destructor implementation:
PhoneCall::~PhoneCall(){
	cout << "PhoneCall: "<< getPhoneNum() <<" deleted" <<endl;
}
//Mutator function implementation:
void PhoneCall::setPhoneNum(string phoneNum){
	this->phoneNum = phoneNum;
}
void PhoneCall::setLengthCall(int lengthCall){
	this->lengthCall = lengthCall;
}
void PhoneCall::setRates(float rates){
	this->rates = rates;
}
//Accessor function implementation:
string PhoneCall::getPhoneNum(){
	return phoneNum;
}
int PhoneCall::getLengthCall(){
	return lengthCall;
}
float PhoneCall::getRates(){
	return rates;
}
//class function for counting charges
float PhoneCall::calCharges(){
	return getRates()*getLengthCall();
}
//Driver program to test the function of the class
int main(){
	string phoneNum[3], max;
	int mins[3];
	float rates[3];
	//user input data for all the phoneCall() class object
	for(int i = 0; i<3 ; i++){
		cout << "Phone call: " << i+1 << endl;
		cout << "Enter phone number: ";
		cin >> phoneNum[i];
		//check the phoneNum with previous phoneNum keyed in, if same, terminate the program
		for(int x = 0; x<i ; x++){
			if (phoneNum[i] == phoneNum[x]){
				cout << "The number had been called" << endl;
				return 0;
			}
		}
		cout << "Enter talk time in minutes: ";
		cin >> mins[i];
		cout << "Enter charge rates per minutes: ";
		cin >> rates[i];
	}
	//Creating object of the class using three different types of constructor
	PhoneCall defaultPhone;
	PhoneCall nonDefaultPhone(phoneNum[1], mins[1], rates[1]);
	PhoneCall copyPhone(defaultPhone);
	//set value for default constructor object
	defaultPhone.setPhoneNum(phoneNum[0]);
	defaultPhone.setLengthCall(mins[0]);
	defaultPhone.setRates(rates[0]);
	//set value for copy constructor object which copied default constructor object
	copyPhone.setPhoneNum(phoneNum[2]);
	copyPhone.setLengthCall(mins[2]);
	copyPhone.setRates(rates[2]);
	//print out every phoneCall charges
	cout << defaultPhone.getPhoneNum() << " charges: RM" << defaultPhone.calCharges() << endl;
	cout << nonDefaultPhone.getPhoneNum() << " charges: RM" << nonDefaultPhone.calCharges() << endl;
	cout << copyPhone.getPhoneNum() << " charges: RM" << copyPhone.calCharges() << endl;
	//check which phoneCall have highest charges and then print it out.
	max = defaultPhone.getPhoneNum();
	if(nonDefaultPhone.calCharges() > defaultPhone.calCharges()){
		max = nonDefaultPhone.getPhoneNum();
	}
	if(copyPhone.calCharges() > defaultPhone.calCharges() && copyPhone.calCharges() > nonDefaultPhone.calCharges()){
		max = copyPhone.getPhoneNum();
	}
	cout << max << " is the highest charge." << endl;
}