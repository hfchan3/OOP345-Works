#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <string>
#include <iostream>

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

		bool isValid() const;

		std::ostream& print(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const Book& bk);
}
#endif // !SENECA_BOOK_H

