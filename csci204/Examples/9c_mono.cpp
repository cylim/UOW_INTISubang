#include<iostream>
using namespace std;

class Admin;	// Forward referencing!

class Weather{
friend class Admin;
private:
 static int max_temp; // Temperatures are in Celsius
 static int min_temp; 
 static int current_temp;  
public:
 int get_max_temp() const { return max_temp;}
 int get_min_temp() const { return min_temp;}
 int get_current_temp() const { return current_temp;}
};

int Weather::max_temp=23;
int Weather::min_temp=6;
int Weather::current_temp=15;

class Admin{
private:
  Admin(){} // Blocking object initialisation.
  bool permit;
public:
  Admin(const string &password); //authentication.
  void set_min_temp(int);
  void set_max_temp(int);
  void set_current_temp(int);
};

Admin::Admin(const string &password)
{
  if (password == "mypassword")
    {
      cout << "Correct password." << endl;
      permit=true;
    }
  else
      cout << "Incorrect password." << endl;
}

void Admin::set_min_temp(int min){
  if ( permit )
    Weather::min_temp = min;
}

void Admin::set_max_temp(int max){
  if ( permit )
    Weather::max_temp = max;
}

void Admin::set_current_temp(int temp){
  if ( permit )
    Weather::current_temp = temp;
}

int main()
{
  Weather weather1, weather2;
  
  cout << weather1.get_current_temp() << endl;
  cout << weather2.get_current_temp() << endl;
  
  //  Admin admin0; // Not allowed to do this.
  {
    Admin admin("mypassword");
    admin.set_current_temp(16);
  }
  
  cout << weather1.get_current_temp() << endl;
  cout << weather2.get_current_temp() << endl;

  Admin admin("mypasswd");
  admin.set_current_temp(24);
 
  cout << weather1.get_current_temp() << endl;
  cout << weather2.get_current_temp() << endl;
}
