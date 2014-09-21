// vector_shrink.cpp

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main( )
{
   // make a big vector and then deallocate all its memory
   const int big_size = 10000;
   vector<double> v( big_size );
   cout << "Before clearing, the capacity of the vector is "
      << v.capacity() << " and its size is " << v.size();
   v.clear();
   cout << "\nAfter clearing, the capacity of the vector is "
      << v.capacity() << " and its size is " << v.size();
   vector<double>().swap( v );

   /* if the above line doesn't compile use this code
   {
      vector<double> temporary;
      temporary.swap( v );
   } */

   cout << "\nAfter swapping, the capacity of the vector is "
      << v.capacity() << " and its size is " << v.size();

   // make a big vector and then minimize its memory
   v.assign( big_size, 3.33 );
   cout << "\n\nBefore resizing, the capacity of the vector is "
      << v.capacity() << " and its size is " << v.size();
   v.resize( 1 );
   cout << "\nAfter resizing, the capacity of the vector is "
      << v.capacity() << " and its size is " << v.size();
   vector<double>( v ).swap( v );

   /* if the above line doesn't compile use this code
   {
      vector<double> temporary( v );
      temporary.swap( v );
   } */

   cout << "\nAfter swapping, the capacity of the vector is "
      << v.capacity() << " and its size is " << v.size();
}

