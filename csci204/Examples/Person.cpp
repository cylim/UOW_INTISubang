#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person(string last, string first, string zip)
 {
   lastName = last;
   firstName = first;
   zipCode = zip;
 }

void Person::showPerson()
 {
   cout<<firstName<<" "<<lastName<<" lives in ZIP code "<<zipCode<<endl;
}
