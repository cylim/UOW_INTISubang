/* 
 * File:   spot.h
 * Author: cy
 *
 * Created on June 23, 2015, 5:37 PM
 */

#ifndef SPOT_H
#define	SPOT_H

#include <iostream>

using namespace std;

class Spot {
public:
	Spot() {}

	int id;
	string car_plate;
	string status;
	int arrival_time;
	int res_id;
private:

};


#endif	/* SPOT_H */

