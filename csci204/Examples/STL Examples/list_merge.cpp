// list_merge.cpp

#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <functional>

using namespace std;

class Salesperson
{
   public:
   Salesperson( const string& name = "", int sales = 0,
      int district = 0 );
   // name - salesperson's last name
   // sales - >= 0, last year's sales in dollars
   // district - district number

   bool operator>( const Salesperson& rhs ) const;
   // true is sales of *this is > than rhs.sales(), else false

   bool operator<( const Salesperson& rhs ) const;
   // true is sales of *this is < than rhs.sales(), else false

   void print() const;
   // print info on salesperson

   private:
   int district_;
   string name_;
   int sales_;
};

inline
Salesperson::Salesperson( const string& name, int sales,
   int district )
   : district_( district ), name_( name ), sales_( sales )
{} // empty

inline
bool Salesperson::operator>( const Salesperson& rhs ) const
{ return sales_ > rhs.sales_; }

inline
bool Salesperson::operator<( const Salesperson& rhs ) const
{ return sales_ < rhs.sales_; }

inline
void Salesperson::print() const
{ cout << name_ << " from District " << district_
   << " has sales of $" << sales_ << endl;
}

int main( )
{
   list<Salesperson>::iterator ip;
   list<Salesperson> list1;
   list1.push_back( Salesperson( string("Gutierrez"), 37000, 1 ) );
   list1.push_back( Salesperson( string("Gonzalez"), 49000, 1 ) );
   list1.push_back( Salesperson( string("Ochoa"), 48500, 1 ) );

   // sort District 1 salespeople in descending order and display
   //list1.
   list1.sort(greater<Salesperson>());
   // list1.sort();
   cout << "Top three salespeople for District 1\n";
   ip = list1.begin();
   while(ip != list1.end()) {
	   ip->print();
	   ip++;
   }

   list<Salesperson> list2;
   list2.push_back( Salesperson( string("Yashimoto"), 65000, 2 ) );
   list2.push_back( Salesperson( string("de la Cruz"), 33000, 2 ) );
   list2.push_back( Salesperson( string("Duke"), 47000, 2 ) );

   // sort District 2 salespeople in descending order and display
   list2.sort( greater<Salesperson>() );
   cout << "\nTop three salespeople for District 2\n";
   ip = list2.begin();
   while(ip != list2.end()) {
	   ip->print();
	   ip++;
   }

   list<Salesperson> list3;
   list3.push_back( Salesperson( string("White"), 30000, 3 ) );
   list3.push_back( Salesperson( string("Kline"), 44000, 3 ) );
   list3.push_back( Salesperson( string("Bradley"), 42500, 3 ) );

   // sort District 3 salespeople in descending order and display
   list3.sort( greater<Salesperson>() );
   cout << "\nTop three salespeople for District 3\n";
   ip = list3.begin();
   while(ip != list3.end()) {
	   ip->print();
	   ip++;
   }

   list<Salesperson> list4;
   list4.push_back( Salesperson( string("Smith"), 51000, 4 ) );
   list4.push_back( Salesperson( string("Kleinenberg"), 33000, 4 ) );
   list4.push_back( Salesperson( string("Schwartz"), 44000, 4 ) );

   // sort District 4 salespeople in descending order and display
   list4.sort( greater<Salesperson>() );
   cout << "\nTop three salespeople for District 4\n";
   ip = list4.begin();
   while(ip != list4.end()) {
	   ip->print();
	   ip++;
   }


   // merge Districts 1 and 2 into Western Region
   list1.merge( list2, greater<Salesperson>() );

   // keep only the top 3 salespeople
   const int top_positions = 3;
   list<Salesperson>::iterator position = list1.begin();
   advance( position, top_positions );
   list1.erase( position, list1.end() );

   cout << "\nTop three salespeople for Western Region "
      << "(Districts 1 and 2 )\n";
   ip = list1.begin();
   while(ip != list1.end()) {
	   ip->print();
	   ip++;
   }

   // merge Districts 3 and 4 into Eastern Region
   list3.merge( list4, greater<Salesperson>() );

   // keep only the top 3 salespeople
   position = list3.begin();
   advance( position, top_positions );
   list3.erase( position, list3.end() );

   cout << "\nTop three salespeople for Eastern Region "
      << "(Districts 3 and 4)\n";
   for_each( list3.begin(), list3.end(),
      mem_fun_ref( &Salesperson::print ) );

   // merge two regions into whole country
   list1.merge( list3, greater<Salesperson>() );

   // keep only the top 3 salespeople
   position = list1.begin();
   advance( position, top_positions );
   list1.erase( position, list1.end() );

   cout << "\nTop three salespeople in the country\n";
   ip = list1.begin();
   while(ip != list1.end()) {
	   ip->print();
	   ip++;
   }
}
