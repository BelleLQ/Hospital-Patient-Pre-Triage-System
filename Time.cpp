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
Filename: Time.cpp
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
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Time& Time::setToNow() {
        m_min = getTime();
        return *this;
    }
    Time::Time(unsigned int min) {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const {
        int hh = m_min / 60;
        int mm = m_min % 60;
        ostr.fill('0');
        ostr.width(2);
        ostr << hh;
        ostr << ":";
        ostr.width(2);
        ostr << mm;
        return ostr;
    }
    std::istream& Time::read(std::istream& istr) {
        /*std::string str;
        getline(istr, str,'\n');
        char* hhmm = new char[strlen(str.c_str()) + 1];
        strcpy(hhmm, str.c_str());
        if (hasColon(hhmm)) {
            char hh[5] = { 0 }, mm[5] = { 0 };
            unsigned i, idx=0;
            for (i = 0; hhmm[i] != ':'; i++) {
                hh[i] = hhmm[i];
                idx++;
            }
            hh[i] = '\0';
            idx++;
            for (i=0; i<strlen(hhmm)-idx; i++) {
                mm[i] = hhmm[i+idx];
            }
            mm[i] = '\0';
            if (isNumber(hh) && isNumber(mm)) {
                int H = stoi(hh), M = stoi(mm);
                if ((H == 0 && M == 0) || H < 0 || M < 0) istr.setstate(ios::failbit);
                else {
                    m_min = 60 * H + M;
                }
            }
            else istr.setstate(ios::failbit);
        }
        else istr.setstate(ios::failbit);
       
        delete[] hhmm;
        
        return istr;*/
        int h = 0;
        int m = 0;
        char colon = '0';
        istr >> h;
        istr >> colon;
        istr >> m;
        if (h < 0 || colon != ':' || m < 0 || (h == 0 && m == 0)) {
            istr.setstate(ios::failbit);
        }
        m_min = h * 60 + m;
        return istr;
    }
    Time& Time::operator-=(const Time& D) {
        if (m_min < (D.m_min % 1440)) m_min += 1440;
            m_min -= (D.m_min % 1440);
        return *this;
    }
    Time Time::operator-(const Time& D)const {
        Time dif;
        dif.m_min = m_min;
        if (dif.m_min < (D.m_min % 1440)) dif.m_min += 1440;
        dif.m_min -= (D.m_min % 1440);

        return dif;
    }
    Time& Time::operator+=(const Time& D) {
        m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const {
        Time dif;
        dif.m_min = m_min + D.m_min;
        return dif;
    }
    Time& Time::operator=(unsigned int val) {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val) {
        m_min *= val;
        return *this;
    }
    Time& Time::operator /= (unsigned int val) {
        m_min /= val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const {
        Time mult;
        mult.m_min = m_min * val;
        return mult;
    }
    Time Time::operator /(unsigned int val)const {
        Time div;
        div.m_min = m_min / val;
        return div;
    }

    Time::operator unsigned int()const {
        return m_min;
    }
    Time::operator int()const {
        return (int)m_min;
    }
std::ostream& operator<<(std::ostream& ostr, const Time& D) {
    D.write(ostr);
    return ostr;
}
std::istream& operator>>(std::istream& istr, Time& D) {
    D.read(istr);
    return istr;
}
}