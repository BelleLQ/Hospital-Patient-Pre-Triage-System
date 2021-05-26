///==============================================
// Name:           Yu-Hsuan Liao
// Student Number: 160096194
// Email:          yliao39@myseneca.ca
// Section:        NCC
// Date:           Apr. 11
// Workshop:       Project M5
//==============================================
/* Citation and Sources
Final Project Milestone 5
Filename: IOAble.cpp
Version 1.0
Author	Yu-Hsuan Liao
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/22  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "IOAble.h"
using namespace std;
namespace sdds {
	ostream& operator<<(ostream& ost, const IOAble& ioa) {
		ioa.write(ost);
		return ost;
	}
	istream& operator>>(istream& ist, IOAble& ioa) {
		ioa.read(ist);
		return ist;
	}
}
