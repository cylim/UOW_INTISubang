// list_front_back.cpp

#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main( )
{
   const char* name_data[] = { "Cindy Winkelman", "Ann Smith",
      "Joe Johnston", "Edward Koppelman", "Janice Weitz",
      "Gail Hickford", "Candy Kauffman" };
   const bool girl_data[] = { true, true, false, false, true,
      true, true };
   const int num_graduates = sizeof( girl_data )
      / sizeof( girl_data[0] );

   list< pair< string, bool > > graduate;
   // first - person's name     second - true if girl, false if boy

   // list of graduates - girls in front, boys in back
   for( int i = 0; i < num_graduates; ++i )
      if( girl_data[i] )
         graduate.push_front(
            make_pair( string(name_data[i]), girl_data[i] ) );
      else
         graduate.push_back(
            make_pair( string(name_data[i]), girl_data[i] ) );

   // march in the graduates in boy-girl pairs
   cout << "LADIES AND GENTLEMEN, THE GRADUATES ARE\n";
   while( !graduate.empty() )
   {
      cout << graduate.front().first;
      graduate.pop_front();
      if( !graduate.empty() )
      {
        cout << " and " << graduate.back().first;
        graduate.pop_back();
      }
      cout << endl;
   }
}
