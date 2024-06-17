/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				10 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <iostream>
#include <string>

namespace seneca {

    class Movie {
        std::string m_title;
        unsigned int m_year;
        std::string m_description;

        void trim(std::string& str);

    public:
        Movie();
        const std::string& title() const;
        Movie(const std::string& strMovie);

        template<typename T>
        void fixSpelling(T& spellChecker) {
            spellChecker(m_title);
            spellChecker(m_description);
        }

        friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
    };
}

#endif // !SENECA_MOVIE_H
