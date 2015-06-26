/*
 * File:   testQuery.cpp
 * Author: cy
 *
 * Created on Jun 25, 2015, 1:50:24 PM
 */

#include "testQuery.h"
#include "../common.h"


CPPUNIT_TEST_SUITE_REGISTRATION(testQuery);

testQuery::testQuery() {
}

testQuery::~testQuery() {
}

void testQuery::setUp() {
}

void testQuery::tearDown() {
}

void testQuery::testSelectCustomer(){
	User cus;
	cus.id = 1;
	CPPUNIT_ASSERT(Query::selectCustomer(cus.id));
	cus.id = 0;
	CPPUNIT_ASSERT(!Query::selectCustomer(cus.id));
}

void testQuery::testSelectReservation(){
	CPPUNIT_ASSERT(true);

	int id = 1001;
	CPPUNIT_ASSERT(Query::selectReservation(id));
	id = 999;
	CPPUNIT_ASSERT(!Query::selectReservation(id));
}

void testQuery::testSelectTransaction(){
	int id = 0;
	CPPUNIT_ASSERT(!Query::selectTransaction(id));
	id = 2;
	CPPUNIT_ASSERT(Query::selectTransaction(id));
}

void testQuery::testSelectSpot(){
	int id = 0;
	CPPUNIT_ASSERT(!Query::selectSpot(id));
	id = 101;
	CPPUNIT_ASSERT(Query::selectSpot(id));
}

void testQuery::testinsertCustomer(){
	User cus;
	cus.name = "Tester";
	cus.email = "tester@test.test";
	cus.credit_card = "101029293838";
	cus.reserved_spot = 300;
	CPPUNIT_ASSERT(Query::insertCustomer(cus));
}
void testQuery::testinsertReservation(){
	Reservation res;
	res.cust_id = 2;
	res.spot_id = 101;
	res.car_plate = "PPP2222";
	res.reservation_date = "2015-06-24";
	res.start_time = 1000;
	res.end_time = 1200;
	CPPUNIT_ASSERT(Query::insertReservation(res));
}
void testQuery::testinsertTransaction(){
	Transaction trans;
	trans.cust_id = 2;
	trans.car_plate = "PPP1111";
	trans.status = "good";
	trans.res_date = "2015-06-14";
	trans.res_time = 800;
	trans.arrival_time = 800;
	CPPUNIT_ASSERT(Query::insertTransaction(trans));
}