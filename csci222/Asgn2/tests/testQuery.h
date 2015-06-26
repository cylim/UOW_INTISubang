/*
 * File:   testQuery.h
 * Author: cy
 *
 * Created on Jun 25, 2015, 1:50:24 PM
 */

#ifndef TESTQUERY_H
#define	TESTQUERY_H

#include <cppunit/extensions/HelperMacros.h>
#include "../query.h"

class testQuery : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(testQuery);

    CPPUNIT_TEST(testSelectCustomer);
    CPPUNIT_TEST(testSelectReservation);
    CPPUNIT_TEST(testSelectTransaction);
    CPPUNIT_TEST(testSelectSpot);

    CPPUNIT_TEST(testinsertCustomer);
    CPPUNIT_TEST(testinsertReservation);
    CPPUNIT_TEST(testinsertTransaction);

    CPPUNIT_TEST_SUITE_END();

public:
    testQuery();
    virtual ~testQuery();
    void setUp();
    void tearDown();

private:
    void testSelectCustomer();
    void testSelectReservation();
    void testSelectTransaction();
    void testSelectSpot();

    void testinsertCustomer();
    void testinsertReservation();
    void testinsertTransaction();

    //Query qry;
};

#endif	/* TESTQUERY_H */

