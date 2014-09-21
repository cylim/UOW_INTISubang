#ifndef ELEMENT
#define ELEMENT
struct ChemicalElement{
	int atomicNumber;
	char name[100];
	char symbol[3];
	float mass;
};
#endif

int readToBinary(ChemicalElement[]);