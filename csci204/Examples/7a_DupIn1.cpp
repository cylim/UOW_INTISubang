#include<iostream>
using namespace std;

class X{
private:
  int x;
public:
  X(int xx){x=xx;}
  void showX(){cout << "x = " << x << endl;};
};

class U : public X{
private:
  int u;
public:
  U(int xx,int uu):X(xx){u=uu;}
  void showU(){showX();cout << "u = " << u << endl;};
};

class V : public X{
private:
  int v;
public:
  V(int xx,int vv):X(xx){v=vv;}
  void showV(){showX();cout << "v = " << v << endl;};
};

class W : public U, public V{
private:
  int w;
public:
  W(int,int,int,int);
  void showW(){showU();showV();cout << "w = " << w << endl;};
};

W::W(int xx, int uu, int vv , int ww):U(xx,uu),V(xx+10,vv){w=ww;}

main()
{
  W w(1,2,3,4);
  w.showW();
}
