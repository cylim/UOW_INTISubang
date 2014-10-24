class RetailItem{
	int ID, unit;
	char description[50];
	double price;
public:
	RetailItem(int = 0, char[] = (char*)&"none", int = 0, double = 0);
	void setID(int); //initialize ID
	void setDescription(char[]); //initialize description
	void setUnit(int); //initialize quantity
	void setPrice(double); //initialize price
	int getID(); //request id
	int getUnit(); //request unit
	int getPrice(); //request price
	void display(); //request all info 
	void sold(int); // get sale price
};