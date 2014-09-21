#include <iostream>
using namespace std;

class Date
{
  private:
     int month;  		// 1-12
     int day;    		// 1-31 based on month
     int year;   		// any year
     // utility function to test proper day for month and year.
     int checkDay( int );
  public:
     Date( int = 1, int = 1, int = 1900 ); // default constructor
     void print() const;  // print date in month/day/year format
     ~Date();  	   // provided to confirm destruction order
}; // end class Date

// Constructor: Confirm proper value for month;
// call utility function checkDay to confirm proper
// value for day.
Date::Date( int mn, int dy, int yr )
{
   if ( mn > 0 && mn <= 12 )       // validate the month
      month = mn;
   else {
      month = 1;
      cout << "Month " << mn << " invalid. Set to month 1.\n";
   } // end else

   year = yr;                      // should really validate yr
   day = checkDay( dy );           // validate the day

   cout << "Date object constructor for date ";
   print();         // interesting: a print with no arguments
   cout << endl;
} // end Date constructor

// Print Date object in form  month/day/year
void Date::print() const
   { cout << month << '/' << day << '/' << year; }

// Destructor: provided to confirm destruction order
Date::~Date()
{ 
   cout << "Date object destructor for date ";
   print();
   cout << endl;
} // end Date destructor

// Utility function to confirm proper day value
// based on month and year.
int Date::checkDay( int testDay )
{
   static const int daysPerMonth[ 13 ] = 
      {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   if ( month == 2 &&      // February: Check for leap year
        testDay == 29 &&
        ( year % 400 == 0 ||                      
         ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

   cout << "Day " << testDay << " invalid. Set to day 1.\n";

   return 1;  // leave object in consistent state if bad value
} // end function checkDay


class Employee
{
  private:
     char firstName[ 25 ];
     char lastName[ 25 ];
     const Date birthDate;
     const Date hireDate;
  public:
     Employee( char *, char *, int, int, int, int, int, int );
     void print() const;
     ~Employee();  // provided to confirm destruction order
}; // end class Employee

Employee::Employee( char *fname, char *lname,
                    int bmonth, int bday, int byear,
                    int hmonth, int hday, int hyear )
   : birthDate( bmonth, bday, byear ), 
     hireDate( hmonth, hday, hyear )
{
   // copy fname into firstName and be sure that it fits
   int length = strlen( fname );
   length = ( length < 25 ? length : 24 );
   strncpy( firstName, fname, length );
   firstName[ length ] = '\0';

   // copy lname into lastName and be sure that it fits
   length = strlen( lname );
   length = ( length < 25 ? length : 24 );
   strncpy( lastName, lname, length );
   lastName[ length ] = '\0';

   cout << "Employee object constructor: "
        << firstName << ' ' << lastName << endl;
} // end Employee constructor

void Employee::print() const
{
   cout << lastName << ", " << firstName << "\nHired: ";
   hireDate.print();
   cout << "  Birth date: ";
   birthDate.print();
   cout << endl;
} // end function print

// Destructor: provided to confirm destruction order
Employee::~Employee()
{ 
   cout << "Employee object destructor: " 
        << lastName << ", " << firstName << endl;
} // end Employee destructor

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
