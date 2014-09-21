// vector_checked.cpp

#include <iostream>
#include <vector>

using namespace std;

// comment next line out when debugging
#define NDEBUG

class Ship
{
   public:
   Ship( const float cargo_weight[], int length );

   float operator[]( int index ) const;
   // REQUIRE: 0 <= index < cargo_loads()
   // RETURN: weight of load with specified index

   int cargo_loads() const;

   private:
   vector<float> weight_;
};

inline
Ship::Ship( const float weight[], int length )
   : weight_( weight, weight+length )
{} // empty

inline
float Ship::operator[]( int index ) const
{
#ifdef NDEBUG
   return weight_[index]; // don't check range when not debugging
#else
   return weight_.at( index ); // check range when debugging
#endif
}

inline
int Ship::cargo_loads() const
{ return static_cast<int>( weight_.size() ); }

int main( )
{
   const int num_loads = 3;
   const float weights[num_loads] = { 40.8f, 35.2f, 22.1f };

   // make a ship and load it with cargo
   Ship ship( weights, num_loads );

   // BAD LOOP - off-by-one error
   for( int i = 0; i <= ship.cargo_loads(); ++i )
      cout << "Cargo load " << i << " weighs "
         << ship[i] << " metric tons\n";
}

