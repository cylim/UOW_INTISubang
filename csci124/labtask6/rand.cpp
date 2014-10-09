#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int total = 10;
	for(int i=0;i<10; i++){
		cout << rand() % total << endl;
	}
}