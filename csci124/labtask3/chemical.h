#ifndef ELEMENT
#define ELEMENT
struct ChemicalElement{
	int atomicNumber;
	char name[100];
	char symbol[3];
	float mass;
};
#endif

void search(ChemicalElement[], int); //search by name or symbol
void greaterMass(ChemicalElement[], int); //search by mass
void rangeNumber(ChemicalElement[], int); //search by atomic number