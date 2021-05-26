//==============================================
// Name:           Yu-Hsuan Liao
// Student Number: 160096194
// Email:          yliao39@myseneca.ca
// Section:        NCC
// Date:           Apr. 11
// Workshop:       Project M5
//==============================================
/* Citation and Sources
Final Project Milestone 5
Filename: utils.cpp
Version 1.0
Author	Yu-Hsuan Liao
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/16  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }
    bool hasNumber(string src) {
        bool isNumber = false;
        for (unsigned i = 0; i < src.length(); i++) {
            if (src[i] == '0' || src[i] == '1' || src[i] == '2' || src[i] == '3' || src[i] == '4' || src[i] == '5' || src[i] == '6' || src[i] == '7'
                || src[i] == '8' || src[i] == '9') isNumber = true;
        }
        return isNumber;
    }
    bool isNumber(char* src) {
        bool isNumber = true;
        for (unsigned i = 0; i < strlen(src); i++) {
            if (src[i] != '0' && src[i] != '1' && src[i] != '2' && src[i] != '3' && src[i] != '4' && src[i] != '5' && src[i] != '6' && src[i] != '7'
                && src[i] != '8' && src[i] != '9') isNumber = false;
        }
        return isNumber;
    }
    bool isDigit(char src) {
        bool isDigit = false;
        if (src == '0' || src == '1' || src == '2' || src == '3' || src == '4' || src == '5' || src == '6' || src == '7'
            || src == '8' || src == '9') isDigit = true;
        if (src == ' ') isDigit = false;
        return isDigit;
    }

    int getInt(const char* prompt) {
        int result;
        if (prompt != nullptr) cout << prompt;
        string input;
        getline(cin, input, '\n');
        while (!hasNumber(input.c_str())) {
            cout << "Bad integer value, try again: ";
            getline(cin, input, '\n');
        }
        while (!isDigit(input.c_str()[input.length() - 1])) {
            cout << "Enter only an integer, try again: ";
            getline(cin, input, '\n');
            while (!hasNumber(input.c_str())) {
                cout << "Bad integer value, try again: ";
                getline(cin, input, '\n');
            }
            
        }
        result = stoi(input.c_str());
        return result;
    }
    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {
        if (prompt != nullptr) cout << prompt;
        int intGot = getInt();
        while (intGot<min || intGot>max) {
            if (errorMessage != nullptr) cout << errorMessage;
            if (showRangeAtError)cout << "[" << min << " <= value <= " <<max<< "]: ";
            intGot = getInt();
        }
        return intGot;
    }
    char* getcstr(const char* prompt, std::istream& istr, char delimiter) {
        if (prompt != nullptr) cout << prompt;
        string str;
        getline(istr, str);
        char* cstr = new char[strlen(str.c_str()) + 1];
        strcpy(cstr, str.c_str());
        return cstr;
    }
    bool hasColon(char* src) {
        bool hasColon = false;
        for (unsigned i = 0; i < strlen(src); i++) {
            if (src[i] == ':') hasColon = true;
        }
        return hasColon;
    }
    
}
