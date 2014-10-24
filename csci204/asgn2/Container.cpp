#include <sstream>  
#include "Container.h"

//Class implementation
//Class Container
//Container accessor and mutator is implemented in Container.h
//Initialize static member of class ShippingContainer
int ShippingContainer::autoID = 9110;
//constructor implementation, by default, ID is 9110
ShippingContainer::ShippingContainer(int ID){
	//if the 0, set the ID to autoID, and autoID will automatically increase by 1
	if(ID == 0){
		this->ID = autoID;
		autoID += 1;
	} else {
		//if ID is any ID, set it to class ID
		this->ID = ID;
	}
}
//destructor implementation
ShippingContainer::~ShippingContainer(){
	cout << "Container ID: " << ID << endl;
}

//Class ManualShippingContainer
//ManualShippingContainer accessor and mutator is implemented in Container.h
//constructor implementation,
ManualShippingContainer::ManualShippingContainer(){
	manifest = " ";
}
//destructor implementation
ManualShippingContainer::~ManualShippingContainer(){
	cout << "Manual Shipping Container out of scope. ";
}

//Class ManualShippingContainer
//constructor implementation,
RFIDShippingContainer::RFIDShippingContainer(){
	total = 0;
}
//destructor implementation
RFIDShippingContainer::~RFIDShippingContainer(){
	cout << "RFID Shipping Container out of scope. ";
}
//Mutator Implementation
void RFIDShippingContainer::add(string item){
	bool valid = false;
	//if the item is in the item[], itemCount[] increase by one
	for(int x=0; x<total;x++){
		if(this->item[x] == item){
			this->itemCount[x] += 1;
			valid = true;
			break;
		}
	}
	//if the item is not in the item[], set itemCount[] to one and total increase by one
	if(valid == false){
		this->itemCount[total] = 1;
		this->item[total] = item;
		total+=1;
	}
}
//Accessor Implementation
string RFIDShippingContainer::getManifest(){
	ostringstream toString;
	for(int x=0; x<total;x++){
		toString.str("");
		toString << itemCount[x];
		if(x < total-1){
			manifest = manifest + toString.str() + " " + item[x] + ", ";
		} else {
			manifest = manifest + toString.str() + " " + item[x] + ".";
		}
	}
	return manifest;
}