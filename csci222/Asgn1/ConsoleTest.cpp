#include "ConsoleTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (ConsoleTest);

void ConsoleTest::setUp(){
}

void ConsoleTest::tearDown(){
}

void ConsoleTest::testAuthenticate() {
    string userID;
    string password;

    // test using a user id/password which are invalid
    CPPUNIT_ASSERT(!_console.authenticate(&userID, &password));

    // test valid user id/password
    userID = "admin";
    password = "admin12345";
    CPPUNIT_ASSERT(_console.authenticate(&userID, &password));

    // after 3 continously failed attempts, the account should be locked
    userID = "admin";
    password = "wrong one";
    CPPUNIT_ASSERT(!_console.authenticate(&userID, &password));
    CPPUNIT_ASSERT(!_console.authenticate(&userID, &password));
    CPPUNIT_ASSERT(!_console.authenticate(&userID, &password));
    userID = "admin";
    password = "admin12345";
    CPPUNIT_ASSERT(!_console.authenticate(&userID, &password));
}