#include <string>

using namespace std;

class Command{
public:
	Command(){ }
	~Command(){ }
	string command;
	int peer;
	string message;

	// For testing purpose, not real usage.
	// void seeResult(){
	// 	cout << command << endl
	// 		<< peer << endl
	// 		<< message << endl << endl;
	// }
private:
};