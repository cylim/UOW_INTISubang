class B{
  // ...
};

class D: public B{
  // ...
};

int main()
{
  D* p;                       // Pointer to derived class.
  p = new B;                   // ERROR
}
