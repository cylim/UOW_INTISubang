#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class test:public exception{
	int id;
	public:
	test(int);
	int getID();
	virtual const char* what() const throw ();
	//virtual ~test() throw() {}
};
test::test(int id):exception(){
	this->id = id;
}
int test::getID(){
	return id;
}
const char* test::what() const throw(){
	return "Day out of range!";
}

void check(int);

int main(){
	int id =9, id2;
	string a = "100";
	stringstream num(a);
	num >> id2;
	try{
		//check(id);
		check(id2);
	}
	catch(exception& e){
		cout << "issue" << endl;
		cout << e.what() << endl;
	}
	cout << "success" << endl;
}

void check(int id){
	if(id == 10){
		test a(id);
		throw a;
	}
}