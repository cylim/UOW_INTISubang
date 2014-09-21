using namespace std;

class Item{
	string name;
	int itemCount;
	float price;
	int weight;
	string description;
public:
	Item();
	Item(string, int, float, int, string);
	//Mutator declaration
	inline void setName(string name){ this->name = name; }
	inline void setItemCount(int itemCount){ this->itemCount = itemCount; }
	inline void setPrice(float price){ this->price = price; }
	inline void setWeight(int weight){ this->weight = weight; }
	inline void setDescription(string description){ this->description = description; }
	//Assessor declaration
	inline string getName(){ return name; }
	inline int getItemCount(){ return itemCount; }
	inline float getPrice(){ return price; }
	inline int getWeight(){ return weight; }
	inline string getDescription(){ return description; }
	float totalValue(); // display the total value of one item
	void display(); //display all elements in item
};

class Customer{
	string name;
	float cash;
	Item purchasedItem[100];
public:
	Customer();
	Customer(string, float);
	//Mutator declaration
	inline void setName(string name){ this->name = name; }
	inline void setCash(float cash){ this->cash = cash; }
	inline void setPurchasedItem(int x, string name, int quantity, float price, int weight = 0, string description = " "){
		purchasedItem[x] = Item(name, quantity, price, weight, description);
	}
	//Assessor declaration
	inline string getName(){ return name; }
	inline float getCash(){ return cash; }
	void displayPurchasedList(int); // display the list of purchased item
	void displayPrice(int); // display the total price
	~Customer();
};

class Supermarket{
	string name;
	float cash;
	Item stock[100];
	int total;
public:
	Supermarket();
	//Mutator declaration
	inline void setName(string name){ this->name = name; }
	inline void setCash(float cash){ this->cash = cash; } 
	inline void setItem(int x, string name, int quantity, float price, int weight, string description){
		stock[x] = Item(name, quantity, price, weight, description);
	}
	//Assessor declaration
	inline string getName(){ return name; }
	inline float getCash(){ return cash; }
	void shop(Customer&); // for customer to purchase item
	void reportStock(); // to list out every item in details
	void reportFinancial(); //show the cash value and stok value
	~Supermarket();
};