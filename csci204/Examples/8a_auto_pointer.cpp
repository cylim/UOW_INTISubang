#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::auto_ptr;
class Integer {
	public:
    Integer( int i = 0 ) : value( i ) 
 	         { cout << "Constructor for Integer " 
                   << value << endl; } 
   ~Integer()  
      	{ cout << "Destructor for Integer " 
                   << value << endl; } 
   void setInteger( int i ) { value = i; }
   int getInteger() const { return value; }
private:
   int value;
};

int main()
{
   cout << "Creating an auto_ptr object that points "
       << "to an Integer\n";

   auto_ptr< Integer > ptrToInteger( new Integer(7) );

   cout << "Using the auto_ptr to manipulate the Integer\n";

   ptrToInteger->setInteger( 99 ); 
 
   cout << "Integer after setInteger: " 
        << ( *ptrToInteger ).getInteger()
        << "\nTerminating program" << endl;
   // no delete [] here
   return 0;
}

