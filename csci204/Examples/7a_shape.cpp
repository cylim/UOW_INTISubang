#include<iostream>
using namespace std;

class Shape {
public:
   virtual void draw() const = 0;
};

class Point : public Shape {
public:
   Point( int a= 0, int b = 0 ) {x=a; y=b;}  // default constructor
   int getx() const {return x;}
   int gety() const {return y;}
   virtual void draw() const {cout<<"draw point ("<<x<<","<<y<<")\n";}
private:
   int x, y;   // x and y coordinates of Point
};

class Circle : public Point {
public:
   // default constructor
   Circle( double r = 0.0, int x = 0, int y = 0 ):Point(x,y) {
        radius=r;}
   virtual void draw() const {cout<<"draw 	circle("<<getx()<<","<<gety()<<","<<radius<<")\n";}
private:
   double radius;   // radius of Circle
};

int main()
{
//   Shape shape;			     // Error!!
   Point point( 7, 11 );                  // create a Point
   Circle circle( 3.5, 22, 8 );           // create a Circle

   point.draw();			// static binding
   circle.draw();			// static binding

   Shape *arrayOfShapes[2];

//   arrayOfShapes[0] = &shape;
   arrayOfShapes[0] = &point;
   arrayOfShapes[1] = &circle;

   for(int i=0; i<2; ++i)
    arrayOfShapes[i]->draw();		// dynamic binding

   return 0;
}
