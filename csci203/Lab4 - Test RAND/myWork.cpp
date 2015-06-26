#include <iostream>
#include <cstdlib>
#include <ctime>
#include <md5.h>

using namespace std;

int generator(int output){
	return (output) + (rand());
}

int main(){
	int count[6] = { 0, 0, 0, 0, 0, 0 };
	long int output;

	srand(time(0));
	for (int x = 0; x < 6000; x++) {
		output = generator(output);
		output = output % 6 + 1;
		if (output == 1)
			count[0]++;
		else if (output == 2)
			count[1]++;
		else if (output == 3)
			count[2]++;
		else if (output == 4)
			count[3]++;
		else if (output == 5)
			count[4]++;
		else
			count[5]++;
	}

	for (int x = 0; x<6; x++)
		cout << x + 1 << " occured " << count[x] << " times" << endl;
}