// File Name: main.cpp
// Author: 
// Email Address:
// Project Number: 17.10
// Description: Test driver for the Set template class
// Last Changed: October 14, 2007

#include <string>
#include <iostream>
#include "set.h"
using namespace std;
using namespace setisenhour;

// Function for testing a set with a list of items
template<class T>
void test_set(string msg, T* to_add, int to_add_size, 
    T* to_test, int to_test_size, T* to_remove, int to_remove_size)
{
    Set<T> set;

    cout << msg << endl;

    cout << "Initial size: " << set.size() << endl;

    // Add the items in the to_add list
    for (int i = 0; i < to_add_size; i++) 
    {
	set.add(to_add[i]);
	cout << (i + 1) << ": Added " << to_add[i] << ", size="
	     << set.size() << endl;
    }

    cout << endl;

    // Dump the results of the to_array() function
    T *contents = set.to_array();
    cout << "Contents: " << endl;
    if (contents == NULL)
    {
	cout << "(Set is empty)";
    }
    else
    {
	int sz = set.size();
	for (int i = 0; i < sz; i++)
	{
	    cout << (i + 1) << ": " << contents[i] << endl;
	}
    }

    cout << endl;

    // Test the contains(...) function
    for (int i = 0; i < to_test_size; i++) 
    {
	string contains = "false";
	if (set.contains(to_test[i]))
	{
	    contains = "true";
	}
	cout << (i + 1) << ": Set contains " << to_test[i] << ": "
	     << contains << endl;
    }

    cout << endl;

    // Test the remove(...) function
    for (int i = 0; i < to_remove_size; i++) 
    {
	set.remove(to_add[i]);
	cout << (i + 1) << ": Removed " << to_remove[i] << ", size="
	     << set.size() << endl;
    }

    cout << endl << "Final size: " << set.size() << endl;
    cout << "--------------------------------------------" << endl;
}

int main()
{
   int int_add[] =    { 1, 2, 2, 3, 4, 2, 5, 1, 5 };
   int int_test[] =   { 1, 2, 3, 4, 5, 0 };
   int int_remove[] = { 1, 1, 8, 9, 1, 2, 3, 4, 5, 7 };

    double double_add[] = { 1.75, 3.14, 1.75, 4, 1.68, 4 };
    double double_test[] = { 4, 3.14, 2.57, 1.75, 1.68, 8.3  };
    double double_remove[] = { 4, 3.14, 1.75, 7.23, 1.68, 1.12 };

    string str_add[] = 
	{ "Lionel Hutz", "Hans Moleman", "Lionel Hutz", "Hank Scorpio",
	  "Lyle Lanley", "Edna Krabappel", "Hank Scorpio" };
    string str_test[] = 
	{ "Elizabeth Hoover", "Hans Moleman", "Lionel Hutz", 
  "Gary Chalmers",
	  "Lyle Lanley", "Edna Krabappel", "Hank Scorpio" };
    string str_remove[] = 
	{ "Elizabeth Hoover", "Hans Moleman", "Lionel Hutz", 
  "Gary Chalmers",
	  "Lyle Lanley", "Edna Krabappel", "Hank Scorpio" };

    // Test the Set implementation with ints, doubles, and strings
    test_set("int test:", int_add, 9, int_test, 6, int_remove, 10);
    test_set("double test:", double_add, 6, double_test, 6,
 double_remove, 6);
    test_set("string test:", str_add, 7, str_test, 7, str_remove, 7);

    return 0;
}