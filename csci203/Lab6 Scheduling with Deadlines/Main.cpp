#include <iostream>
#include "Scheduler.h"
using namespace std;

int main ()
{
	Scheduler mySchedule;
	mySchedule.Input ();
	mySchedule.Schedule ();
	mySchedule.Display ();

	return 0;
}
