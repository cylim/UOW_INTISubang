#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"
#include "MagazineSubscription.h"
using namespace std;

MagazineSubscription::MagazineSubscription(Person p, Date s, Date e)
 {
   subscriber = p;
   start = s;
   expiration = e;
 }

void MagazineSubscription::showSubscription()
{
  cout<<"Subscriber: ";
  subscriber.showPerson();
  cout<<"The subscription starts on ";
  start.print();
  cout<<"The subscription expires on ";
  expiration.print();
}
