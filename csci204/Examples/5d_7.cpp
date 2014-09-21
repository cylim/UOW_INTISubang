#include <iostream>
#include <string>
#include "Person.h"
#include "Date.h"
#include "MagazineSubscription.h"

int main()
{
  Person person("Martin","Emily","60097");
  Date startDate(6, 24, 2006);
  Date endDate(6, 23, 2008);
  MagazineSubscription mag(person, startDate, endDate);
  mag.showSubscription();
}
