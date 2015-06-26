/* 
 * File:   ConsoleTest.h
 * Author: CheeYeong
 *
 * Created on May 20, 2015, 2:11 AM
 */

#ifndef CONSOLETEST_H
#define	CONSOLETEST_H
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "Console.h"

using namespace std;

class ConsoleTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE (ConsoleTest);
    CPPUNIT_TEST (testAuthenticate);
    CPPUNIT_TEST_SUITE_END ();
public:
    void setUp();
    void tearDown();
protected:
    void testAuthenticate();
private:
    Console _console;
};



#endif	/* CONSOLETEST_H */

