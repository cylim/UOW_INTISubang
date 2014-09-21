#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int x = 0;
	char temp;
	for (x=0; x < atoi(argv[1]); x++)
	{
		cin >> temp;
		cout << "You entered " << temp << endl;}
}
