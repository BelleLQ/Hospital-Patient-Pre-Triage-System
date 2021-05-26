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
Filename: TriagePatient.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient():Patient(nextTriageTicket) {
	   m_symptoms = nullptr;
	   nextTriageTicket ++;
   }

   char TriagePatient::type()const {
	   return 'T';
   }
   ostream& TriagePatient::csvWrite(ostream& ost)const {
	   Patient::csvWrite(ost);
	   ost << ',' << m_symptoms;
	   return ost;
   }
   istream& TriagePatient::csvRead(istream& ist) {
	   string tmp;
	   delete[] m_symptoms;
	   Patient::csvRead(ist);
	   ist.ignore();
	   getline(ist, tmp, '\n');
	   m_symptoms = new char[strlen(tmp.c_str()) + 1];
	   strcpy(m_symptoms, tmp.c_str());
	   nextTriageTicket = Patient::number() + 1;
	   return ist;
   }
   ostream& TriagePatient::write(ostream& ost)const {
	   if (fileIO()) csvWrite(ost);
	   else {
		   ost << "TRIAGE" << endl;
		   Patient::write(ost);
		   ost << endl << "Symptoms: " << m_symptoms << endl;
	   }
	   return ost;
   }
   istream& TriagePatient::read(istream& ist) {
	   string tmp;
	   if (fileIO()) csvRead(ist);
	   else {
		   delete[] m_symptoms;
		   Patient::read(ist);
		   cout << "Symptoms: ";
		   getline(ist, tmp, '\n');
		   m_symptoms = new char[strlen(tmp.c_str()) + 1];
		   strcpy(m_symptoms, tmp.c_str());
	   }
	   return ist;
   }
   TriagePatient::~TriagePatient() {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }
}