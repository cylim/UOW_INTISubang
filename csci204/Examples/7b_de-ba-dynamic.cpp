#include<iostream>
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
  D* p = dynamic_cast<D*> ( new B);
  cout << p << endl;
  p->m();

  cout << typeid(p).name() << endl;
 cout << typeid(*p).name() << endl;
//    if (p)
//   {
//     p->m();
//   }
// else
//    cout << "Unsafe for p to point to a B" << endl;
}
