#include<iostream>
using namespace std;

class X
{
private:
  int x;
public:
  X(int xx){x=xx;}
  X(){}
  void showX(){cout << "x = " << x << endl;};
};

class U : virtual public X
{
private:
  int u;
public:
  U(int uu, int xx):X(xx){u=uu;}
  void showU(){showX();cout << "u = " << u << endl;};
};

class V : virtual public X
{
private:
  int v;
public:
  V(int vv, int xx):X(xx){v=vv;}
  void showV(){showX();cout << "v = " << v << endl;};
};

class W : virtual public U, virtual public V
{
private:
  int w;
public:
  W(int,int,int,int);
  void showW(){showU();showV();cout << "w = " << w << endl;};
};

W::W(int xx, int uu, int vv, int ww):U(uu, 7),V(vv, 8){w=ww;}

main()
{
  W w(1,2,3,14);
  w.showW();
}
