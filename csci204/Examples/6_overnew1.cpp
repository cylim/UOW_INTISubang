#include<iostream>
#include<cstring>
using namespace std;

class Thing{
private:
  int value;
public:
  void* operator new[](size_t index, size_t extra);
  void show(){cout << "Value is " << value << endl;}
};

void *Thing::operator new[](size_t size, size_t extra){
  size_t n = size / sizeof(Thing);
  Thing *op = ::new Thing[n];
  for (size_t idx = 0; idx < n; idx++)
    op[idx].value = extra+idx;
  return op;
}

int main()
{
  Thing *op = new(10) Thing[5];
  for (int i=0; i<5; i++)
    op[i].show();
}

