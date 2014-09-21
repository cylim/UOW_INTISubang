#include<iostream>
using namespace std;

class X{
        ~X();
};

class Y : public X{
};

int main()
{
        Y y;
}
