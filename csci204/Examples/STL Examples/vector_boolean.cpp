#include <vector>

#include "tips.hpp"

using namespace std;

int main( )
{
   vector<bool> shots( 5 ); // true if pet has shot
   tips::print( shots, "Initial pets with shots" );

   // give shots to two pets
   shots[1] = true;
   shots[4].flip();
   tips::print( shots, "Subsequent pets with shots" );

   // delete the first element because that pet was adopted
   shots.erase( shots.begin() );
   tips::print( shots, "After adoption, pets with shots" );

   // flip bits to show pets needing shots
   shots.flip();
   tips::print( shots, "Pets needing shots" );
}
