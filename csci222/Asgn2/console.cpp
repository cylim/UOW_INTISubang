#include "console.h"
#include <cstring>

// Constructor
Console::Console() {
    reserveFee  = 0.5;
    overstayFee = 2.0;
    noshowFee   = 1.0;

    db = sqlite3pp::database("csci222asgn2.db");
}

// Destructor
Console::~Console() { }

// start the program
int Console::run(bool value) {
    if (value) { showMainMenu(); }
    else { return 1; }

    return 0;
}

//
// Car Related
//

// park car to respective places
void Console::parkCar(){
    cout << endl << "\t--\tParking\t--" << endl << endl;

    string car_plate;
    char check;
    int arrival_time, spot_id, start_time, end_time;

    cout << "Enter car plate number: ";
    cin >> car_plate;
    cout << "Arrival Time(HHMM): ";
    cin >> arrival_time;

    string tempQuery = "SELECT id, reserved_spot FROM Customer WHERE car_plate = '" + car_plate + "'";
    sqlite3pp::query qry1(db, tempQuery.c_str());  
    sqlite3pp::query::iterator i = qry1.begin();  
    if(i == qry1.end()){
        cout << "Car plate not found." << endl;

        int res_id;
        cout << "Enter reservation number: ";
        cin >> res_id;

        // check whether the car park is available, if not then issue raincheck
        tempQuery = "SELECT * FROM Spot WHERE status = 'available'";
        sqlite3pp::query qry2(db, tempQuery.c_str());
        if(qry2.begin() == qry2.end()){
            int cust_id;
            cout << "Car park fulled. Issue raincheck to customer id: ";
            cin >> cust_id;
            raincheck.push_back(cust_id);

            backToMenu();
        }

        tempQuery = "SELECT spot_id, start_time FROM Reservation WHERE res_id = " + to_string(res_id);
        sqlite3pp::query qry3(db, tempQuery.c_str()); 
        sqlite3pp::query::iterator i = qry3.begin();
        if (i != qry3.end()){
            (*i).getter() >> spot_id
                        >> start_time;

            cout << "Parking Spot: " << spot_id << endl;
            cout << "Start Time: " << start_time << endl;
            cout << "Confirm? (Y/N): ";
            cin >> check;
            if(check == 'Y' || check == 'y'){
                if (arrival_time > start_time){
                    cout << "Do you want to extend stay period? (Y/N): ";
                    cin >> check;
                    if (check == 'Y' || check == 'y'){
                        cout << "Enter expected leave time(HHMM): ";
                        cin >> end_time;
                    }
                }
                
                sqlite3pp::command st(db, "UPDATE Spot SET car_plate = ?, status = 'occupied', arrival_time = ?, res_id = ? WHERE spot_id = ? ");
                st.bind(1, car_plate.c_str());
                st.bind(2, arrival_time);
                st.bind(3, res_id);
                st.bind(4, spot_id);
                st.execute();
            }
        } else {
            cout << "Reservation not found." << endl;
            cout << "Do you want to create reservation? (Y/N): ";
            cin >> check;
            if(check == 'Y' || check == 'y'){
                newReservation();
            }
        }
    } else {
        string temp;
        (*i).getter() >> temp
                    >> spot_id;

        sqlite3pp::command st(db, "UPDATE Spot SET car_plate = ?, status = 'occupied', arrival_time = ?, res_id = 1000 WHERE spot_id = ? ");
            st.bind(1, car_plate.c_str());
            st.bind(2, arrival_time);
            st.bind(3, spot_id);
            st.execute();
    }

    backToMenu();
}

