// list_sort.cpp

#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

class Player
{
   public:
   Player( const string& first_name = "John",
      const string& last_name = "Doe", int height = 60,
      float field_goal_percentage = 10 ); // height in inches
   bool operator<( const Player& rhs ) const;

   float field_goal_percentage() const;
   string first_name() const;
   int height() const;  // in inches
   void height( int& feet, int& inches ) const;
   string last_name() const;
   void print() const;

   private:
   float field_goal_percentage_;
   string first_name_;
   int height_;   // in inches
   string last_name_;
};

inline
Player::Player( const string& first_name, const string& last_name,
   int height, float field_goal_percentage )
   : field_goal_percentage_( field_goal_percentage ),
     first_name_( first_name ), height_( height ),
     last_name_( last_name )
{} // empty

inline
float Player::field_goal_percentage() const
{  return field_goal_percentage_; }

inline
string Player::first_name() const
{  return first_name_; }

inline
int Player::height() const  // in inches
{  return height_; }

inline
void Player::height( int& feet, int& inches ) const
{
   feet = height() / 12;
   inches = height() % 12;
}

inline
string Player::last_name() const
{  return last_name_; }

void Player::print() const
{
   int feet, inches;
   height( feet, inches );
   string name( first_name() );
   name += " ";
   name += last_name();
   cout << setw( 20 ) << left << name << feet << " feet " << inches
      << " inches   Field goal percentage: "
      << field_goal_percentage() << endl;
}

inline
bool Player::operator<( const Player& rhs ) const
{ return last_name() < rhs.last_name(); }


int main( )
{
   list<Player> players;
   list<Player>::iterator ip;

   // statistics for 2003-2004 season
   players.push_back( Player( "Kobe", "Bryant", 78, 0.422 ) );
   players.push_back( Player( "Allen", "Iverson", 72, 0.392 ) );
   players.push_back( Player( "Shaquille", "O'Neal", 85, 0.555 ) );
   players.push_back( Player( "Yao", "Ming", 90, 0.531 ) );
   players.push_back( Player( "Tim", "Duncan", 84, 0.502) );

   // sort by name
   cout << "PLAYERS BY LAST NAME\n";
   players.sort();
   ip = players.begin();
   while(ip != players.end()) {
	   ip->print();
	   ip++;
   }

   // descending sort by height
   

   // descending sort by field goal percentage
  
}

