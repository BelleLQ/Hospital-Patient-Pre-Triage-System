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
Filename: PreTriage.cpp
Version 1.0
Author	Yu-Hsuan Liao
Revision History
-----------------------------------------------------------
Date      Reason
2021/4/11  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
using namespace std;
namespace sdds {
    void PreTriage::reg() {
        int selection = 0;
        if (m_lineupSize < maxNoOfPatients) {
            if (m_pMenu >> selection) {
                if (selection == 1) m_lineup[m_lineupSize] = new CovidPatient();
                else if (selection == 2) m_lineup[m_lineupSize] = new TriagePatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                m_lineup[m_lineupSize]->fileIO(false);
                cout << "Please enter patient information: "<<endl;
                m_lineup[m_lineupSize]->read(cin);
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[m_lineupSize]->write(cout);
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl<<endl;
                m_lineupSize++;
            }
        }
        else cout << "Line up full!" << endl;
    }
    void PreTriage::admit() {
        int selection = 0;
        char type = 'A';
        int index = -1;
        if (m_pMenu >> selection) {
            if (selection == 1) type = 'C';
            else if (selection == 2) type = 'T';
            index = indexOfFirstInLine(type);
            if (index > -1) {
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[index]->fileIO(false);
                cout << "Calling for ";
                m_lineup[index]->write(cout);
                cout << "******************************************" << endl<<endl;
                setAverageWaitTime(*m_lineup[index]);
                removePatientFromLineup(index);
            }
           
        }
    }
    const Time PreTriage::getWaitTime(const Patient& p)const {
        unsigned count = 0;
        Time estimatedwaiting;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == p.type()) count++;
        }
        if (p.type() == 'C') estimatedwaiting = m_averCovidWait;
        else estimatedwaiting = m_averTriageWait;
        return estimatedwaiting * count;
    }
    void PreTriage::setAverageWaitTime(const Patient& p) {
        Time ct = getTime();
        Time ptt = Time(p);
        unsigned ptn = p.number();
        if (p.type() == 'C') {
            m_averCovidWait = ((ct - ptt) + ((m_averCovidWait) * (ptn - 1))) / ptn;
        }
        else {
            m_averTriageWait = ((ct - ptt) + ((m_averTriageWait) * (ptn - 1))) / ptn;
        }
    }
    void PreTriage::removePatientFromLineup(int index) {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }
    int PreTriage::indexOfFirstInLine(char type) const {
        int index = -1;
        for (int i = 0; i < m_lineupSize && index==-1 ; i++) {
            if (m_lineup[i]->type() == type) index = i;
        }
        return index;
    }
    void PreTriage::load() {
        ifstream fin(m_dataFilename);
        int i = 0;
        cout << "Loading data..." << endl;
        if (fin.is_open()) {
            Time tempCovid, tempTriage;
            fin >> tempCovid;
            fin.ignore();
            fin >> tempTriage;
            fin.ignore();
            while (fin && i< maxNoOfPatients) {
                char c = 'A';
                fin.get(c); 
                if (fin && c != '\0') {
                    if (c == 'C') m_lineup[i] = new CovidPatient();
                    else if (c == 'T') m_lineup[i] = new TriagePatient();
                    if (c == 'C' || c == 'T') {
                        fin.ignore();
                        m_lineup[i]->fileIO(true);
                        m_lineup[i]->csvRead(fin);
                        m_lineup[i]->fileIO(false);
                        m_lineupSize++;
                        i++;
                    }
                }
            }
            if (fin) cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            if (i == 0) cout << "No data or bad data file!"<<endl<<endl;
            if (i != 0) {
                m_averCovidWait = tempCovid;
                m_averTriageWait = tempTriage;
                cout << i << " Records imported..."<<endl<<endl;
            }
        }
        

    }
    PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
        if (dataFilename != nullptr) {
            delete[] m_dataFilename;
            m_dataFilename = new char[strlen(dataFilename) + 1];
            strcpy(m_dataFilename, dataFilename);
        }
        m_lineupSize = 0;
        load();
    }
    PreTriage::~PreTriage() {
        ofstream fout(m_dataFilename);
        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;
        cout << "Saving m_lineup..." << endl;
        if (fout.is_open()) {
            fout << m_averCovidWait << "," << m_averTriageWait << endl;
        }
        for (int i = 0; i < m_lineupSize; i++) {
            m_lineup[i]->csvWrite(fout);
            fout << endl;
            cout << i+1 << "- ";
            m_lineup[i]->csvWrite(cout);
            cout << endl;
            /*fout << m_lineup[i];

            cout << m_lineup[i];*/
            delete m_lineup[i];
            m_lineup[i] = nullptr;
        }
        fout.close();
        delete[] m_dataFilename;
        m_dataFilename = nullptr;
        cout << "done!" << endl;
    }
    void PreTriage::run(void) {
        int selection = 0;
        while (m_appMenu >> selection) {
            if (selection == 1) reg();
            else if (selection == 2) admit();
        }
    }
}