#ifndef __Rate_SEEN__
#define  __Rate_SEEN__
///////    Rate.h    ///////
#include <iostream> 
#include <string> 
using std::cout;
using std::string;

class Rate
{  public:
      Rate(const char* name = "",        // currency name
           double r = 0.0)               // exchange rate
      : cur(string(name)), amt(r) { }   
      double getRate() { return amt; }   // retrieve rate
      void setRate(double r) { amt = r; }// set rate
      const string& id() { return cur; } // retrieve currency name
      void display()
      { cout << amt << "\t\t" << cur; } 
   private:
      const string cur;    // currency name
      double amt;          // exchange rate
};
#endif
