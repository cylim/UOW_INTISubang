#include "common.h"

class Query{
public:
	Query();
	~Query();

	static bool selectCustomer(int);
	static bool selectReservation(int);
	static bool selectTransaction(int);
	static bool selectSpot(int);

	static bool insertCustomer(User);
	static bool insertReservation(Reservation);
	static bool insertTransaction(Transaction);
};