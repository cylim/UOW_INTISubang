#include<iostream>
using namespace std;

struct Test
{ 
	float	value;
	
	void outValue(){cout << value << " ::: " << endl;}
};

int main(){
	Test thing;
	thing.value=20;

	cout << thing.value<< endl;
	thing.outValue();
}
