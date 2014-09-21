// list_unique.cpp

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <utility>

using namespace std;

void print_message( const pair<int,string>& message );

int main( )
{
   list< pair< int, string > > message;
   list< pair< int, string > >::iterator ip;

   message.push_back( make_pair( 40449, string("Shift key down")) );
   message.push_back( make_pair( 40443, string("Mouse key down")) );
   message.push_back( make_pair( 40443, string("Mouse key down")) );
   message.push_back( make_pair( 40444, string("Mouse key up" )) );
   message.push_back( make_pair( 40448, string("Mouse move" )));
   message.push_back( make_pair( 40443, string("Mouse key down")) );

   cout << "ORIGINAL MESSAGES" << endl;
   ip = message.begin();
   while(ip!=message.end()) {
	   print_message(*ip);
	   ip++;
   }

   message.unique();
   cout << "\nSEQUENTIAL DUPLICATES REMOVED" << endl;
   ip = message.begin();
   while(ip!=message.end()) {
	   print_message(*ip);
	   ip++;
   }

   message.sort();
   message.unique();
   cout << "\nALL DUPLICATES REMOVED" << endl;
   for_each( message.begin(), message.end(), print_message );
}

void print_message( const pair<int,string>& message )
{
   cout << message.first << " - " << message.second << endl;
}
