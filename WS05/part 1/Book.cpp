#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <string>
#include "Book.h"

namespace seneca {
    std::string Book::trim(const std::string& str) {
        size_t start = 0;
        size_t end = str.size() - 1;

        // Find the position of the first non-space character from the start
        while (start <= end && std::isspace(static_cast<unsigned char>(str[start]))) {
            start++;
        }

        // Find the position of the first non-space character from the end
        while (end >= start && std::isspace(static_cast<unsigned char>(str[end]))) {
            end--;
        }

        // If all characters are spaces, start will be greater than end
        if (start > end) {
            return "";
        }

        // Return the substring that contains no leading or trailing spaces
        return str.substr(start, end - start + 1);
    }

	Book::Book() : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_description("") {}

    Book::Book(const std::string& strBook) {
        size_t start = 0;
        size_t end = 0;

        // Extract author
        end = strBook.find(',', start);
        m_author = strBook.substr(start, end - start);
        m_author = trim(m_author);
        start = end + 1;

        // Extract title
        end = strBook.find(',', start);
        m_title = strBook.substr(start, end - start);
        m_title = trim(m_title);
        start = end + 1;

        // Extract country
        end = strBook.find(',', start);
        m_country = strBook.substr(start, end - start);
        m_country = trim(m_country);
        start = end + 1;

        // Extract price
        end = strBook.find(',', start);
        std::string priceStr = strBook.substr(start, end - start);
        m_price = std::stod(trim(priceStr));
        start = end + 1;

        // Extract year
        end = strBook.find(',', start);
        std::string yearStr = strBook.substr(start, end - start);
        m_year = std::stoi(trim(yearStr));
        start = end + 1;

        // Extract description
        m_description = strBook.substr(start);
        m_description = trim(m_description);
    }

    // Query functions
    const std::string& Book::title() const {
        return m_title;
    }

    const std::string& Book::country() const {
        return m_country;
    }

    const size_t& Book::year() const {
        return m_year;
    }

    double& Book::price() {
        return m_price; // Allow modification of the price
    }

    // Friend function to overload the insertion operator
    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os.setf(std::ios::right);
        os.width(20);
        os << book.m_author << " | ";
        os.width(22);
        os << book.m_title << " | ";
        os.width(5);
        os << book.m_country << " | " << book.m_year << " | ";
        os.width(6);
        os.setf(std::ios::fixed);
        os.precision(2);
        os << book.m_price << " | " << book.m_description;
        os.unsetf(std::ios::fixed);
        os.unsetf(std::ios::right);
        
        return os;
    }
}
