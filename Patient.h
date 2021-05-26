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
Filename: Patient.h
Version 1.0
Author	Yu-Hsuan Liao
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/26  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient : public IOAble {
		char* m_patientName;
		int m_ohip;
		Ticket* m_ticket;
		bool m_fileIO;
	public:
		Patient(int ticketNo = 0, bool fileIO = false);
		Patient(const Patient&) = delete;
		~Patient();
		virtual char type()const = 0;
		bool fileIO()const;
		void fileIO(bool fileIO);
		bool operator==(char c)const;
		bool operator==(const Patient& p1)const;
		void setArrivalTime();
		operator Time() const;
		int number()const;
		ostream& csvWrite(ostream& ost)const;
		istream& csvRead(istream& ist);
		ostream& write(ostream& ost)const;
		istream& read(istream& ist);
	};
}
#endif