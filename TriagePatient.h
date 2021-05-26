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
Filename: TriagePatient.h
Version 1.0
Author	Yu-Hsuan Liao
Revision History
-----------------------------------------------------------
Date      Reason
2021/4/2  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
	class TriagePatient : public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		char type()const;
		ostream& csvWrite(ostream& ost)const;
		istream& csvRead(istream& ist);
		ostream& write(ostream& ost)const;
		istream& read(istream& ist);
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


