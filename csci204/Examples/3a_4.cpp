#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int school;
	cin >> school;
	switch(school)
	{
	case 1:
		cout <<	"SCSSE" << endl;
//		break;
	case 2:
		cout << "SMAS" << endl;
//		break;
	case 3:
		cout << "SISAT" << endl;
//		break;
	case  4:
		cout << "SECTE" << endl;
		break;
	default:
		cout << "No such school" << endl;}
}