// leaving the carpark
void Console::leaveCar(){
    cout << endl << "\t--\tLeaving\t--" << endl << endl;

    Spot spot;
    cout << "Enter Car Plate Number: ";
    cin >> spot.car_plate;

    string tempQuery = "SELECT * FROM Spot WHERE car_plate = '" + spot.car_plate + "'";
    sqlite3pp::query qry(db, tempQuery.c_str());

    sqlite3pp::query::iterator i = qry.begin();
    if(i == qry.end()){
        cout << "\033[31m" << "Car plate not found! Back to Main." << "\033[0m" << endl;
        backToMenu();
    }
    (*i).getter() >> spot.id
                >> spot.car_plate
                >> spot.status
                >> spot.arrival_time
                >> spot.res_id;

    cout << "Successfully retrieved car info." << endl;

    Reservation reservation;
    tempQuery = "SELECT * FROM Reservation WHERE res_id = " + to_string(spot.res_id);
    sqlite3pp::query qry1(db, tempQuery.c_str());
    i = qry1.begin();
    if(i == qry1.end()){
        cout << "\033[31m" << "Reservation not found! Back to Main." << "\033[0m" << endl;
        backToMenu();
    }

    (*i).getter() >> reservation.res_id
                >> reservation.cust_id
                >> reservation.spot_id
                >> reservation.car_plate
                >> reservation.reservation_date
                >> reservation.start_time
                >> reservation.end_time;

    cout << "Successfully retrieved parking info." << endl << endl;

    int exit_time;
    cout << "Enter Exit Time(HHMM): ";
    cin >> exit_time;

    double reservedTime = ((reservation.end_time - reservation.start_time) / 100 + 1) * reserveFee;
    double overstayTime = ((exit_time - reservation.end_time) / 100 + 1) * overstayFee;

    cout << "Reserved Parking Fee: MYR " << reservedTime << endl;
    cout << "Overstay Parking Fee: MYR " << overstayTime << endl;
    cout << "Total Parking Fee   : MYR " << reservedTime + overstayTime << endl;

    string status;
    if(spot.arrival_time > reservation.start_time) status = "late";
    if(spot.arrival_time < reservation.start_time) status = "early";
    if(spot.arrival_time == reservation.start_time) status = "good";

    sqlite3pp::command cmd(db, "INSERT INTO Log (cust_id, car_plate, status, res_date, res_time, arrival_time) VALUES (?, ?, ?, ?, ?, ?)");
    cmd.bind(1, reservation.cust_id);
    cmd.bind(2, spot.car_plate.c_str());
    cmd.bind(3, status.c_str());
    cmd.bind(4, reservation.reservation_date.c_str());
    cmd.bind(5, reservation.start_time);
    cmd.bind(6, spot.arrival_time);
    cmd.execute();

    sqlite3pp::command st(db, "UPDATE Spot SET car_plate = '0', status = 'available', arrival_time = 0 WHERE spot_id = ?");
    st.bind(1, spot.id);
    st.execute();

    backToMenu();
}

// check individual car
void Console::showCar(){
    cout << endl << "\t--\tShow Car Information\t--" << endl << endl;

    Spot temp;

    cout << "Enter car plate number: ";
    cin >> temp.car_plate;
    string query = "SELECT spot_id, car_plate, status, res_id FROM Spot WHERE  status = 'occupied' AND car_plate = '" 
                + temp.car_plate + "'";
    sqlite3pp::query qry(db, query.c_str());

    //Show Column
    sqlite3pp::query::iterator i = qry.begin();
    if (i == qry.end()){
        cout << "No Records availables." << endl;
    } else {
        for (int i = 0; i < qry.column_count(); ++i) {
            cout << qry.column_name(i) << "\t";
        }
        cout << endl;
        (*i).getter() >> temp.id
                    >> temp.car_plate
                    >> temp.status
                    >> temp.res_id;
                
        cout << temp.id              << "\t" 
            << temp.car_plate        << "\t\t" 
            << temp.status           << "\t"
            << temp.res_id           << endl;
    }

    backToMenu();
}

//
// Reservation Related
//

