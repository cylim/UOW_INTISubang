/* 
 * File:   console.h
 * Author: cy
 *
 * Created on June 23, 2015, 5:40 PM
 */

#ifndef CONSOLE_H
#define	CONSOLE_H

#include "common.h"

using namespace std;

class Console {
    public:
        Console();                  // constructor
        virtual ~Console();         // destructor
        int run(bool);                  // start the program
    private:

        // vector<User>            user;              // details about each customer
    	// vector<Reservation>     reservation;       // details about reservation
    	// vector<vector<Spot>>    spot;              // details about parking spot

        vector<int>     raincheck;      // store raincheck
        float           reserveFee;     // Fees for Reserved parking
        float           overstayFee;    // Fees for Over Stay parking
        float           noshowFee;      // Fees for No Show reservation

        sqlite3pp::database     db;                 // connect the database

    	// Menu stuff
        void showMainMenu();        // prompt Main Menu for user to choose
        void showParkingMenu();     // prompt Menu about Parking
        void showReservationMenu(); // prompt Menu about Reservation
        void showAccountMenu();     // prompt Menu about Account Management
        void showAdminMenu();       // prompt Menu about administration settings
        void backToMenu();          // back the showMainMenu()
        // Car Related
        void parkCar();             // park car to respective places
        void leaveCar();            // leaving the carpark
        void showCar();             // check individual car
        // Reservation Related
        void newReservation();              // create reservation for parking spot
        void editReservation();             // edit the reservation details
        void showReservation(bool, int);    // show individual reservation
        // Account Related
        void newRegistration();     // register new customer
        void showReport();          // show historical report of respective customer
        // Administrative Related
        void showPrice();           // show price for the parking system
        void setPrice();            // set price for the parking system
        void showCarpark();         // check the whole car park
        void editCarpark();         // edit the carpark size
        void statistic();           // statistic of the parking system
        // Simulate the whole Program
        void simulate();            // simulate the whole program
        //Terminate the Program
        void quit();                // terminate the program
};

#endif	/* CONSOLE_H */