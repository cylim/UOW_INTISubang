#include <iostream>
#include <ctime>
#include "sort.h"

using namespace std;

int main ()
{
	int m, num[dataSIZE];
	int isdata[dataSIZE], ssdata[dataSIZE], msdata[dataSIZE];
	time_t start, end;
	float diff;
	srand (time(NULL));
	cout << "Generate 30000 random numbers ...";
	for (m=0; m<dataSIZE; m++) {	//generate 30000 random numbers
		num[m] = rand() % 30000;
		isdata[m] = num[m];
		ssdata[m] = num[m];
		msdata[m] = num[m];
	}
	cout << "done" << endl;
	start = clock();	
	insertionSort (isdata, dataSIZE);
	end = clock();
	diff = (float)(end - start)/CLOCKS_PER_SEC;	
	cout << "\n\nSorted data (show the first 30 only)" << endl;
	cout << "\nInsertion sort " << diff << " second" << endl;
	for (m=0; m<30; m++)
		cout << isdata[m] << " ";
	
	start = clock();
	shellSort (ssdata, dataSIZE);
	end = clock();
	diff = (float)(end - start)/CLOCKS_PER_SEC;	
	cout << "\n\nShell sort " << diff << " second" << endl;
	for (m=0; m<30; m++)
		cout << ssdata[m] << " ";

// Exercise : write the mergeSort function	
	start = clock();
	mergeSort(msdata, 0, dataSIZE-1);
	end = clock();
	diff = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "\n\nMerge sort " << diff << " second" << endl;
	for (m = 0; m<30; m++)
		cout << msdata[m] << " ";

	cout << endl << endl;
	//system ("PAUSE");
}