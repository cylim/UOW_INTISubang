#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int bad_LC1 (int seed)
{
	int a = 53;
	int c = 79;
	int m = 65536;
	return (a*seed + c) % m;
}

int bad_LC2 (int seed)
{
	int a = 29;
	int c = 131;
	int m = 65536;
	return (a*seed + c) % m;
}

int good_LC(int seed)
{
	int a = 37;
	int c = 193;
	int m = 65536;
	return (a*seed + c) % m;
}

int main()
{
	int count_a[6] = { 0, 0, 0, 0, 0, 0 };
	int count_b[6] = { 0, 0, 0, 0, 0, 0 };
	int count_c[6] = { 0, 0, 0, 0, 0, 0 };
	int count_d[6] = { 0, 0, 0, 0, 0, 0 };

	int s, m, dice;
	srand(time(NULL));
	cout << "Using rand() function from <stdlib> to generate random dice" << endl;
	for (m = 1; m <= 6000; m++) {
		dice = rand() % 6 + 1;
		if (dice == 1)
			count_a[0]++;
		else if (dice == 2)
			count_a[1]++;
		else if (dice == 3)
			count_a[2]++;
		else if (dice == 4)
			count_a[3]++;
		else if (dice == 5)
			count_a[4]++;
		else
			count_a[5]++;
	}

	for (m = 0; m<6; m++)
		cout << m + 1 << " occured " << count_a[m] << " times" << endl;

	cout << endl << endl;
	cout << "Using good linear congruential algorithm to generate random dice" << endl;
	s = time(NULL);

	for (m = 1; m <= 6000; m++) {
		s = good_LC(s);
		dice = s % 6 + 1;
		if (dice == 1)
			count_b[0]++;
		else if (dice == 2)
			count_b[1]++;
		else if (dice == 3)
			count_b[2]++;
		else if (dice == 4)
			count_b[3]++;
		else if (dice == 5)
			count_b[4]++;
		else
			count_b[5]++;
	}

	for (m = 0; m<6; m++)
		cout << m + 1 << " occured " << count_b[m] << " times" << endl;

	cout << endl << endl;
	cout << "Using bad linear congruential algorithm (bad_LC1) to generate random dice" << endl;
	s = time(NULL);

	for (m = 1; m <= 6000; m++) {
		s = bad_LC1(s);
		dice = s % 6 + 1;
		if (dice == 1)
			count_c[0]++;
		else if (dice == 2)
			count_c[1]++;
		else if (dice == 3)
			count_c[2]++;
		else if (dice == 4)
			count_c[3]++;
		else if (dice == 5)
			count_c[4]++;
		else
			count_c[5]++;
	}

	for (m = 0; m<6; m++)
		cout << m + 1 << " occured " << count_c[m] << " times" << endl;
	cout << endl << endl;

	cout << "Using a bad linear congruential algorithm (bad_LC2) to generate random dice" << endl;
	s = time(NULL);

	for (m = 1; m <= 6000; m++) {
		s = bad_LC2(s);
		dice = s % 6 + 1;
		if (dice == 1)
			count_d[0]++;
		else if (dice == 2)
			count_d[1]++;
		else if (dice == 3)
			count_d[2]++;
		else if (dice == 4)
			count_d[3]++;
		else if (dice == 5)
			count_d[4]++;
		else
			count_d[5]++;
	}

	for (m = 0; m<6; m++)
		cout << m + 1 << " occured " << count_d[m] << " times" << endl;
}

