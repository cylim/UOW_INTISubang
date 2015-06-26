#include "chord.h"

int main(int argc, char* argv[]){
	string file;
	if (argc == 2){
		file = argv[1];
	} else {
		file = "myfile.dat";
	}
	Chord c;
	c.run(file);

	return 0;
}