// create reservation for parking spot
void Console::newReservation(){
    cout << endl << "\t--\tCreate Reservation\t--" << endl << endl;

    Reservation temp;

    cout << "Enter account ID: ";
    cin >> temp.cust_id;
    string tempQuery = "SELECT id FROM CUSTOMER WHERE id = " + to_string(temp.cust_id);
    sqlite3pp::query qry1(db, tempQuery.c_str());
    if(qry1.begin() != qry1.end()){

        cout << "Enter parking spot ID: ";
        cin >> temp.spot_id;
        tempQuery = "SELECT spot_id FROM Spot WHERE spot_id = " + to_string(temp.spot_id);
        sqlite3pp::query qry2(db, tempQuery.c_str());
        if(qry2.begin() != qry2.end()){

            cout << "Enter car plate number: ";
            cin >> temp.car_plate;
            cout << "Enter reservation date(YYYY-MM-DD): ";
            cin >> temp.reservation_date;
            cout << "Enter start time(HHMM): ";
            cin >> temp.start_time;
            cout << "Enter end time(HHMM): ";
            cin >> temp.end_time;

            sqlite3pp::command cmd(db, "INSERT INTO Reservation (cust_id, spot_id, car_plate, reservation_date, start_time, end_time) VALUES (?, ?, ?, ?, ?, ?)");
            cmd.bind(1, temp.cust_id);
            cmd.bind(2, temp.spot_id);
            cmd.bind(3, temp.car_plate.c_str());
            cmd.bind(4, temp.reservation_date.c_str());
            cmd.bind(5, temp.start_time);
            cmd.bind(6, temp.end_time);
            cmd.execute();

            sqlite3pp::query qry(db, "SELECT MAX(res_id) FROM Reservation");
            sqlite3pp::query::iterator i = qry.begin();
            (*i).getter() >> temp.res_id;
                        
            cout << "\033[31m" << "Reservation Created. ID: " << temp.res_id << "\033[0m" << endl;
        } else {
            cout << "\033[31m" << "Spot ID not found." << "\033[0m" << endl;
        }
    } else {
        cout << "\033[31m" << "Customer ID not found." << "\033[0m" << endl;
    }

    

    backToMenu();
}

void Console::editReservation(){
    cout << endl << "\t--\tEdit Reservation\t--" << endl << endl;
    Reservation res;

    cout << "Enter reservation id: ";
    cin >> res.res_id;
    showReservation(true, res.res_id);

    char check;
    cout << "Continue to edit? (Y/N): ";
    cin >> check;
    if(check == 'Y' || check == 'y'){
        cout << "Enter new car plate number: ";
        cin >> res.car_plate;
        cout << "Enter reserve date(YYYY-MM-DD): ";
        cin >> res.reservation_date;
        cout << "Enter expected arrival time: ";
        cin >> res.start_time;
        cout << "Enter expected end time: ";
        cin >> res.end_time;

        sqlite3pp::command st(db, "UPDATE Reservation SET car_plate = ?, reservation_date = ?, start_time = ?, end_time = ? WHERE res_id = ?");
        st.bind(1, res.car_plate.c_str());
        st.bind(2, res.reservation_date.c_str());
        st.bind(3, res.start_time);
        st.bind(4, res.end_time);
        st.bind(5, res.res_id);
        st.execute();
    }

    backToMenu();
}

// show individual reservation
void Console::showReservation(bool state = false, int res_id = 0){
    cout << endl << "\t--\tShow Reservation\t--" << endl << endl;
    if(!state){
        cout << "Enter Reservation Number: ";
        cin >> res_id;
    }

    string temp = "SELECT * FROM Reservation WHERE res_id = " + to_string(res_id);
    sqlite3pp::query qry(db, temp.c_str());

    //Show Column
    sqlite3pp::query::iterator i = qry.begin();
    if (i == qry.end()){
        cout << "No Records availables." << endl;
    } else {
        for (int i = 0; i < qry.column_count(); ++i) {
            cout << qry.column_name(i) << "\t";
        }
        cout << endl;

        Reservation temp;
        (*i).getter() >> temp.res_id
                    >> temp.cust_id
                    >> temp.spot_id 
                    >> temp.car_plate
                    >> temp.reservation_date
                    >> temp.start_time
                    >> temp.end_time;
                
        cout << temp.res_id              << "\t" 
            << temp.cust_id              << "\t" 
            << temp.spot_id              << "\t" 
            << temp.car_plate            << "\t\t"
            << temp.reservation_date     << "\t\t";

            if(temp.start_time < 1000){
                cout << "0" << temp.start_time << "\t\t";
            } else { cout << temp.start_time << "\t\t"; }
            if(temp.end_time < 1000){
                cout << "0" << temp.end_time << endl;
            } else { cout << temp.end_time << endl; };
    }
    if(!state){
        backToMenu();
    }
}

//
// Account Related
//

