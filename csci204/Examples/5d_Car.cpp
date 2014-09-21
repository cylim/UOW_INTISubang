#include<iostream>
#include<string>
using namespace std;

// declaration and implementation of a class Car
class Car
{
	private:
		static int count;
	public:
		Car();
		~Car();
};

int Car::count = 0;
Car::Car()
{
	++count;
	cout<<count<<" Car object";
	if(count != 1)
		cout<<"s exist";
	else
		cout<<" exists";
	cout<<endl;
}
Car::~Car()
{
	--count;
	cout<<count<<" Car object";
	if(count != 1)
		cout<<"s exist";
	else
	    cout<<" exists";
	cout<<endl;
}

// test function
int main()
{
    int carCount;
    cout<<"Enter the number of cars to be created: ";
    cin>>carCount;
	// this works for g++, but not for CC
	// Car car[carCount];
	// This works for both CC and g++
	Car *car = new Car[carCount];
	delete [] car;
}

