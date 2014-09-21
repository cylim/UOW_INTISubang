#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

int main()
{
   Employee one( "Bob", "Jones", 7, 24, 1949, 3, 12, 1988 );

   cout << '\n';
   one.print();

   cout << "\nTest Date constructor with invalid values:\n";
   Date d( 14, 35, 1994 );  // invalid Date values
   cout << endl;
  
   return 0;
} // end function main