// register new customer
void Console::newRegistration(){
    cout << endl << "\t--\tCreate Account\t--" << endl << endl;

    User temp;
    char check;

    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, temp.name);
    cout << "Enter your email: ";
    cin >> temp.email;
    cout << "Enter your credit card number: ";
    cin >> temp.credit_card;
    cout << "Do you want to reserve a parking spot monthly(Y/N): ";
    cin >> check;
    if(check == 'Y' || check == 'y'){
        cout << "Enter a car plate: ";
        cin >> temp.car_plate;
        cout << "Enter the spot number: ";
        cin >> temp.reserved_spot;
    }
    sqlite3pp::command cmd(db, "INSERT INTO Customer (name, email, credit_card, car_plate, reserved_spot) VALUES (?, ?, ?, ?, ?)");
    cmd.bind(1, temp.name.c_str());
    cmd.bind(2, temp.email.c_str());
    cmd.bind(3, temp.credit_card.c_str());
    cmd.bind(4, temp.car_plate.c_str());
    cmd.bind(5, temp.reserved_spot);
    cmd.execute();

    // Find the customer id
    sqlite3pp::query qry(db, "SELECT MAX(id) FROM Customer");
    sqlite3pp::query::iterator i = qry.begin();
    int cust_id;

    (*i).getter() >> cust_id;
            
    cout << "\033[31m" << "Account Created. ID: " << cust_id << "\033[0m" << endl;

    sqlite3pp::command st(db, "UPDATE Spot SET car_plate = ?, status = 'reserved' WHERE spot_id = ? ");
    st.bind(1, temp.car_plate.c_str());
    st.bind(2, temp.reserved_spot);

    backToMenu();
}

// show historical report of respective customer
void Console::showReport(){
    cout << endl << "\t--\tShow Report\t--" << endl << endl;

    int id;

    cout << "Enter Customer ID: ";
    cin >> id;

    string temp = "SELECT * FROM Log WHERE cust_id = " 
                + to_string(id) + " ORDER BY res_date DESC";
    sqlite3pp::query qry(db, temp.c_str());

    //Show Column
    sqlite3pp::query::iterator i = qry.begin();
    if (i == qry.end()){
        cout << "No Records availables." << endl;
    } else {
        for (int i = 0; i < qry.column_count(); ++i) {
            cout << qry.column_name(i) << "\t";
        }
        cout << endl;

        Transaction temp;
        do {
            (*i).getter() //>> sqlite3pp::ignore 
                        >> temp.cust_id
                        >> temp.car_plate 
                        >> temp.status
                        >> temp.res_date
                        >> temp.res_time
                        >> temp.arrival_time;
                    
            cout << temp.cust_id             << "\t" 
                << temp.car_plate            << "\t\t" 
                << temp.status               << "\t" 
                << temp.res_date             << "\t";

            if(temp.res_time < 1000){
                cout << "0" << temp.res_time << "\t\t";
            } else { cout << temp.res_time << "\t\t"; }
            if(temp.arrival_time < 1000){
                cout << "0" << temp.arrival_time << endl;
            } else { cout << temp.arrival_time << endl; };

            ++i;
        } while (i != qry.end());
    }

    backToMenu();
}

//
// Administrative Related
//

// show price of the parking system
void Console::showPrice(){
    cout << endl << "\t--\tShow Car Park Pricing\t--" << endl << endl;

    cout << "Reserved Parking: MYR " << reserveFee << endl;
    cout << "Overstay Parking: MYR " << overstayFee << endl;
    cout << "No Show Parking : MYR " << noshowFee << endl;

    backToMenu();
}

// set price for the parking system
void Console::setPrice(){
    cout << endl << "\t--\tSet Car Park Pricing\t--" << endl << endl;

    cout << "Enter new reserved parking fee: MYR ";
    cin >> reserveFee;
    cout << "Enter new overstay parking fee: MYR ";
    cin >> overstayFee;
    cout << "Enter new no show parking fee: MYR ";
    cin >> noshowFee;

    cout << endl << "Price set successfully." << endl;
    
    backToMenu();
}

