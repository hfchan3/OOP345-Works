/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/

#include <iostream>
#include <string>
#include "Book.h"

namespace seneca {
	Book::Book() : m_title(""), m_numChapters(0), m_numPages(0) {}

	Book::Book(const std::string& title, unsigned nChapters, unsigned nPages) : m_title(title), m_numChapters(nChapters), m_numPages(nPages) {}

	void Book::setTitle(const std::string& title) {
		m_title = title;
	}

	void Book::setNumChapters(unsigned nChapters) {
		m_numChapters = nChapters;
	}

	void Book::setNumPages(unsigned nPages) {
		m_numPages = nPages;
	}

	const std::string& Book::getTitle() const {
		return m_title;
	}

	unsigned Book::getNumChapters() const {
		return m_numChapters;
	}

	unsigned Book::getNumPages() const {
		return m_numPages;
	}

	double Book::pagesPerChapter() const {
		if (m_numChapters == 0) {
			return 0.0;
		}
		return static_cast<double>(m_numPages) / m_numChapters;
	}

	bool Book::isValid() const {
		return !m_title.empty() && m_numChapters > 0 && m_numPages > 0;
	}

	std::ostream& Book::print(std::ostream& os) const {
		if (isValid()) {
			std::string firstField = m_title + "," + std::to_string(m_numChapters) + "," + std::to_string(m_numPages);
			std::string secondField = "(" + std::to_string(pagesPerChapter()) + ")";
			os.width(56);
			os.setf(std::ios::right);
			os << firstField << " | ";
			os.unsetf(std::ios::right);
			os.setf(std::ios::left);
			os.width(15);
			os << secondField;
			os.unsetf(std::ios::left);
		}
		else {
			os << "| Invalid book data";
		}
		return os;
	}

	bool Book::operator<(const Book& b) const {
		return pagesPerChapter() < b.pagesPerChapter();
	}

	bool Book::operator>(const Book& b) const {
		return pagesPerChapter() > b.pagesPerChapter();
	}

	std::ostream& operator<<(std::ostream& os, const Book& bk) {
		return bk.print(os);
	}

}