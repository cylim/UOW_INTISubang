/* 
 * File:   reservation.h
 * Author: cy
 *
 * Created on June 23, 2015, 5:42 PM
 */

#ifndef TRANSACTION_H
#define	TRANSACTION_H

class Transaction {
public:
	Transaction(){}

	int cust_id;
	string car_plate;
	string status;
	string res_date;
	int res_time;
	int arrival_time;
private:
};

#endif /* TRANSACTION_H */