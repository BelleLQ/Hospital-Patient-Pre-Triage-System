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
Filename: CovidPatient.cpp
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
#include"CovidPatient.h"
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient():Patient(nextCovidTicket) {
	   nextCovidTicket++;
	}
   char CovidPatient::type()const {
	   return 'C';
	}
   istream& CovidPatient::csvRead(istream& ist) {
	   Patient::csvRead(ist);
	   nextCovidTicket = Patient::number() + 1;
	   ist.ignore();
	   return ist;
	}
   ostream& CovidPatient::write(ostream& ost)const {
	   if (fileIO()) {
		   Patient::csvWrite(ost);
	   }
	   else {
		   ost << "COVID TEST" << endl;
		   Patient::write(ost) << endl;
	   }
	   return ost;
	}
   istream& CovidPatient::read(istream& ist) {
	   if (fileIO()) {
		   csvRead(ist);
	   }
	   else {
		   Patient::read(ist);
	   }
	   return ist;
	}
}