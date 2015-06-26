/*
 * File:   UserTest.cpp
 * Author: CheeYeong
 *
 * Created on May 18, 2015, 7:21:50 PM
 */

#include "UserTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION (UserTest);

UserTest::UserTest() {
}

UserTest::~UserTest() {
}

void UserTest::setUp() {
}

void UserTest::tearDown() {
}

void UserTest::testValidatePassword() {
    string wrongPassword1 = "ab123";
    CPPUNIT_ASSERT(!User::validatePassword(&wrongPassword1));
    string wrongPassword2 = "abcdefghijklmn";
    CPPUNIT_ASSERT(!User::validatePassword(&wrongPassword2));
    string wrongPassword3 = "123456789";
    CPPUNIT_ASSERT(!User::validatePassword(&wrongPassword3));

    string validPassword = "admin1234";
    CPPUNIT_ASSERT(User::validatePassword(&validPassword));
}

void UserTest::testSetPasswordByPlainText() {
    string passwordPlain1 = "admin1234";
    string encryptedResult1 = "jmvrw1234";
    User testUser;
    testUser.setPasswordByPlainText(passwordPlain1);
    CPPUNIT_ASSERT_EQUAL(encryptedResult1, testUser.passwordCrypted);

    string passwordPlain2 = "user";
    string encryptedResult2 = "dbna";
    testUser.setPasswordByPlainText(passwordPlain2);
    CPPUNIT_ASSERT_EQUAL(encryptedResult2, testUser.passwordCrypted);
    
    string passwordPlain3 = "manager";
    string encryptedResult3 = "vjwjpna";
    testUser.setPasswordByPlainText(passwordPlain3);
    CPPUNIT_ASSERT_EQUAL(encryptedResult3, testUser.passwordCrypted);
}