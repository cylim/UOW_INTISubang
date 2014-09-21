// adaptor_stack.cpp

#include <iostream>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main( )
{
   const int num_loads = 5;
   const int palettes[num_loads] = { 7, 6, 2, 5, 10 };
   const string destinations[num_loads] = { string("Houston"), string("Dallas"),
      string("Albuquerque"), string("Phoenix"), string("Los Angeles") };

   // load up the truck
   stack< pair<int,string> > truck;
   cout << "LOADING TRUCK";
   for( int i = 0; i < num_loads; ++i )
   {
      truck.push( make_pair( palettes[i], destinations[i] ) );
      cout << "\nLoaded " << truck.top().first << " palettes for "
         << truck.top().second;
   }

   // make the trip
   cout << "\n\nTRUCK EN ROUTE";
   while( !truck.empty() )
   {
      cout << "\nDelivered " << truck.top().first << " palettes to "
         << truck.top().second;
      truck.pop();
   }
   cout<<endl<<endl;

}

