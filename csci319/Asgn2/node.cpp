#include <iostream>
#include "node.h"

Node::Node(bool state, int index){
	this->state = state;
	fingerTable.resize(index);
}

Node::~Node(){ }

bool Node::getState(){
	if(state){
		return true;
	}
	return false;
}

void Node::updatePeer(vector<int> cNode){
	if(state){
		state = false;
		fingerTable.clear();
	} else {
		state = true;
	}
}

bool Node::insertData(unsigned key, string message){
	pair<std::map<unsigned,string>::iterator,bool> ret;
	ret = data.insert(pair<unsigned,string>(key,message));
	if (ret.second==false) {
    	return false;
  	}
  	return true;
}

bool Node::removeData(unsigned key){
	map<unsigned,string>::iterator i = data.find(key);
	if (i != data.end()){
		data.erase(i);
		return true;
	}
	return false;
}

void Node::showData(){
	cout << "Key\tData" << endl;
	cout << "---\t----" << endl;
	map<unsigned, string>::iterator i = data.begin();
	for(i=data.begin(); i!=data.end(); i++){
		cout << i->first << '\t' << i->second << endl;
	}
}

void Node::showFinger(){
	cout << "Index\tKey" << endl;
	cout << "-----\t---" << endl;
	for(vector<Finger>::iterator i = fingerTable.begin(); i != fingerTable.end(); i++){
		cout << i->index << '\t' << i->key << endl;
	}
}