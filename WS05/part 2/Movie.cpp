/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              10 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "Movie.h"
#include <iomanip>
#include <string>
#include <iostream>

namespace seneca {
    Movie::Movie() : m_title(""), m_year(0), m_description("") {}

    const std::string& Movie::title() const {
        return m_title;
    }

    Movie::Movie(const std::string& strMovie) {
        size_t pos = strMovie.find(',');
        m_title = strMovie.substr(0, pos);
        m_title.erase(0, m_title.find_first_not_of(' '));
        m_title.erase(m_title.find_last_not_of(' ') + 1);

        size_t nextPos = strMovie.find(',', pos + 1);
        m_year = std::stoi(strMovie.substr(pos + 1, nextPos - pos - 1));

        m_description = strMovie.substr(nextPos + 1);
        m_description.erase(0, m_description.find_first_not_of(' '));
        m_description.erase(m_description.find_last_not_of(' ') + 1);
    }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os.setf(std::ios::right);
        os.width(40);
        os << movie.m_title << " | ";
        os.unsetf(std::ios::right);
        os.width(4);
        os << movie.m_year << " | " << movie.m_description << std::endl;

        return os;
    }
}
