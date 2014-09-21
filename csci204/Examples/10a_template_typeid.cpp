// Using typeid with templates.
#include <iostream>
using namespace std;
template <class T> class myclass {
  T a;
public:
  myclass(T i) { a = i; }
  // ...
};
int main()
{
  myclass<int> o1(10), o2(9);
  myclass<double> o3(7.2);

  cout << "Type of o1 is ";
  cout << typeid(o1).name() << endl;
  cout << "Type of o2 is ";
  cout << typeid(o2).name() << endl;
  cout << "Type of o3 is ";
  cout << typeid(o3).name() << endl;
  cout << endl;
  if(typeid(o1) == typeid(o2)) 
    cout << "o1 and o2 are the same type\n";
  if(typeid(o1) == typeid(o3))
    cout << "Error\n";
  else
    cout << "o1 and o3 are different types\n";
  return 0;
}

