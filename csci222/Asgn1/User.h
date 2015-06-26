/* 
 * File:   User.h
 * Author: CheeYeong
 *
 * Created on May 18, 2015, 10:39 PM
 */

#ifndef USER_H
#define	USER_H
#include "common.h"

using namespace std;

class User {
    public:
        User();
        int id;
        string userName;
        string passwordCrypted;
        bool isEnabled;
        int numOfWrongAttempts;
        void setPasswordByPlainText(string password); // called from class Console, due to user input password is plain text
        bool isPasswordMatched(string * passwordPlainText); // to check the input password is matched to the data or not
        static bool validatePassword(string * password); // checking whether the password matched the password rules
    private:
        static const string ALPHABET_LETTERS;
        static const string NUMBER_DIGITS;
        static const int CAESAR_CIPHER_OFFSET;
        static string encrptByCaesarCipher(string plainText); // encrypt the plain text using Caesar Cipher
};
#endif	/* USER_H */