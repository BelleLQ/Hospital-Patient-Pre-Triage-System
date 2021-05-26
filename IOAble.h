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
Filename: IOAble.h
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
#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_

#include "utils.h"

namespace sdds {
	class IOAble {
	public:
		virtual ostream& csvWrite(ostream& ost)const = 0 ;
		virtual istream& csvRead(istream& ist) = 0;
		virtual ostream& write(ostream& ost)const = 0;
		virtual istream& read(istream& ist) = 0;
		virtual ~IOAble() {};
	};
	ostream& operator<<(ostream& ost, const IOAble& ioa);
	istream& operator>>(istream& ist, IOAble& ioa);

}
#endif // !SDDS_IOABLE_H_

