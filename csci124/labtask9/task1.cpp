//Author	:Lim Chee Yeong
//Student ID: J14016414(INTI) or 4933643(UOW)
//Class		:CSCI124
//Lab Task	:9 - 1
//Date		:November 9th, 2014

#include <iostream>
#include <cstring>
using namespace std;

class Patient{
	struct node;
	typedef node* nodeptr;
	struct node{
		char name[30];
		nodeptr next;
	};
	nodeptr head;
public:
	Patient();
	~Patient();
	void insert(char[]);
	void push_back(char[]);
	bool isempty();
	void consult();
	void display();
	void remove(char[]);
};
//Constructor, create empty list
Patient::Patient(){
	head = NULL;
}
//Destructor to delete all dynamic object.
Patient::~Patient(){
	nodeptr current;
	current = head;
	while (head != NULL){
		head = current->next;
		delete current;
		current = head;
	}
	head = NULL;
}
// check whether head is empty
bool Patient::isempty(){
	if (head == NULL){
		return true;
	} else {
		return false;
	}
}
// add patient at the front of the list
void Patient::insert(char name[]){
	nodeptr tmp;
	tmp = new node;
	strcpy(tmp->name, name);
	tmp->next = NULL;
	if (!isempty()){
		tmp->next = head;
		head = tmp;
	} else {
		head = tmp;
	}
}
// add patient at the back of the list
void Patient::push_back(char name[]){
	nodeptr tmp, curr;
	tmp = new node;
	strcpy(tmp->name, name);
	tmp->next = NULL;
	if(!isempty()){
		curr = head;
		while(curr->next){
			curr = curr->next;
		}
		curr->next = tmp;
	} else {
		head = tmp;
	}
}
//Remove the first one from the list, due to the first patient go to consult doctor
void Patient::consult(){
	nodeptr tmp;
	//tmp = new node;
	char name[30];
	if(!isempty()){
		strcpy(name, head->name);
		tmp = head;
		head = head->next;
		delete tmp;
		cout << name << " consult doctor." << endl << endl;
	} else {
		cout << "No patient in waiting list." << endl << endl;
	}
}
//Remove selected name from the list
void Patient::remove(char name[]){
	nodeptr curr, prev;
	curr = head;
	prev = NULL;
	while(curr!=NULL && strcmp(name, curr->name) != 0){
		prev = curr;
		curr = curr->next;
	}
	if(curr==NULL){
		cout << "Patient not found!" << endl << endl;
	} else if(prev) { 
		prev->next = curr->next;
		delete curr;
		cout << "Patient name: " << name << " removed from the list." << endl << endl;
	} else {
		head = curr->next;
		delete curr;
		cout << "Patient name: " << name << " removed from the list." << endl << endl;
	}
}
//Display all patient in waiting list
void Patient::display(){
	nodeptr tmp;
	if (!isempty()){
		int count = 1;
		tmp = head;
		cout << "No\tName" << endl;
		while(tmp){
			cout << count << "\t" << tmp->name << endl;
			count+=1;
			tmp = tmp->next;
		}
	} else {
		cout << "The list is empty." << endl << endl;
	}
}

int main(){
	int option;
	Patient list;
	while(true){
		//show the menu title
		cout << "\t+++++++++++++++++++++++++++++++++++++++++" << endl
			<< "\t+\tClinic Patients Management\t+" << endl
			<< "\t+++++++++++++++++++++++++++++++++++++++++" << endl;
		//show the menu selection
		cout << "1. Register a new patient" << endl
			<< "2. Remove a patient" << endl
			<< "3. Doctor consultation" << endl
			<< "4. Display patients list" << endl
			<< "0. Exit" << endl;
		cout << "Option: ";
		cin >> option;

		int priority;
		char name[30];
		switch(option){
			case 1: //Registering new patient
				cin.ignore();
				cin.clear();
				cout << "Name: ";
				cin.getline(name, 30);
				//cout << name; //check the output of name
				cout << "Priority (0 or 1): ";
				cin >> priority;
				if(priority == 0){
					list.push_back(name);
				} else if(priority == 1) {
					list.insert(name);
				} else {
					cout << "Wrong priority input. \n" << endl;
				}
				break;
			case 2: //Removing patient from waiting list
				cin.ignore();
				cin.clear();
				cout << "Name: ";
				cin.getline(name, 30);
				//cout << name; //check the output of name
				list.remove(name);
				break;
			case 3: //Inform first patient to consult doctor
				list.consult();
				break;
			case 4: //Display patient waiting list
				list.display();
				break;
			case 0:
				cout << "Thank you for using." << endl << endl;
				return 0; 
			default:
				cout << "Wrong input, please try again." << endl << endl;
		}
	}
}