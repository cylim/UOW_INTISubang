//This program find the sum of all positive integers (i.e. 1+2+3+...+n, where n is input by user)
//Tasks :
//(1) Find the Big-O notation of the algorithm
//(2) Give a better algorithm

#include <iostream>
#include <ctime>

using namespace std;

void main()
{
	time_t start, end;
	unsigned long long a, n, sum = 0;
	float diff;

	cout << "Enter the ending number : ";
	cin >> n;
	cout << "Calculation start..." << endl;
	start = clock();
	//Algorithm starts
	int half = n / 2;
	int sum = (half + 1) * half
	for (a = 1; a <= n; a++) {
		sum = sum + a;
	}
	//Algorithm ends
	end = clock();
	diff = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Calculation complete." << endl;
	cout << "The sum is " << sum << endl;
	cout << "Total running time is " << diff << " second" << endl;

	system("pause");

}

