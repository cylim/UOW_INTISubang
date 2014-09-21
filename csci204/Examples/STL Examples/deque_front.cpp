// deque_front.cpp

#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Auction_item
{
   public:
   Auction_item( const string& name = "nothing",
      int minimum_bid = 0 );
   int minimum_bid() const;
   string name() const;

   private:
   int minimum_bid_;
   string name_;
};

inline
Auction_item::Auction_item( const string& name, int minimum_bid )
   : name_( name ), minimum_bid_( minimum_bid )
{} // empty

inline
int Auction_item::minimum_bid() const
{  return minimum_bid_; }

inline
string Auction_item::name() const
{  return name_; }

int main( )
{
   vector<Auction_item> v( 5 );
   v[0] = Auction_item( "dinner for two", 150 );
   v[1] = Auction_item( "1000 piece jigsaw puzzle", 10 );
   v[2] = Auction_item( "25-year old bottle of wine", 75 );
   v[3] = Auction_item( "night of babysitting", 20 );
   v[4] = Auction_item( "limousine ride", 100 );

   deque<Auction_item> items;

   // load auction items with cheap ones in front, expensive at back
   const int min_expensive_item = 50;
   for( vector<Auction_item>::iterator i = v.begin();
      i != v.end(); ++i )
      if( i->minimum_bid() >= min_expensive_item )
         items.push_back( *i );
      else
         items.push_front( *i );

   // sell the items
   bool sell_cheap = true;
   while( !items.empty() )
   {
      if( sell_cheap )
      {
         cout << "Now selling: a " << items.front().name()
            << " for a minimum bid of "
            << items.front().minimum_bid() << endl;
         items.pop_front();
      }
      else
      {
         cout << "Now selling: a " << items.back().name()
            << " for a minimum bid of "
            << items.back().minimum_bid() << endl;
         items.pop_back();
      }

      // Alternate selling cheap and expensive
      sell_cheap = !sell_cheap;
   }
}

