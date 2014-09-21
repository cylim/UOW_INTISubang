#include<iostream>
using namespace std;

class Singleton{
public:
  static Singleton* Instance();
  static void Show(){cout << instance << endl;}
  static void TidyUp();
protected:
  Singleton(){};
private:
  static Singleton* instance;
};

Singleton* Singleton::instance = 0;
Singleton* Singleton::Instance(){
  if ( instance == 0 )
    instance = new Singleton;
  return instance;
}
void Singleton::TidyUp(){
  delete instance;
  instance=0;
}

int main()
{
  Singleton::Show();
  Singleton *eg = Singleton::Instance();
  eg->Show();
  eg->TidyUp();
  delete eg;  
  Singleton::Show();
}
