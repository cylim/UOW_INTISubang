#include <iostream>
	#include <new>
	using namespace std;

	int main()
	{
		int* p;
		p = new(nothrow) int[100000000000];
		if (p == NULL)
		{
			cout << "Error" << endl;
			return 1;
		}
		/* code */
		return 0;
	}
