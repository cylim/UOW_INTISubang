#include<iostream>
#include<typeinfo>
using namespace std;

class B{
public:
  virtual void f(){}
  void m(){cout << "Base" << endl;}
};

class D: public B{
public:
  void m(){cout << "Derived" << endl;}
};

int main()
{
  D* p = static_cast<D*> ( new B);
  cout << p << endl;
  p->m();
  (*p).m();
  cout << typeid(p).name() << endl;
  cout << typeid(*p).name() << endl;
}
