#include <iostream>

using namespace std;

class A {
public:
	void m(int a) { cout<<"A::m(int)-argument="<<a<<endl;}
};

class Z: public A {
public:
	// void m(int a) { cout<<"Z::m(int)-argument="<<a<<endl;}
	void m() {cout<<"Z::m()-without argument"<<endl;}
};

int main()
{
	Z z1;

	//z1.m(999);
	z1.A::m(999);
	z1.m();

	return 0;
}

