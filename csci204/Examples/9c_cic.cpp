#include <iostream>
using namespace std;

class A{
private:
  int a;
  class B{
  private:
    int b;
  public:
    B(int bb){b=bb;}
  };
public:
  A(int aa){a=aa;}
 class C{
  private:
    int c;
  public:
   C(int cc){c=cc;}
  };
};

int main()
{
  A a1(4);
  //  B b1(3);
  //  C c1(5);
  A::C c2(6);
}
