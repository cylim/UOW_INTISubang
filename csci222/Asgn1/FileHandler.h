/* 
 * File:   TextFileRepository.h
 * Author: CheeYeong
 *
 * Created on May 18, 2015, 10:47 PM
 */
#ifndef TEXTFILEREPOSITORY_H
#define	TEXTFILEREPOSITORY_H
#include "common.h"
#include <iostream>
#include <fstream>

using namespace std;

class FileHandler {
    public:
        FileHandler();
        virtual ~FileHandler();
        vector<User> getAllUsers(); // Get all user data into user vector
        vector<Player> getAllPlayers(); // get all player data in player vector
    private:
        static const string USER_DATA_FILE;
        static const string DATA_DELIMITER;
        static const string PLAYER_DATA_FILE;
        static vector<string> splitString(string * str, string * delimiter); // split string with ":"
};

#endif	/* TEXTFILEREPOSITORY_H */