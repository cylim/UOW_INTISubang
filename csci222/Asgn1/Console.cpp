#include <sstream> // convert string to integer, vice versa
#include <string> // stting datatype and it function
#include <conio.h> // to hide password
#include <ctime> // to do randomize
#include <algorithm> // to use random_shuffle function
#include "Console.h"

using namespace std;

// Constructors and Destructors

Console::Console() {
    // read user data and player data from file
    _userData = _FileHandler.getAllUsers();
    _playerData = _FileHandler.getAllPlayers();
}

Console::Console(const Console& orig) {
}

Console::~Console() {
}

// Navigation Functions

int Console::run() {
    cout << "Welcome to Game Monitoring and Tracking system!" << endl;
    showLogin();
    showMenu();
    return 0;
}

void Console::showLogin() {
    while (true)
    {
        string userID;
        string password;
        cout << "Enter your user ID: ";
        getline(cin, userID);
        char ch;
        cout << "Enter Password: ";
        while ( (ch = getch()) != '\r' )
        {  
            password.push_back(ch);
        }
        //password = getpass("Enter your password:");
        if (authenticate(&userID, &password)) {
            cout << "Login succeeded! " << endl;
            break;
        } else {
            cout << "Login failed!"  << endl;
        }
    }
}

void Console::showMenu() {
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl
        << "++\t\t\t\t\t\t++" << endl
        << "++\t" << "Game Monitoring and Tracking System" << "\t++" << endl
        << "++\t\t\t\t\t\t++" << endl
        <<  "++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "1) New Game" << endl;
    cout << "2) New Game(auto)" << endl;
    cout << "3) Show Player List" << endl;
    cout << "4) Add New Player" << endl;
    cout << "8) Change password" << endl;
    cout << "9) Log Out" << endl;
    cout << "0) Quit" << endl;
    while (true) {
        int input;
        cout << "Enter option (e.g. 1): ";
        cin >> input;
   
        switch(input) {
            case 1 :
                cout << endl << "\t--\tNew Game\t--" << endl << endl;
                showNewGame(false);
                break;
            case 2:
                cout << endl << "\t--\tNew Game(auto)\t--" << endl << endl;
                showNewGame(true);
                break;
            case 3:
                cout << endl << "\t--\tPlayers List\t--" << endl << endl;
                showPlayerList();
                break;
            case 4:
                cout << endl << "\t--\tAdd New Player\t--" << endl << endl;
                showAddPlayer();
                break;
            case 8:
                ChangePassword();
                break;
            case 9:
                cin.ignore();
                cout << "Logged out successfully" << endl << endl;
                run();
            case 0:
                exit(0);
            default:
                cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

void Console::ChangePassword() {
    cin.ignore();
    string newPasswordPlainText;
    while(true) {
        string strInput;
        char ch;
        cout << "Enter New Password: ";
        while ( (ch = getch()) != '\r' ){  
            strInput.push_back(ch);
        }
        cout << endl;
        //strInput = getpass("Enter new password: ");
        newPasswordPlainText = strInput;
        strInput = "";
        cout << "Confirm New Password: ";
        while ( (ch = getch()) != '\r' ){  
            strInput.push_back(ch);
        }
        cout << endl;
        //strInput = getpass("Confirm new password: ");
        if (newPasswordPlainText == strInput) {
            if (User::validatePassword(&newPasswordPlainText)){
                break;
            } else {
                cout << "Password must contain at least 8 characters and must include at least a number and a letter." << endl;
            }
        } else {
            cout << "New Password and confirm new password are not matched." << endl;
        }
    }
    _currentUser->setPasswordByPlainText(newPasswordPlainText);
    backToMenu();
}

void Console::showNewGame(bool check){
    cin.ignore();
    
    int heat[30][4];
    addPlayers(check, heat); // Add Player to game
    
    // Generate Score
    for(int i=1; i<7; i++){
        int main[20][2];
        random_shuffle(&heat[0], &heat[30]); // grouping
        cout << "Game " << i << endl;
        simulateGame(heat, main); // simulate the game result
        updateScore(main); // update score stored in _playerData
        showResult(heat, main); // print the result
        showPrize(main); // show the top 5 of each game
        
        if(i != 6){
            cout << endl << "(Press Enter to continue)";
            cin.get();
        }
    }
    showFinal();
    
    backToMenu();
}

void Console::showPlayerList(){
    cin.ignore();
    cout << "Code\tPlayer Name" << endl;
    cout << "----\t-----------" << endl;
    for(vector<Player>::iterator p = _playerData.begin(); p != _playerData.end(); p++){
        cout << p->code << "\t" << p->name << endl;
    }
    backToMenu();
}

void Console::showAddPlayer(){
    cin.ignore();
    string name;
    cout << "New Player name: ";
    cin >> name;
    
    Player p;
    p.name = name;
    p.code = _playerData.size()+1;
    p.score = 0;
    _playerData.push_back(p);
    cout << "Added Successfully." << endl;
    cout << "Code\t: " << p.code << endl;
    cout << "Name\t: " <<p.name << endl << endl;
    
    cin.ignore();
    backToMenu();
}

void Console::backToMenu() {
    cout << endl << "(Press Enter to go back)";
    cin.get();
    showMenu();
}

// Function to do the jobs

void Console::addPlayers(bool check, int heat[][4]){
    if(!check){
        for(int i=1; i<=30; i++){
            cout << "Enter "<< i <<" Player Code: ";
            cin >> heat[i-1][0];
            for(int x=0;  x<i-1; x++){
                if((heat[i-1][0] == heat[x][0]) || (heat[i-1][0]<=0) || (heat[i-1][0]>_playerData.size())){
                    if (heat[i-1][0] == heat[x][0]) {
                        cout << "Player is in the game, please try again." << endl;
                    } else {
                        cout << "Player code not available, please try again." << endl;
                    }
                    cout << "Enter " << i << " Player Code: ";
                    cin >> heat[i-1][0];
                    x = -1;
                }
            }
        }
        cin.ignore();
    } else {
        srand(time(0));
        for(int i=0; i<30; i++){
            heat[i][0] = rand() % 60 + 1;
            for(int x=0;  x<i; x++){
                if(heat[i][0] == heat[x][0]){
                    heat[i][0] = rand() % 60 + 1;
                    x = -1;
                }
            }
        }
    }
}

void Console::simulateGame(int heat[][4], int main[][2]){
    srand(time(0));
    //Generate the score for first half and second half
    for(int i=0; i<30; i++){
        heat[i][1] = rand() % 100 + 1;
        heat[i][2] = rand() % 100 + 1;
        if(heat[i][1] >= heat[i][2]){
            heat[i][3] = heat[i][1]  + _playerData.at(heat[i][0] -1).score;
        } else {
            heat[i][3] = heat[i][2]  + _playerData.at(heat[i][0] -1).score;
        }
    }
    //Sorting for final heat score
    for(int i=0; i<10; i++){
        for(int x=i+1; x<10; x++){
            if(heat[i][3] < heat[x][3]){
                swap(heat[i], heat[x]);
            }
            if(heat[10 + i][3] < heat[10 + x][3]){
                swap(heat[10+i], heat[10+x]);
            }
            if(heat[20 + i][3] < heat[20 + x][3]){
                swap(heat[20+i], heat[20+x]);
            }
        }
    }
    // populate A-Main and B-Main
    int temp[30][2];
    for(int i=0; i<30; i++){
        temp[i][0] = heat[i][0];
        temp[i][1] = heat[i][3];
    }
    // populate highest score into temp
    for(int i=0; i<30; i++){
        for(int x=i+1; x<30; x++){
            if(temp[i][1] < temp[x][1]){
                swap(temp[i], temp[x]);
            }
        }
    }
    for(int i=0; i<20; i++){
        main[i][0] = temp[i][0]; // populate by highest score
        main[i][1] = rand() % 100 + 1  + _playerData.at(main[i][0] -1).score; // generate score
        
        _playerData.at(main[i][0] -1).total += main[i][1];
    }
    // sorting for final score
    for(int i=0; i<10; i++){
        for(int x=i+1; x<10; x++){
            if(main[i][1] < main[x][1]){
                swap(main[i], main[x]);
            }
            if(main[10 + i][1] < main[10 + x][1]){
                swap(main[10+i], main[10+x]);
            }
        }
    }
}

void Console::updateScore(int main[][2]){
    for(vector<Player>::iterator p = _playerData.begin(); p != _playerData.end(); p++){
        p->score = 0;
        if( p->code == main[0][0]){
            p->score = 10;
        } else if(p->code == main[1][0]){
            p->score = 8;
        } else if(p->code == main[2][0]){
            p->score = 6;
        } else if(p->code == main[3][0]){
            p->score = 4;
        } else if(p->code == main[4][0]){
            p->score = 2;
        }
    }
}

void Console::showResult(int heat[][4], int main[][2]){
    cout << "Heat 1\tRound 1\tRound 2\tFinal\t|" 
            << "Heat 2\tRound 1\tRound 2\tFinal\t|"
            << "Heat 3\tRound 1\tRound 2\tFinal\t|" 
            << "A-Main\tScore\tB-Main\tScore" << endl;
    cout << "------\t-------\t-------\t-----\t|"
            << "------\t-------\t-------\t-----\t|"
            << "------\t-------\t-------\t-----\t|" 
            << "------\t-----\t------\t-----" << endl;
    for(int i=0; i<10; i++){
        cout << _playerData.at(heat[i][0] -1).name << "\t" << heat[i][1] << "\t" 
                << heat[i][2] << "\t" << heat[i][3] << "\t|";
        cout << _playerData.at(heat[i+10][0] -1).name << "\t" << heat[10 + i][1] << "\t" 
                << heat[10 + i][2] << "\t" << heat[10 + i][3] << "\t|";
        cout << _playerData.at(heat[i+20][0] -1).name << "\t" << heat[20 + i][1] << "\t" 
                << heat[20 + i][2] << "\t" << heat[20 + i][3] << "\t|";
        cout << _playerData.at(main[i][0] - 1).name << "\t" << main[i][1] << "\t"
                << _playerData.at(main[10+i][0] -1).name << "\t" << main[10+i][1] << endl;
    }
}

void Console::showPrize(int main[][2]){
    string trophies[6];
    cout << endl << "\t--\tResult Of The Game\t--" << endl;
    cout << "Rank\tA-Main\tScore\tB-Main\tScore" << endl;
    for(int i=0; i<5; i++){
        cout << i+1 << "\t" << _playerData.at(main[i][0] -1 ).name << "\t" << main[i][1] << "\t"
                << _playerData.at(main[10+i][0] -1).name << "\t" << main[10+i][1] << endl;
        if(i < 3) {
            trophies[i] = _playerData.at(main[i][0] -1 ).name;
            trophies[i+3] = _playerData.at(main[10+i][0] -1).name;
        }
    }
    cout << "trophies for: ";
    for(int i=0; i<6; i++){
        cout << trophies[i];
        if(i != 5){
            cout << ", ";
        } else {
            cout << endl;
        }
    }
}

void Console::showFinal(){
    string name[3];
    int score[3];
    cout << endl << "\t--\tWinner of the Game Session\t--" << endl;
    cout << "Rank\tScore\tName" << endl;
    cout << "----\t-----\t----" << endl;
    
    for(int i=0;i<3;i++){
        score[i] = 0;
        for(vector<Player>::iterator p = _playerData.begin(); p != _playerData.end(); p++){
            if(p->total > score[i]){
                if(i > 0){
                    if(p->total < score[i-1]){
                        score[i] = p->total;
                        name[i] = p->name;
                    }
                } else {
                    score[i] = p->total;
                    name[i] = p->name;
                }
            }
        }
        cout << i+1 << "\t" << name[i] << "\t" << score[i] << endl;
    }
    
    //Clean up the total score
    for(vector<Player>::iterator p = _playerData.begin(); p != _playerData.end(); p++){
        p->total = 0;
    }
}

bool Console::authenticate(string * userID, string * password){
    for(vector<User>::iterator iteratorU=_userData.begin(); iteratorU!=_userData.end(); iteratorU++) {
        if (iteratorU->userName == *userID){
            if (iteratorU->isPasswordMatched(password)){
                if (iteratorU->isEnabled == false){
                    cout << "Your account is locked." << endl;
                    return false;
                }
                iteratorU->numOfWrongAttempts = 0;
                _currentUser = iteratorU.base();
                return true;
            } else {
                iteratorU->numOfWrongAttempts ++;
                if (iteratorU->numOfWrongAttempts >= 3)
                    iteratorU->isEnabled = false;
                return false;
            }
        }
    }
    return false;
}
