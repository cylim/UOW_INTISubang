//Author	: Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		: CSCI204
//Task		: 8 -1
//Date		: October 28th, 2014
//This is a program to log message into log.txt, after each log, user have to delete old log instances to create a new instances.

#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
//Logger Class Declaration
class Logger{
	static Logger* instance;
protected:
	Logger(){}
public:
	static Logger* Instance();
	static void log(int, string, int);
	static void stopLogger();
};
//Logger Class Implementation 
Logger* Logger::instance = 0;
//To check whether the log exist
Logger* Logger::Instance(){
	//if log not exist, instance point to address of ptr
	if( instance == 0)
		instance = new Logger;
	//else throw exception
	else
		throw((char*)&"Unable to initialize the logger");
	return instance;
}
//To write log message into log.txt
void Logger::log(int code, string message, int level){
	ofstream write("log.txt", ios::app);
	write << code << " " << message << " " << level << '\n';
	write.close();

}
//To clear the instance and initialize it with 0
void Logger::stopLogger(){
	delete instance;
	instance=0;
}

//Driver progam to test the Logger
int main(){
	int input;
	while(true){
		cout << "1. Log Message\n"
			<< "2. Delete Log\n"
			<< "0. Exit\n";
		cout << "Option: ";
		cin >> input;

		int code, level;
		string message;
		Logger *ptr;
		switch(input){
			case 1: // Create log instance and log message
				try{
					ptr = Logger::Instance();
					//read the log message
					cout << "Code: ";
					cin >> code;
					cout << "Message: ";
					cin.ignore();
					getline(cin, message);
					cout << "Level: ";
					cin >> level;
					//write into file
					ptr->log(code, message, level);
				}
				catch(char* e){
					//show the exception occur issue
					cout << "Issue: " << e << endl;
					cout << "Please stop previous logger before create a new one."<< endl;
				}
				break;
			case 2: // Clear instances.
				ptr->stopLogger();
				break;
			case 0: // Terminate
				cout << "System Terminated." << endl;
				return 0;
			default:
				cout << "Wrong input, please try again." << endl;
		}
	}
	
}