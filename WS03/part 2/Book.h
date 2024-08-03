/*************************************************************************************************************************************
Name:		    Hiu Fung CHAN
Seneca Email :	    hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :		    27 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
	class Book {
		std::string m_title{};
		unsigned m_numChapters{};
		unsigned m_numPages{};
	public:
		Book();
		Book(const std::string& title, unsigned nChapters, unsigned nPages);
		// TODO: In completing Part 1, add here the missing member prototypes that would be necessary for the 
        // Collection module code and tester module w3_p1.cpp to manage Book-type objects. 
        
		// setters
		void setTitle(const std::string& title);
		void setNumChapters(unsigned nChapters);
		void setNumPages(unsigned nPages);

		// getters
		const std::string& getTitle() const;
		unsigned getNumChapters() const;
		unsigned getNumPages() const;

		double pagesPerChapter() const;

		bool isValid() const;

		bool operator<(const Book& b) const;
		bool operator>(const Book& b) const;

		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);

}
#endif // !SENECA_BOOK_H

