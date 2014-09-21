#ifndef __RateTable_SEEN__
#define  __RateTable_SEEN__
///////    RateTable.h    ///////
#include "Rate.h"

class RateTable
{  public:
     RateTable() {}                        // default constructor
     static double rate(char *cur);        // gets rate
     static newRate(char *cur, double r);  // sets rate
     static void display(char *cur);       // display one entry
     static void display();                // display rate table
   private:
     static int lookup(char *cur);         // table lookup
     static Rate table[];				   // Rates are stored in the order of the current names
     static unsigned len;
};

#define RATES   Rate("Britain (Pound)", 0.6967),  \
                Rate("Canada (Dollar)", 1.4728), \
                Rate("Germany (Mark)", 2.0176),  \
                Rate("European (Euro)", 1.0916),   \
                Rate("Japan (Yen)", 106.10),     \
                Rate("Mexico (New Peso)", 9.922),  \
                Rate("Spain (Peseta)", 171.64),  \
                /*      .  .  .             */   \
                Rate("Taiwan (NT $)", 30.74) 
#endif
