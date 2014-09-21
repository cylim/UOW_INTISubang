#ifndef _DATE_H_
#define _DATE_H_
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
#endif
