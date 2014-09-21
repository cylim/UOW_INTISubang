#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int x = 0;
	for (x=0; x < argc; x++)
	{
		cout << "arg " << x + 1 << " " << argv[x] << endl;}
	return 0;
}
