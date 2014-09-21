#include<iostream>
using namespace std;

template <class T>
T reverse (T x)
{
	return (-x);
}

int main()
{
	char x='0';
	char y='Ğ';
	string z="abc";	

	cout << static_cast<int>(x) << endl;
	cout << -x << endl;
	cout << reverse(x) << endl;
	cout << y << endl;
	cout << static_cast<int>(y) << endl;
	cout << reverse(z) << endl;
}
