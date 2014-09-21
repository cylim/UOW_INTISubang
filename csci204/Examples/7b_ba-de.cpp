#include<iostream>
#include<typeinfo>
using namespace std;

class B {
public:
	void f() { }
};
class D: public B {
public:
	void m() { } 
};
int main() {
	B* p = static_cast<B*>( new D );	    // Cast!
	p->m();					    // No B::m ?
}