// change the car park size
void Console::editCarpark(){
    cout << endl << "\t--\tEdit Car Park Spot\t--" << endl << endl;

    int maxLevel;    
    cout << "Enter Max Level for parking: ";
    cin >> maxLevel;
    //spot.resize(maxLevel);

    int parkingSpot[maxLevel];
    for (int i = maxLevel; i > 0; i--){
        cout << "Enter total parking spot for level " << i << ": ";
        cin >> parkingSpot[i-1];
        //spot[i-1].resize(parkingSpot[i-1]);
    }

    cout << "New Parking spot layout," << endl;
    for(int x = maxLevel; x > 0; x--){
        for(int y = 0; y < parkingSpot[x-1]; y++){
            if (y < 10) {
                cout << x << "0" << y << "\t";
            } else {
                cout << x << y << "\t";
            }
        }
        cout << endl;
    }

    backToMenu();
}

// check the whole car park
void Console::showCarpark(){
    cout << endl << "\t--\tShow Car Park Information\t--" << endl << endl;
    sqlite3pp::query qry(db, "SELECT spot_id, status FROM Spot ORDER BY spot_id DESC");

    sqlite3pp::query::iterator i = qry.begin();
    if (i == qry.end()){
        cout << "No Records availables." << endl;
    } else {
        Spot temp;
        do {
            (*i).getter() >> temp.id
                        >> temp.status;

            cout << temp.id << ": " << temp.status << "\t";
            
            if (temp.id % 100 == 0){
                cout << endl;
            }
            ++i;
        } while (i != qry.end());
    }

    backToMenu();
}

// statistic of the parking system
void Console::statistic(){
    char option;

    cout << endl << "\t--\tStatistic Options\t--" << endl << endl;
    cout << "1: Day Statistic, 2: Rain Check" << endl;
    cout << "Option: ";
    cin >> option;

    if (option == '1'){
        string date;
        cout << "Enter date(YYYY-MM-DD): ";
        cin >> date;

        string tempQuery = "SELECT * FROM Log WHERE res_date = '" + date + "'";
        sqlite3pp::query qry(db, tempQuery.c_str());

        sqlite3pp::query::iterator i = qry.begin();
        if (i == qry.end()){
            cout << "No Records availables." << endl;
        } else {
            for (int i = 0; i < qry.column_count(); ++i) {
                cout << qry.column_name(i) << "\t";
            }
            cout << endl;

            Transaction temp;
            do {
                (*i).getter() >> temp.cust_id
                            >> temp.car_plate
                            >> temp.status
                            >> temp.res_date
                            >> temp.res_time
                            >> temp.arrival_time;

                cout << temp.cust_id        << "\t"
                    << temp.car_plate       << "\t\t"
                    << temp.status          << "\t"
                    << temp.res_date        << "\t";

                if(temp.res_time < 1000){
                    cout << "0" << temp.res_time << "\t\t";
                } else { cout << temp.res_time << "\t\t"; }
                if(temp.arrival_time < 1000){
                    cout << "0" << temp.arrival_time << endl;
                } else { cout << temp.arrival_time << endl; };

                ++i;
            } while (i != qry.end());
        }
    } else if (option == '2'){
        for(vector<int>::iterator i = raincheck.begin(); i != raincheck.end(); i++){
            cout << *i << ", ";
        }
        cout << endl;
    } else {
        cout << "Wrong input, back to main." << endl;
    }    
    backToMenu();
}

//
// Simulate the whole Program
//
void Console::simulate(){
    cout << endl << "\t--\tSimulate Mode\t--" << endl << endl;
    
    backToMenu();
}

//
// Terminate the Program
//
void Console::quit(){
    cout << "Thanks you for using." << endl << endl;
    cout << "Credited by, " << endl
        << "Shahmin Bin Jasni\t4636478" << endl
        << "Lim Chee Yeong\t\t4933643" << endl
        << "Liew Loo Yee\t\t4632254" << endl
        << "Hang Wen Jia\t\t4930320" << endl
        << "Ho Wei Law\t\t4632242" << endl << endl;
    exit(0);
}

//
// Menu stuff
//

