#include "User.h"


const string User::ALPHABET_LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string User::NUMBER_DIGITS = "0123456789";
const int User::CAESAR_CIPHER_OFFSET = 9;

User::User() {
    numOfWrongAttempts = 0;
}

void User::setPasswordByPlainText(string password) {
    this->passwordCrypted = encrptByCaesarCipher(password);
    cout << "Password changed successfully.";
}

bool User::isPasswordMatched(string * passwordPlainText) {
    string encrpyted = encrptByCaesarCipher(*passwordPlainText);
    return encrpyted == passwordCrypted;
}

bool User::validatePassword(string * password) {
    if (password->size() < 8)
        return false;
    bool hasAlphabet = false;
    bool hasNumber = false;
    const char * chars = password->c_str();
    int length = password->length();
    for (int i = 0; i<length; i++) {
        if (ALPHABET_LETTERS.find_first_of(toupper(chars[i])) != -1)
            hasAlphabet = true;
        else if (NUMBER_DIGITS.find_first_of(chars[i]) != -1)
            hasNumber = true;
        if (hasAlphabet && hasNumber)
            break;
    }
    return hasAlphabet && hasNumber;
}

string User::encrptByCaesarCipher(string plainText) {
    string passwordCrypted;
    int difference = CAESAR_CIPHER_OFFSET;
    int crypted;
    int real_difference;
    int i = 0;

    if (difference > 26) { //Brings back the number if above 26
        real_difference = difference % 26;
    } else {
        real_difference = difference;
    }

    while (i <= plainText.length()) { //Converts each letter
        if (plainText[i] == 32) { // Detect if the letter is a space
            crypted = plainText[i];
            passwordCrypted += (char) crypted;
            i++;
        }


        if ((plainText[i] + real_difference) > 'z') {//detect if the crypted letter is above 'z'
            crypted = (plainText[i] + real_difference) - 'z' + 'a' - 1;
        } else {
            crypted = plainText[i] + real_difference;
        }

        if (NUMBER_DIGITS.find_first_of(plainText[i]) != -1) {
            crypted = plainText[i]; // do not encrypt number
        }

        passwordCrypted += (char) crypted;
        i++;

        if (i >= plainText.length()) //If the string is finished
            break;
    }
    return passwordCrypted;
}
