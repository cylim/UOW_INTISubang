// accumulate algorithm to compute a product,
// using a function object
#include <iostream>
using namespace std;

class GenericNegate{
public:
	template <class T> T operator() (T t) const {return -t;}
};

int main(){
	GenericNegate negate;
	long long val = 1.012e7;
	cout<< negate(5.3333) << endl;
	cout<< negate(val) << endl; 
} 
