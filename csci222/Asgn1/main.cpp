/* 
 * File:   main.cpp
 * Author: CheeYeong
 *
 * Created on May 18, 2015, 6:27 PM
 */
#include "Console.h"

using namespace std;

int main(int argc, char** argv) {
    Console console;
    return console.run();
}

// For GCOV Coverage Testing
// gcov -o build/Debug/MinGW-Windows/main -c main.cpp