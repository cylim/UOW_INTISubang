///////    RateTable.C    ///////
#include <string.h>
#include "RateTable.h"
using std::endl;

Rate RateTable::table[] = { RATES };

unsigned RateTable::len = sizeof(RateTable::table)/sizeof(Rate);

double RateTable::rate(char *cur)
{     int index = lookup(cur);
      if ( index > -1 )
          return( table[index].getRate() );
      else
          return 0.0;   // no exchange rate
}

int RateTable::newRate(char *cur, double r)
{     int index = lookup(cur);
      if ( index > -1 )
      {   table[index].setRate(r);
          return 0;
      }
      else
          return -1;   // failed
}
   
void RateTable::display(char *cur)
{     int index = lookup(cur);
      if ( index > -1 )
      {   table[index].display();
          cout << endl;
      }
      else
          cout << "Entry " << cur 
               << " not found." << endl;
}

void RateTable::display()
{   cout << "len =" << len << endl;
    for (int i = 0; i < len; i++)
    {  table[i].display();
       cout << endl;
    }
}

// table lookup with binary search
int RateTable::lookup(char *cur)
{     int low = 0, high = len-1, mid, test;
      while (low <= high)
      {   mid = (high + low)/2;
          test = (table[mid].id()).compare(cur);
          if ( test == 0 )
               return mid;
          else if ( test < 0 )
               low = mid + 1;
          else high = mid - 1;
      }
      return -1;   // entry not on rate table
}

