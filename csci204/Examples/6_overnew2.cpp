#include<iostream>
#include<cstring>
using namespace std;

class Thing{
private:
  int value;
public:
  void* operator new[](size_t index, size_t extra);
  void* operator new(size_t index, int val);
  void* operator new(size_t index, int val, int extra);
  void show(){cout << "Value is " << value << endl;}
};

void *Thing::operator new[](size_t size, size_t extra){
  size_t n = size / sizeof(Thing);
  Thing *op = ::new Thing[n];
  for (size_t idx = 0; idx < n; idx++)
    op[idx].value = extra+idx;
  return op;
}

void *Thing::operator new(size_t size, int val){
	Thing *op = ::new Thing;
	op->value = val;
	return op;
}

void *Thing::operator new(size_t size, int val, int extra){
	Thing *op = ::new Thing;
	op->value = val*extra;
	return op;
}

int main()
{
  Thing *op = new(10) Thing[5];
  for (int i=0; i<5; i++)
    op[i].show();

  Thing *ap = new(50) Thing;
  ap->show();

  Thing *bp = new(50, 100) Thing;
  bp->show();
}
