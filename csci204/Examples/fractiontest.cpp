#include "fraction.h"

int main()
{
   // Test constructors
   Fraction a; // Value is 0/1
   Fraction b(4); // Value is 4/1
   Fraction c(6,8); // Value is 6/8, which is converted to 3/4
   cout << "Constructed values " << a << " " << b << " " << c << "\n";
   Fraction d(c); // Value is copy of c, also 3/4
   cout << "Value of d is " << d.numerator() << "/"
      << d.denominator() << "\n";
   // Test arithmetic instructions
   d = b + c;
   cout << "4 + 3/4 is " << d << "\n";
   d = b - c;
   cout << "4 - 3/4 is " << d << "\n";
   Fraction e = (b + (-c));
   cout << e << "Done with negation\n";
   if (d == e)
      cout << "Subtraction test successful\n";
   else
      cout << "Subtraction test failed\n";
   a = Fraction(6,8);
   b = Fraction(7,8);
   if (a < b)
      cout << "Compare successful\n";
   return 0;
}
