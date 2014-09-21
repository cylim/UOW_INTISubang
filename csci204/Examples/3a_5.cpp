#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int x = 0;
	char temp;
	cout << &x << endl;
	for (x=0; x < atoi(argv[1]); x++)
	{
		cin >> temp;
		cout << "You entered " << static_cast<int>(temp) << endl;
		cout << "You entered " << &temp << endl;
  }
}
