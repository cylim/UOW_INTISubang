/* 
 * File:   reservation.h
 * Author: cy
 *
 * Created on June 23, 2015, 5:42 PM
 */

#ifndef RESERVATION_H
#define	RESERVATION_H
 
#include <iostream>

using namespace std;

class Reservation {
public:
	Reservation() {}

	int res_id;
	int cust_id;
	int spot_id;
	string car_plate;
	string reservation_date;
	int start_time;
	int end_time;
private:
	
};

#endif	/* RESERVATION_H */

