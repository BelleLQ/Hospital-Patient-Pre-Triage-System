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
Filename: Patient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"

using namespace std;
namespace sdds {
	Patient::Patient(int ticketNo, bool fileIO){	
		m_patientName = nullptr;
		m_ohip = 0;
		m_ticket = new Ticket(ticketNo);
		m_fileIO = fileIO;
	}
	Patient::~Patient() {
		delete[] m_patientName;
		m_patientName = nullptr;
		delete m_ticket;
		m_ticket = nullptr;
	}
	bool Patient::fileIO()const {
		return m_fileIO;
	}
	void Patient::fileIO(bool fileIO) {
		m_fileIO = fileIO;
	}
	bool Patient::operator==(char c)const {
		return c == type();
	}
	bool Patient::operator==(const Patient& p1)const {
		return p1.type() == type();
	}
	void Patient::setArrivalTime() {
		m_ticket->resetTime();
	}
	Patient::operator Time() const {
		return Time(*m_ticket);
	}
	int Patient::number()const {
		return m_ticket->number();
	}
	ostream& Patient::csvWrite(ostream& ost)const {
		ost << type() << ',' << m_patientName << ',' << m_ohip << ',';
		m_ticket->csvWrite(ost);
		return ost;
	}
	istream& Patient::csvRead(istream& ist) {
		string tmp;
		getline(ist, tmp, ',');
		if (tmp != "\0") {
			if(m_patientName !=nullptr) delete[] m_patientName;
			m_patientName = new char[strlen(tmp.c_str()) + 1];
			strcpy(m_patientName, tmp.c_str());
			ist >> m_ohip;
			ist.ignore();
			m_ticket->csvRead(ist);
		}
		return ist;
	}
	ostream& Patient::write(ostream& ost)const {
		ost << *m_ticket << endl;
		string temp_patientName(m_patientName);
		
		if (strlen(m_patientName) > 25) ost << temp_patientName.substr(0, 25);
		else ost << m_patientName;
		ost << ", OHIP: " << m_ohip;
		return ost;
	}
	istream& Patient::read(istream& ist) {
		string tmp;
		cout << "Name: ";
		getline(ist, tmp, '\n');
		if (m_patientName != nullptr) delete[] m_patientName;
		m_patientName = new char[strlen(tmp.c_str()) + 1];
		strcpy(m_patientName, tmp.c_str());
		m_ohip=getInt(100000000, 999999999, "OHIP: ","Invalid OHIP Number, ", true);
		return ist;
	}

}