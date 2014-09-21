#include<iostream>
using namespace std;
class House
{
   private:
      int squareFeet;
   public:
       House();
      ~House();
};
House::House()
{
   squareFeet = 1000;
   cout<<"House created."<<endl;
   cout << this << endl;
}
House::~House()
{
   cout<<"House destroyed!"<<endl;
   cout<< this << endl;
}
int main()
{
   House aHouse[6];
   cout << "End of program" << endl;
}
