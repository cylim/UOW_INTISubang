//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI204
//Assignment:3 - 1
//Date		:November 21st, 2014

#include <iostream>
using namespace std;
//Class declaration
template<class Key, class Item>
class Keyed_Bag{
	struct node;
	typedef node* nodeptr;
	struct node{
		Key key;
		Item item;
		nodeptr next;
	};
	nodeptr head;
public:
	Keyed_Bag();
	~Keyed_Bag();
	void add(Key, Item);
	bool remove(Key);
	bool isEmpty();
};
//Class Implemantation
//Constructor
template<class Key, class Item>
Keyed_Bag<Key, Item>::Keyed_Bag(){
	head = NULL;
}
//Destructor
template<class Key, class Item>
Keyed_Bag<Key, Item>::~Keyed_Bag(){
	nodeptr current;
	current = head;
	while (head != NULL){
		head = current->next;
		delete current;
		current = head;
	}
	head = NULL;
}
//Add new node into the class
template<class Key, class Item>
void Keyed_Bag<Key, Item>::add(Key key, Item item){
	nodeptr tmp, curr;
	tmp = new node;
	tmp->key = key;
	tmp->next = NULL;
	if(!isEmpty()){
		curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = tmp;
	} else {
		head = tmp;
	}
}
//remove node from the class
template<class Key, class Item>
bool Keyed_Bag<Key, Item>::remove(Key key){
	nodeptr curr, prev;
	curr = head;
	prev = NULL;
	while(curr!=NULL && key != curr->key){
		prev = curr;
		curr = curr->next;
	}
	if(curr==NULL){
		return false;
	} else if(prev) { 
		prev->next = curr->next;
		delete curr;
		return true;
	} else {
		head = curr->next;
		delete curr;
		return true;
	}
}
//check whether the class is empty
template<class Key, class Item>
bool Keyed_Bag<Key, Item>::isEmpty(){
	if (head == NULL){
		return true;
	} else {
		return false;
	}
}
//User define type, struct.
struct Inventory{
	string name;
	double price;
};
//function to check whether delete is successful
void validate(bool check){
	if(check == true){
		cout << "Item sucessfully deleted." << endl << endl;
	} else {
		cout << "Item deletion failure, key not found." << endl << endl;
	}
}

int main(){
	bool check;
	//create three object
	Keyed_Bag<int, string> a;
	Keyed_Bag<string, double> b;
	Keyed_Bag<int, Inventory> c;

	//Testing first object
	cout << "Testing for Keyed_Bag 1" << endl;
	a.add(1, "eggs");
	cout << "add eggs to key 1" << endl;
	a.add(2, "powder");
	cout << "add powder to key 2" << endl;
	a.add(1, "candle");
	cout << "add candle to key 1" << endl;
	check = a.remove(1);
	cout << "remove key 1" << endl;
	validate(check);

	//Testing second object
	cout << "Testing for Keyed_Bag 2" << endl;
	b.add("eggs", 12.5);
	cout << "Added price 12.5 to item key eggs" << endl;
	b.add("bread", 2.4);
	cout << "Added price 2.4 to item key bread" << endl;
	b.remove("eggs");
	cout << "delete eggs" << endl;
	validate(check);

	//Testing third Object
	cout << "Testing for Keyed_Bag 3" << endl;
	Inventory inv[3];
	for(int x=0; x<3; x++){
		inv[x].name = "Item" + x;
		inv[x].price = x + 3.2;
	}
	c.add(1, inv[0]);
	cout << "Add Inventory to key 1" << endl;
	c.add(2, inv[1]);
	cout << "Add Inventory to key 2" << endl;
	check = c.remove(3);
	cout << "Delete key 3" << endl;
	validate(check);
}