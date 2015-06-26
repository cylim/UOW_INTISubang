#include "FileHandler.h"


const string FileHandler::USER_DATA_FILE = "users.dat";
const string FileHandler::PLAYER_DATA_FILE = "players.dat";
const string FileHandler::DATA_DELIMITER = ":";

FileHandler::FileHandler() {
}

FileHandler::~FileHandler() {
}

vector<User> FileHandler::getAllUsers() {
    vector<User> vU;
    string line;
    ifstream datafile(USER_DATA_FILE.data());
    if (datafile.is_open()){
        string delimiter = DATA_DELIMITER;
        while (datafile.good()){
            getline(datafile, line);
            User u;
            vector<string> strs = FileHandler::splitString(&line, &delimiter);
            u.id = atoi(strs[0].c_str());
            u.userName = strs[1];
            u.passwordCrypted = strs[2];
            u.isEnabled = atoi(strs[3].c_str());
            vU.push_back(u);
        }
        datafile.close();
    } else {
        cout << "ERROR: User data file is missing.";
    }
    return vU;
}

vector<Player> FileHandler::getAllPlayers(){
    vector<Player> vP;
    string line;
    ifstream datafile(PLAYER_DATA_FILE.data());
    if (datafile.is_open()){
        string delimiter = DATA_DELIMITER;
        while (datafile.good()){
            getline(datafile, line);
            Player p;
            vector<string> strs = FileHandler::splitString(&line, &delimiter);
            p.code = atoi(strs[0].c_str());
            p.name = strs[1];
            p.score = atoi(strs[2].c_str());
            p.total = atoi(strs[3].c_str());
            vP.push_back(p);
        }
        datafile.close();
    } else {
        cout << "ERROR: Player data file is missing.";
    }

    return vP;
}

vector<string> FileHandler::splitString(string * str, string * delimiter) {
    // split by delimiter
    vector<string> vStr;
    string curStr = *str;
    while (!curStr.empty()){
        int index = curStr.find_first_of(*delimiter);
        if (index != -1){
            vStr.push_back(curStr.substr(0, index));
            curStr = curStr.substr(index + 1, string::npos);
        } else {
            vStr.push_back(curStr.substr(0, string::npos));
            curStr = "";
        }
    }
    return vStr;
}