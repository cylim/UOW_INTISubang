#ifndef _MAGZINESUBSCRIPTION_H_
#define _MAGZINESUBSCRIPTION_H_

#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"
using namespace std;

class MagazineSubscription
 {
   private:
    Person subscriber;
    Date start;
	Date expiration;
   public:
    MagazineSubscription(Person, Date, Date);
    void showSubscription();
 };

#endif
