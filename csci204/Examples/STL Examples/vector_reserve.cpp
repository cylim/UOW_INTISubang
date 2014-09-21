// vector_reserve.cpp

#include <vector>

using namespace std;

int main( )
{
   // fill a vector with one million numbers the slow way
   vector<int> v1;
   for( int i = 0; i < 1000000; ++i )
      v1.push_back( i );

   // fill a vector with one million numbers the fast way
   vector<int> v2;         // has zero elements
   v2.reserve( 1000000 );  // still has zero elements
   for( int i = 0; i < 1000000; ++i )
      v2.push_back( i );
}

