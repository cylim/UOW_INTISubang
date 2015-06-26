/* 
 * File:   user.h
 * Author: cy
 *
 * Created on June 23, 2015, 5:43 PM
 */

#ifndef USER_H
#define	USER_H
 
#include <iostream>

using namespace std;

class User {
public:
	User() {
		car_plate = "";
		reserved_spot = 0;
	}

	int id;
	string name;
	string email;
	string credit_card;
	string car_plate;
	int reserved_spot;
private:
	
};

#endif	/* USER_H */

