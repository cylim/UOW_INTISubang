#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
using namespace std;

class Person
{
  private:
    string lastName;
    string firstName;
    string zipCode;
  public:
    Person(string = "X", string = "X", string = "X");
    void showPerson();
};

#endif
