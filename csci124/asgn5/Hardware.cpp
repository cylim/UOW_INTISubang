#include <iostream>
#include <cstring>
#include "Hardware.h"
using namespace std;

Hardware::Hardware(){
	root = NULL;
}
Hardware::~Hardware(){
	ofstream write("hardware.txt", ios::trunc);
	inordersave(write, root); // save everything in the node to file
	write.close();
	postorderdelete(root); // delete everything in the node
}

void Hardware::insert(const int& barcode, char description[], double& price, int& quantity){
	insertnode(barcode, description, price, quantity, root);
}
bool Hardware::locate(const int& barcode, char description[], double& price, int& quantity){
	nodeptr found = findnode(barcode, root);
	if(found != NULL){
		strcpy(description, found->description);
		price = found->price;
		quantity = found->quantity;
		return true;
	} else {
		return false;
	}
}
void Hardware::inorder_traversal(){
	inorder(root);
}
// Edit Hardware price or quantity
void Hardware::update(const int& barcode, double& price, int& quantity){
	nodeptr found = findnode(barcode, root);
	if(found != NULL){
		found->price = price;
		found->quantity = quantity;
	} else {
		cout << "Item not found!" << endl << endl;
	}
}
void Hardware::updateQuantity(const int& barcode, int& quantity){
	nodeptr found = findnode(barcode, root);
	if(found != NULL){
		found->quantity = quantity;
	} else {
		cout << "Item not found!" << endl << endl;
	}
}

//Compare the node key with data key to determine the right way of insert
void Hardware::insertnode(const int& barcode, char description[], double& price, int& quantity, Hardware::nodeptr& rootp){
	if(rootp == NULL){
		rootp = new node;
		rootp->barcode = barcode;
		strcpy(rootp->description, description);
		rootp->price = price;
		rootp->quantity = quantity;
		rootp->left = NULL;
		rootp->right = NULL;
	} else if(barcode <= rootp->barcode){
		insertnode(barcode, description, price, quantity, rootp->left);
	} else {
		insertnode(barcode, description, price, quantity, rootp->right);
	}
}
//check if the key is same with node data, if so retrieve the data.
Hardware::nodeptr Hardware::findnode(const int& barcode, Hardware::nodeptr& rootp){
	if(barcode == rootp->barcode){
		return rootp;
	} else if(barcode < rootp->barcode && rootp->left != NULL){
		return findnode(barcode, rootp->left);
	} else if(barcode > rootp->barcode && rootp->right != NULL){
		return findnode(barcode, rootp->right);
	}
	return NULL;
}
void Hardware::inorder(nodeptr curr){
	if (curr != NULL){
		inorder(curr->left);
		cout << curr->barcode << '\t' << curr->price << "\t" 
			<< curr->quantity << '\t' << curr->description << endl;
		inorder(curr->right);
	}
}
// to save each node to file in ascending order by the barcode
void Hardware::inordersave(ofstream& write, nodeptr curr){
	if (curr != NULL){
		inordersave(write, curr->left);
		write << curr->barcode << ' ' << curr->price << ' ' 
			<< curr->quantity << curr->description << '\n';
		inordersave(write, curr->right);
	}
}

// to delete all sub-node in oreder to clean all node.
void Hardware::postorderdelete(nodeptr curr){
	if (curr != NULL){
		postorderdelete(curr->left);
		postorderdelete(curr->right);
		delete curr;
	}
}