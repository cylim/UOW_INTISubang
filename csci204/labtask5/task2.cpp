//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab task	:5 - 2
//Date		:September 30th, 2014
//This program built a better understanding in inheritance and the differences between initialize using function or constructor
#include <iostream>
using namespace std;

//class declaration
class Payment{
	float payment;
public:
	Payment();
	Payment(float);
	//for the setField() and paymentDetails() function, using inline function
	inline void setField(float payment){ this->payment = payment; }
	inline void paymentDetails(){ cout << "Payment\t:RM"<< payment << endl; }

};
//class CashPayment inherited Payment
class CashPayment: public Payment{
	float balance;
public:
	CashPayment();
	CashPayment(float, float);
	void setField(float, float);
	void paymentDetails();
};
//class CreditCardPayment inherited Payment
class CreditCardPayment: public Payment{
	string name;
	string expire;
	long number;
public:
	CreditCardPayment();
	CreditCardPayment(float, string, string, long);
	void setField(float, string, string, long);
	void paymentDetails();
};

//class function implementation
//Payment class function implementation
//Default Constructor
Payment::Payment(){
	payment = 0;
}
//Non-default constructor
Payment::Payment(float payment){
	setField(payment);
}
//for the Payment class setField() and paymentDetails() function, using inline function

//CashPayment class function implementation
//Default Constructor
CashPayment::CashPayment(){
	balance = 0;
}
//Non-default construtor
CashPayment::CashPayment(float payment, float balance){
	setField(payment, balance);
}
//Mutator, used to set value for the CashPayment class
void CashPayment::setField(float payment, float balance){
	Payment::setField(payment); //called base class setField()
	this->balance = balance;
}
//display the details of the CashPayment class
void CashPayment::paymentDetails(){
	cout << "Cash Payment Details," << endl;
	Payment::paymentDetails(); //called base class paymentDetails()
	cout << "Balance\t:RM" << balance << endl;
}

//CreditCardPayment class function implementation
//Default Constructor
CreditCardPayment::CreditCardPayment(){
	name ="";
	expire = "";
	number = 0;
}
//Non-default construtor
CreditCardPayment::CreditCardPayment(float payment, string name, string expire, long number){
	setField(payment, name, expire, number);
}
//This function is used to set data to CreditCardPayment object
void CreditCardPayment::setField(float payment, string name, string expire, long number){
	Payment::setField(payment); //called base class setField()
	this->name = name;
	this->expire = expire;
	this->number = number;
}
//This function is used to display details from CreditCardPayment object with it base class
void CreditCardPayment::paymentDetails(){
	cout << "Credit Card Payment Details," << endl;
	Payment::paymentDetails(); //called base class  paymentDetails()
	cout << "Name\t:" << name << endl;
	cout << "Expire Date: " << expire << endl;
	cout << "Card Number: " << number << endl;
}

//driver function to test all the object with two different way of implementation
int main(){
	CashPayment cashA; //create CashPayment object using default constructor
	CashPayment cashB(223.5, 176.5); //create CashPayment object using non-default constructor
	CreditCardPayment creditA; //create CriditCardPayment object using default constructor
	CreditCardPayment creditB(124.5, "Lim Chee Yeong", "Dec 31st, 2099", 4283321015332274); //create CreidtCardPayment object using non-default constructor

	cashA.setField(12, 38); //set the data of cashA using setField() function
	creditA.setField(588.88, "Kok Xuan Zhao", "Sept 30th, 2014", 5196032006675295); //set the data of creditA using setField() function

	//output of all four object
	cout << "Display Cash A," << endl;
	cashA.paymentDetails();
	cout << endl << "Display Cash B," << endl;
	cashB.paymentDetails();
	cout << endl << "Display Credit A," << endl;
	creditA.paymentDetails();
	cout << endl << "Display Credit B," << endl;
	creditB.paymentDetails();
}