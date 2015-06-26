#include "query.h"

Query::Query(){
	
}
Query::~Query() { }


bool Query::selectCustomer(int temp){
	sqlite3pp::database db("csci222asgn2.db");

	string query = "SELECT * FROM Customer where id = " + to_string(temp);
	sqlite3pp::query qry(db, query.c_str());
	if(qry.begin() == qry.end()){ return false; }
	return true;
}
bool Query::selectReservation(int temp){
	sqlite3pp::database db("csci222asgn2.db");

	string query = "SELECT * FROM Reservation where res_id = " + to_string(temp);
	sqlite3pp::query qry(db, query.c_str());
	if(qry.begin() == qry.end()){ return false; }
	return true;
}
bool Query::selectTransaction(int temp){
	sqlite3pp::database db("csci222asgn2.db");

	string query = "SELECT * FROM Log where cust_id = " + to_string(temp);
	sqlite3pp::query qry(db, query.c_str());
	if(qry.begin() == qry.end()){ return false; }
	return true;
}
bool Query::selectSpot(int temp){
	sqlite3pp::database db("csci222asgn2.db");

	string query = "SELECT * FROM Spot where spot_id = " + to_string(temp);
	sqlite3pp::query qry(db, query.c_str());
	if(qry.begin() == qry.end()){ return false; }
	return true;
}

bool Query::insertCustomer(User temp){
	sqlite3pp::database db("csci222asgn2.db");
	sqlite3pp::command cmd(db, "INSERT INTO Customer (name, email, credit_card, car_plate, reserved_spot) VALUES (?, ?, ?, ?, ?)");
    cmd.bind(1, temp.name.c_str());
    cmd.bind(2, temp.email.c_str());
    cmd.bind(3, temp.credit_card.c_str());
    cmd.bind(4, temp.car_plate.c_str());
    cmd.bind(5, temp.reserved_spot);
    cmd.execute();
	return true;
}
bool Query::insertReservation(Reservation temp){
	sqlite3pp::database db("csci222asgn2.db");
	sqlite3pp::command cmd(db, "INSERT INTO Reservation (cust_id, spot_id, car_plate, reservation_date, start_time, end_time) VALUES (?, ?, ?, ?, ?, ?)");
    cmd.bind(1, temp.cust_id);
    cmd.bind(2, temp.spot_id);
    cmd.bind(3, temp.car_plate.c_str());
    cmd.bind(4, temp.reservation_date.c_str());
    cmd.bind(5, temp.start_time);
    cmd.bind(6, temp.end_time);
    cmd.execute();
	return true;
}
bool Query::insertTransaction(Transaction temp){
	sqlite3pp::database db("csci222asgn2.db");
	sqlite3pp::command cmd(db, "INSERT INTO Log (cust_id, car_plate, status, res_date, res_time, arrival_time) VALUES (?, ?, ?, ?, ?, ?)");
    cmd.bind(1, temp.cust_id);
    cmd.bind(2, temp.car_plate.c_str());
    cmd.bind(3, temp.status.c_str());
    cmd.bind(4, temp.res_date.c_str());
    cmd.bind(5, temp.res_time);
    cmd.bind(6, temp.arrival_time);
    cmd.execute();
	return true;
}