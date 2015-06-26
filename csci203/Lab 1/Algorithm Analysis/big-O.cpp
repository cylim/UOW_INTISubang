#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void main()
{
	int sum, k, m, n, p, count = 0;
	time_t start, end;
	ofstream outfile;
	float diff;

	outfile.open("data.txt");

	for (k = 100; k <= 1000; k += 100) {
		outfile << k << ", ";
		start = clock();
		for (m = 0; m <= k; m++) {
			for (n = 0; n <= k; n++) {
				for (p = 0; p <= k; p++) {
					sum = m + n + p;
					if (sum == k)
						count++;
				}
			}
		}
		end = clock();
		diff = (float)(end - start) / CLOCKS_PER_SEC;
		outfile << diff << endl;
		cout << "Calculation finished for k = " << k << endl;
	}
	outfile.close();
	system("pause");

}







