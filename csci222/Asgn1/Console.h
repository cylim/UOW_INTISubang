/* 
 * File:   Console.h
 * Author: CheeYeong
 *
 * Created on May 18, 2015, 10:49 PM
 */

#ifndef CONSOLE_H
#define	CONSOLE_H

#include <iostream>
#include "common.h"
#include "FileHandler.h"

class Console {
    public:
        Console();
        Console(const Console& orig);
        virtual ~Console();
        int run();
        bool authenticate(string * userID, string * password); // check the login credentials
    private:
        void showLogin(); // prompt to ask user to login
        void showMenu(); // prompt Menu for user to choose
        void showNewGame(bool); // simulate the game
        void showPlayerList(); // show the player list
        void showAddPlayer(); // prompt to ask user to add new player
        void ChangePassword(); // prompt to change password
        void backToMenu(); // back to showMenu())
        
        void addPlayers(bool, int[][4]); // internal function, add player to game
        void simulateGame(int[][4], int[][2]); // to create random score and print out
        void showResult(int[][4], int[][2]); // print out the result
        void updateScore(int[][2]); // update score for _playerData
        void showPrize(int[][2]); // Show top 3 in total score
        void showFinal(); // To show the final winner of the game session
        FileHandler _FileHandler;
        User * _currentUser;
        vector<User> _userData;
        vector<Player> _playerData;
};
#endif	/* CONSOLE_H */

