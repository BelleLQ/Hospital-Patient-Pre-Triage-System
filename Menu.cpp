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
Filename: Menu.cpp
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
#include "Menu.h"
#include "utils.h"

namespace sdds {
    void Menu::display()const {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }
    Menu::Menu(const char* MenuContent, int NoOfSelections) {
        if (MenuContent != nullptr) {
            if(m_text!=nullptr) delete[] m_text;
            m_text = new char[strlen(MenuContent) + 1];
            strcpy(m_text, MenuContent);
            m_noOfSel = NoOfSelections;
        }
        else {
            delete[] m_text;
            m_text = nullptr;
            m_noOfSel = 0;
        }
    }
    Menu::Menu(const Menu& menu) {
        if (menu.m_text != nullptr) {
            m_noOfSel = menu.m_noOfSel;
            if (m_text != nullptr) delete[] m_text;
            m_text = new char[strlen(menu.m_text) + 1];
            strcpy(m_text, menu.m_text);
        }
        else {
            delete [] m_text;
            m_text = nullptr;
            m_noOfSel = 0;
        }
    }
    Menu::~Menu() {
        delete[] m_text;
    }
    int& Menu::operator>>(int& Selection) {
        display();
        Selection = getInt(0, m_noOfSel, "> ", "Invalid option ", true);
        return Selection;
    }
}
