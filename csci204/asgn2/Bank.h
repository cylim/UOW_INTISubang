#include <iostream>
using namespace std;

class BankAccount{
	//insertion operator overload
	friend ostream& operator<<(ostream&, const BankAccount&);
private:
	int ID;
	double balance;
	static int accountNumber;
public:
	BankAccount(int = 0, double=100);
	//Mutator declaration and implementation
	inline void setID(int ID) { this->ID = ID; }
	inline void setBalance(double balance) { this->balance = balance; }
	//Accessor declaration and implementation
	inline int getID(){ return ID; }
	inline double getBalance(){ return balance; }
	//Operator declaration and implementation
	inline void operator+=(double amount){ balance += amount; } //add two amount together
	void operator-=(double); //withdraw, implementation at below,
	inline bool operator<(BankAccount& a){ return balance < a.balance; } //if balance greater than a.balance, return true
	inline bool operator>(BankAccount& a){ return balance > a.balance; } //if balance smaller than a.balance, return true
	inline bool operator==(BankAccount& a){ return ID == a.ID; } //if two ID are same, return true
};