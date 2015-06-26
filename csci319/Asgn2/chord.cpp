#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include "chord.h"

Chord::Chord(){
	validate = false;
}

Chord::~Chord(){ }

void Chord::run(string file){
	read(file); // Read Command from file

	// For each command, perform the repective function
	for(vector<Command>::iterator c = cmd.begin(); c != cmd.end(); c++){
		if (c->command.compare("init") == 0) {
			init(c->peer);
		}
		if (c->command.compare("addpeer") == 0) {
			addPeer(c->peer);
			updateFinger();
		}
		if (c->command.compare("insert") == 0) {
			insert(c->peer, c->message);
		}
		if (c->command.compare("print") == 0) {
			print(c->peer);
		}
		if (c->command.compare("delete") == 0) {
			Delete(c->peer, c->message);
		}
		if (c->command.compare("removepeer") == 0) {
			removePeer(c->peer);
			updateFinger();
		}
	}
}

void Chord::init(int index){
	if(validate == false){
		validate = true;
		cout << endl << "This program is written by Lim Chee Yeong 4933643." << endl << endl;

		// if the size is not power of two, change the size to 32
		if(!(index == 1 || index == 2 || index == 4 || index == 8 || index == 16 || 
			index == 32 || index == 64 || index == 128 || index == 256 || index == 512 || 
			index == 1024 || index == 2048 || index == 4096 || index == 8192 || 
			index == 16384 || index == 32768 || index == 65536 || index == 131072 || 
			index == 262144 || index == 524288 || index == 1048576 || index == 2097152 || 
			index == 4194304 || index == 8388608 || index == 16777216 || index == 33554432 || 
			index == 67108864 || index == 134217728 || index == 268435456 || 
			index == 536870912 || index == 1073741824 || index == 2147483648)){
			cout << "Chord size is not power of two, set size to 32." << endl;
			index = 32;
		}
		maxSize = index; // 
		cout << "INITIAZE CHORD" << endl;

		int fingerIndex = log2(index);
		node.resize(index, Node(false, fingerIndex));
		addPeer(0);
	} else {
		cout << "CHORD EXISTED." << endl 
			<< "Skipping initiate CHORD, directly proceed." << endl;
	}
}

void Chord::addPeer(int peer){
	bool status = node[peer].getState();
	if (peer >= maxSize || peer < 0){
		cout << "FAILED: PEER EXIST MAX SIZE." << endl;
	} else {
		if(!status){
			cNode.push_back(peer);
			sort(cNode.begin(), cNode.end());

			node[peer].updatePeer(cNode);

			if(peer != 0) {
				cout << "PEER " << peer << " INSERTED." << endl;
			}
		} else {
			cout << "FAILED: PEER " << peer << "EXISTED." << endl;
		}
	}
	cout << endl;
}

void Chord::removePeer(int peer){
	bool status = node[peer].getState();
	if(status){
		for(vector<int>::iterator i = cNode.begin(); i != cNode.end(); i++){
			if(*i == peer){
				cNode.erase(i);
				break;
			}
		}
		node[peer].updatePeer(cNode);
		cout << "PEER " << peer << " DELETED." << endl;
	} else {
		cout << "FAILED: PEER " << peer << " NOT EXIST." << endl;
	}
	cout << endl;
}

void Chord::find(int peer, int key){
	cout << "Move: " << peer;
	while(peer != key){
		for(vector<Finger>::iterator f = node[peer].fingerTable.end()-1; f >= node[peer].fingerTable.begin(); f--){
			if(key >= f->key){
				peer = f->key;
				cout << " > " << peer;
			}
		}
	}	
	cout << endl;
}

void Chord::insert(int peer, string message){
	find(0, peer);
	unsigned key = hash(message);
	bool status = node[peer].insertData(key, message);
	if(status){
		cout << "INSERTING \"" << message << "\" AT: " << key << endl;
	} else {
		cout << "FAILED: KEY " << key << " EXISTED." << endl;
	}
	cout << endl;
}

void Chord::Delete(int peer, string message){
	find(0, peer);
	bool status = node[peer].removeData(hash(message));
	if(status){
			cout << "REMOVING \"" << message << "\" FROM: PEER " << peer << endl;
	} else {
		cout << "FAILED: MESSAGE NOT AVAILABLE." << endl;
	}
	cout << endl;
}

void Chord::print(int peer){
	bool status = node[peer].getState();
	if (status){
		cout << "DATA AT INDEX NODE " << peer << endl;
		node[peer].showData();
		cout << "FINGER TABLE OF NODE " << peer << ":" << endl;
		node[peer].showFinger();
	} else {
		cout << "NO PEER AT " << peer << endl;
	}
	cout << endl;
}

unsigned Chord::hash(string message){
	unsigned key = 0;
	for(string::iterator character=message.begin(); character!=message.end(); ++character){
		key = ((key << 5) + key) ^ *character;
	}
	return key % 256;
}

void Chord::read(string file){
	cout << "READ FILE: " << file << endl;
	string line;
	ifstream data(file.c_str());
	if(data.is_open()){
		string delimiter = " ";
		while(data.good()){
			Command temp;
			int count = 0;
			getline(data, line);
			while(!line.empty()){

				int index = line.find_first_of(delimiter);
				if (count == 0){
		            temp.command = line.substr(0, index);
		            line = line.substr(index + 1, string::npos);
		            transform(temp.command.begin(), temp.command.end(), temp.command.begin(),::tolower);
		            count++;
		        } else if (count == 1){
		        	string str = line.substr(0, index);
		            temp.peer = atoi(str.c_str());
		            line = line.substr(index + 1, string::npos);
		            count++;
		        } else if (count == 2){
		            temp.message = line;
		            line = "";
		        }
			}
			//temp.seeResult();	// To see the result
			cmd.push_back(temp);
		}
		data.close();
	} else {
		cout << "ERROR ON LOADING FILES." << endl;
	}
}

void Chord::updateFinger(){
	for(vector<int>::iterator i = cNode.begin(); i != cNode.end(); i++){
		int peer = *i;
		int index = 1;
		for(vector<Finger>::iterator f = node[peer].fingerTable.begin(); f != node[peer].fingerTable.end(); f++){
			f->index = index;
			f->key = peer + pow(2, index-1);
			index+=1;
			for(vector<int>::iterator it = cNode.begin(); it != cNode.end(); it++){
				if(f->key < *it && f->key > *(it-1)){
					f->key = *it;
				}
			}
			if(cNode[cNode.size()-1] < f->key){
				f->key = 0;
			}
		}
	}		
}
