/* 
 * File:   main.cpp
 * Author: cy
 *
 * Created on June 23, 2015, 5:35 PM
 */

#include "console.h"

using namespace std;

int main(int argc, char** argv){
	Console console;
	return console.run(true);
}

// For GCOV Coverage Testing
// gcov -o build/Debug/GNU-MacOSX/main -c main.cpp