#include <iostream>
using namespace std;

class ShippingContainer{
	int ID;
	static int autoID;
public:
	//Constructor and destructor declaration
	ShippingContainer(int = 0);
	~ShippingContainer();
	inline void setID(int ID){ this->ID = ID; }
	inline int getID(){ return ID; }
	//Accessor declaration and implementation
	virtual string getManifest(){ return " "; }
};
class ManualShippingContainer: public ShippingContainer{
	string manifest;
public:
	//Constructor and destructor declaration
	ManualShippingContainer();
	~ManualShippingContainer();
	//Mutator declaration and implementation
	inline void setManifest(string manifest){ this->manifest = manifest; }
	//Accessor declaration and implementation
	string getManifest(){ return manifest; }
};
class RFIDShippingContainer: public ShippingContainer{
	string manifest;
	string item[10];
	int itemCount[10];
	int total;
public:
	//Constructor and destructor declaration
	RFIDShippingContainer();
	~RFIDShippingContainer();
	//Mutator declaration
	void add(string);
	//Accessor declaration
	string getManifest();
};