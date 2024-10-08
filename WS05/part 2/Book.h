/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              10 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>

namespace seneca {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price;
		std::string m_desc;

		std::string trim(const std::string& str);

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_desc);
		}

		friend std::ostream& operator<<(std::ostream& os, const Book& book);
	};
}
#endif // !SENECA_BOOK_H
