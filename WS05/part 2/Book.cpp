/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				10 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <string>
#include "Book.h"

namespace seneca {
    std::string Book::trim(const std::string& str) {
        size_t start = 0;
        size_t end = str.size() - 1;

        while (start <= end && std::isspace(static_cast<unsigned char>(str[start]))) {
            start++;
        }

        while (end >= start && std::isspace(static_cast<unsigned char>(str[end]))) {
            end--;
        }

        if (start > end) {
            return "";
        }

        return str.substr(start, end - start + 1);
    }

	Book::Book() : m_author(""), m_title(""), m_country(""), m_year(0), m_price(0.0), m_desc("") {}

    Book::Book(const std::string& strBook) {
        size_t start = 0;
        size_t end = 0;

        end = strBook.find(',', start);
        m_author = strBook.substr(start, end - start);
        m_author = trim(m_author);
        start = end + 1;

        end = strBook.find(',', start);
        m_title = strBook.substr(start, end - start);
        m_title = trim(m_title);
        start = end + 1;

        end = strBook.find(',', start);
        m_country = strBook.substr(start, end - start);
        m_country = trim(m_country);
        start = end + 1;

        end = strBook.find(',', start);
        std::string priceStr = strBook.substr(start, end - start);
        m_price = std::stod(trim(priceStr));
        start = end + 1;

        end = strBook.find(',', start);
        std::string yearStr = strBook.substr(start, end - start);
        m_year = std::stoi(trim(yearStr));
        start = end + 1;

        m_desc = strBook.substr(start);
        m_desc = trim(m_desc);
    }

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
        return m_price;
    }

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
        os << book.m_price << " | " << book.m_desc << std::endl;
        os.unsetf(std::ios::fixed);
        os.unsetf(std::ios::right);
        
        return os;
    }
}
