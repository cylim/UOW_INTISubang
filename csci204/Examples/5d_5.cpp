#include<iostream>
using namespace std;
class TestClass
{
   private:
    int field;
   public:
    TestClass();
};
TestClass::TestClass()
 {
  cout<<"Constructing"<<endl;
 }
int main()
{
  TestClass a[10];
}
