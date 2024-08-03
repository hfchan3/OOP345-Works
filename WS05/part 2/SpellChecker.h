/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              10 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace seneca {
    class SpellChecker {
    private:
        const static int SIZE = 6;
        std::string m_badWords[SIZE];
        std::string m_goodWords[SIZE];
        int m_replacementCounts[SIZE] = { 0 };

    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif // SENECA_SPELLCHECKER_H
