class Training{
	//traing details
	char id[6], description[51], date[31], trainingTime[16], charges[8];
	//participant details
	int total;
	char pid[30][15], firstName[30][10], lastName[30][10]; 
public:
	void setCourse(char[],char[],char[],char[],char[]);
	void setTotal(int);
	void setParticipant(int, char[],char[],char[]);
	char* getID(){ return id; }
	int getTotal(){ return total; }
	char* getPID(int num){ return pid[num]; }
	void delParticipant(int); //delete participant from object
	void display(); //display every details
	void save(char[]); //save objects into file
};