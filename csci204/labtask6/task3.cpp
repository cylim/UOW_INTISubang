//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Lab task	:6 - 3
//Date		:October 7th, 2014
//This program used typeid function to demonstrate five different data types
#include <iostream>
#include <typeinfo>
using namespace std;
//Class implementation
class Base{};
class Derived: public Base{};
class Base2{ virtual void poly(){} };
class Derived2: public Base2{};

int main(){
	//Testing with primitive C++ types
	cout << "primitive C++ types" << endl;
	int *pointer, integer;
	long longInteger;

	//check if integer pointer and variable is same
	if(typeid(pointer) != typeid(integer)){
		cout << "Pointer and integer are of different types," << endl
			<< "Pointer is: " << typeid(pointer).name() << endl
			<< "Integer is: " << typeid(integer).name() << endl;
	}

	//check whether long is same as float type
	if(typeid(longInteger) != typeid(float)){
		cout << endl << "longInteger is not float type," << endl
			<< "longInteger is: " << typeid(longInteger).name() << endl
			<< "used of (float): " << typeid((float)longInteger).name() << endl;
	}
	//check by default number with '.' is double of float
	if(typeid(1234.56) == typeid(float)){
		cout << "1234.56 is: float" << endl;
	} else if(typeid(1234.56) == typeid(double)){
		cout << "1234.56 is: double" << endl;
	}

	//Testing with programmer-defined types

	//non-polymorphic testing
	cout << endl << "Non-Polymorphic base class," << endl;
	Base* polyBase = new Base;
	Base* polyDerived = new Derived;
    cout << "polyBase is: " << typeid(polyBase).name() << endl;
    cout << "polyDerived is: " << typeid(polyDerived).name() << endl;
    cout << "*polyBase is: " << typeid(*polyBase).name() << endl;
    cout << "*polyDerived is: " << typeid(*polyDerived).name() << endl;

    //polymorphic testing
    cout << endl << "Polymorphic base class," << endl;
	Base2* nonPolyBase = new Base2;
    Base2* nonPolyDerived = new Derived2;
    cout << "nonPolyBase is: " << typeid(nonPolyBase).name() << endl;
    cout << "nonPolyDerived is: " << typeid(nonPolyDerived).name() << endl;
    cout << "*nonPolyBase is: " << typeid(*nonPolyBase).name() << endl;
    cout << "*nonPolyDerived is: " << typeid(*nonPolyDerived).name() << endl;
}