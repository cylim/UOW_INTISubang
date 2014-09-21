#include <iostream>
#include "Time.h"
using namespace std;

// operator overloading through normal function overloading
int operator-(const Time& a, const Time& b)
{
	return a.seconds_from(b);
}

int main()
{  
   Time now, morning(9,0,0);
   int seconds_elapsed = now - morning;
   cout<<"Second_Elapsed from 9:00am is "<<seconds_elapsed<<endl;
   return 0;
}
