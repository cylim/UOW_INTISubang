/*
 * File:   UserTest.h
 * Author: CheeYeong
 *
 * Created on May 18, 2015, 7:21:50 PM
 */

#ifndef USERTEST_H
#define	USERTEST_H
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../User.h"

using namespace std;

class UserTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE (UserTest);
    CPPUNIT_TEST (testValidatePassword);
    CPPUNIT_TEST (testSetPasswordByPlainText);
    CPPUNIT_TEST_SUITE_END ();
public:
    UserTest();
    virtual ~UserTest();
    void setUp();
    void tearDown();
protected:
    void testValidatePassword();
    void testSetPasswordByPlainText();
private:
    User user;
};

#endif	/* USERTEST_H */