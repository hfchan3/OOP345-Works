/*************************************************************************************************************************************
Name:              Hiu Fung CHAN
Seneca Email:      hfchan3@myseneca.ca
Seneca Student ID: 106184237
Date:              19 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
**************************************************************************************************************************************/
#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <iostream>
#include <fstream>
#include <utility>
#include <chrono>
#include <string>

namespace seneca {
    class ProteinDatabase {
        std::string* m_proteinArr{};
        size_t m_numProteins{};
    public:
        ProteinDatabase();
        ProteinDatabase(const std::string fileName);
        // Copy constructor
        ProteinDatabase(const ProteinDatabase& src);
        // Copy assignment operator
        ProteinDatabase& operator=(const ProteinDatabase& src);
        ~ProteinDatabase();

        size_t size() const;
        std::string operator[](size_t index) const;
    };
}

#endif // !SENECA_PROTEINDATABASE_H