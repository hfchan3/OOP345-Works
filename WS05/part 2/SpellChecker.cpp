/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              10 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>

namespace seneca {
    SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw "Bad file name!";
        }

        for (int i = 0; i < SIZE; i++) {
            file >> m_badWords[i] >> m_goodWords[i];
        }
        file.close();
    }

    void SpellChecker::operator()(std::string& text) {
        for (int i = 0; i < SIZE; i++) {
            size_t pos = text.find(m_badWords[i]);
            while (pos != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                m_replacementCounts[i]++;
                pos = text.find(m_badWords[i], pos + m_goodWords[i].length());
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        out << "Spellchecker Statistics" << std::endl;
        for (int i = 0; i < SIZE; i++) {
            out.setf(std::ios::right);
            out.width(15);
            out << m_badWords[i] << ": ";
            out.width(1);
            out << m_replacementCounts[i] << " replacements" << std::endl;
        }
    }
}
