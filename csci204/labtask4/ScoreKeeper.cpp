//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:4 -3
//Date		:September 9th, 2014
//This program make use of dynamic declaration with the overload operator

#include <iostream>
using namespace std;

class ScoreKeeper{
	// overload << operator for easy display of the class content
	friend ostream& operator<<(ostream&, const ScoreKeeper&);
private:
	string subject;
	int num;
	float* assessment; //declare as pointer
public:
	ScoreKeeper(string, int);
	void operator=(ScoreKeeper&); // overload = operator, for easy assign
};
//Class constructor
ScoreKeeper::ScoreKeeper(string subject, int num){
	this->subject = subject;
	this->num = num;
	assessment = new float[num]; //set the assessment size as num
	//prompt user to input assessment mark, if mark is not valid, reprompt
	for(int i=0; i<num;i++){
		do{
			cout << "Assessment " << i+1 << ": ";
			cin >> assessment[i];
		}while(assessment[i] < 0 || assessment[i] > 100);	
	}
}
//this function copy the parameter object and assign to another object
void ScoreKeeper::operator=(ScoreKeeper& s){
	this->subject = s.subject;
	this->num = s.num;
	for (int i = 0; i < this->num; ++i){
		this->assessment[i] = s.assessment[i];
	}
}
//this function cout all the info in the parameter object
ostream& operator<<(ostream& out, const ScoreKeeper& s){
	out << "Subject: " << s.subject << endl
		<< "There is " << s.num << " Assessment," << endl;
	for(int i=0;i<s.num;i++){
		out << "Assessment " << i+1 << ": " << s.assessment[i] << endl;
	}
	return out;
}


int main(){
	//object declaration
	ScoreKeeper sub("Computer Science", 2);
	//print out the result of the object
	cout << "First Subject," << endl;
	cout << sub << endl;
	//create another object, and assign sub object to it
	ScoreKeeper sub2 = sub;
	//print out second object
	cout << "Second Subject," << endl;
	cout << sub2;
}