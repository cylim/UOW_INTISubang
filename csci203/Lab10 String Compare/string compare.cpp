#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main ()
{
	ifstream infile;
	string text, pattern;
	char input[500];
	int found, pos = 0, count = 0, n = 0, p = 0;
	time_t start, end;
	float diff;

	infile.open("data.txt");

	cout << "Enter search pattern : ";
	cin >> pattern;
	start = clock();
	do {
		infile.getline(input, 500);
		text = input;
		n = 0;
		p = 0;
		do {
			found = text.find(pattern, n);
			p = n;
			if (found != string::npos) {
				cout << "Found \"" << pattern << "\" at position " << pos + found << endl;
				count++;
				n = found + 1;
			}
		} while (p != n);
		pos = pos + infile.gcount();

	} while (infile.eof() != true);

	end = clock();
	diff = (float)(end - start) / CLOCKS_PER_SEC;

	if (count == 0)
		cout << "\"" << pattern << "\" not found" << endl;
	cout << "Time used is " << diff << " second" << endl;
	infile.close();
	return 0;
}