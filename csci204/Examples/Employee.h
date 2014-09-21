#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <iostream>
#include "Date.h"
using namespace std;

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
     ~Employee();  	   // provided to confirm destruction order
}; // end class Employee

#endif