// prompt Main Menu for user to choose
void Console::showMainMenu() {
    cout << "\t++++++++++++++++++++++++++++++++++++++++++++++++++"  << endl
        << "\t++\t\t\t\t\t\t++" << endl
        << "\t++\t\t" << "KPlus Parking System" << "\t\t++"         << endl
        << "\t++\t\t\t\t\t\t++" << endl
        <<  "\t++++++++++++++++++++++++++++++++++++++++++++++++++"  << endl;
    cout << "1) Parking Management"     << endl;
    cout << "2) Reservation Management" << endl;
    cout << "3) Account Management"     << endl;
    cout << "4) Administrative Menu"    << endl;
    //cout << "9) Simulation Mode"        << endl;
    cout << "0) Quit"                   << endl;
    while (true) {
        char input;
        cout << "Enter option (e.g. 1): ";
        cin >> input;
   
        switch(input) {
            case '1':
                showParkingMenu();
            case '2':
                showReservationMenu();
            case '3':
                showAccountMenu();
            case '4':
                showAdminMenu();
            case '9':
                simulate();
            case '0':
                quit();
            default:
                cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

// prompt Menu about Parking
void Console::showParkingMenu(){
    cout << "\t----------------------------------"  << endl;
    cout << "\t--\tParking Management\t--"          << endl;
    cout << "\t----------------------------------"  << endl;
    cout << "1) Arrive"                             << endl;
    cout << "2) Depart"                             << endl;
    cout << "3) Show Car Information"               << endl;
    cout << "0) Back"                               << endl;
    while (true) {
        char input;
        cout << "Enter option (e.g. 1): ";
        cin >> input;
   
        switch(input) {
            case '1':
                parkCar();
            case '2':
                leaveCar();
            case '3':
                showCar();
            case '0':
                showMainMenu();
            default:
                cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

// prompt Menu about Reservation
void Console::showReservationMenu(){
    cout << "\t----------------------------------"  << endl;
    cout << "\t--\tReservation Management\t--"      << endl;
    cout << "\t----------------------------------"  << endl;
    cout << "1) Create Reservation"                 << endl;
    cout << "2) Edit Reservation"                   << endl;
    cout << "3) Show Reservation"                   << endl;
    cout << "0) Back"                               << endl;
    while (true) {
        char input;
        cout << "Enter option (e.g. 1): ";
        cin >> input;

        switch(input){
            case '1':
                newReservation();
            case '2':
                editReservation();
            case '3':
                showReservation();
            case '0':
                showMainMenu();
            default:
                cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

// prompt Menu about Account Management
void Console::showAccountMenu(){
    cout << "\t----------------------------------"  << endl;
    cout << "\t--\tAccount Management\t--"          << endl;
    cout << "\t----------------------------------"  << endl;
    cout << "1) New Registration"                   << endl;
    cout << "2) Show Report"                        << endl;
    cout << "0) Back"                               << endl;
    while (true) {
        char input;
        cout << "Enter option (e.g. 1): ";
        cin >> input;

        switch(input){
            case '1':
                newRegistration();
            case '2':
                showReport();
            case '0':
                showMainMenu();
            default:
                cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

// prompt Menu about administration settings
void Console::showAdminMenu(){
    string id, pass;
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> pass;
    //char *pass = getpass("Enter password: ");
    if (id == "admin" && pass == "admin"){
        cout << "\t----------------------------------"  << endl;
        cout << "\t--\tAdministrative Menu\t--"         << endl;
        cout << "\t----------------------------------"  << endl;
        cout << "1) Show Price"                         << endl;
        cout << "2) Set Price"                          << endl;
        cout << "3) Edit Car Park"                      << endl;
        cout << "4) Show Car Park"                      << endl;
        cout << "5) Show Statistic"                     << endl;
        cout << "0) Back"                               << endl;

        while (true) {
            char input;
            cout << "Enter option (e.g. 1): ";
            cin >> input;

            switch(input){
                case '1': showPrice();
                case '2': setPrice();
                case '3': editCarpark();
                case '4': showCarpark();
                case '5': statistic();
                case '0': showMainMenu();
                default: cout << "Wrong input, please try again" << endl << endl;
            }
        }
    } else {
        cout << "Wrong Account. Back to Main Menu." << endl;
        backToMenu();
    }
}

// Back to Main Menu
void Console::backToMenu() {
    cin.ignore();
    cout << endl << "(Press Enter to go back)";
    cin.get();
    showMainMenu();
}
