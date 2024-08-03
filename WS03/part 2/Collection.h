/*************************************************************************************************************************************
Name:			    Hiu Fung CHAN
Seneca Email :	    hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <string>
#include "Book.h"

namespace seneca {
    template <typename T, unsigned C>
    class Collection {
    protected:
        T m_items[C];
        unsigned m_size = 0;
        static T m_smallestItem;
        static T m_largestItem;

        void setSmallestItem(const T& item);
        void setLargestItem(const T& item);
        T& operator[](unsigned index);
        void incrSize();

    public:
        Collection() = default;

        static T getSmallestItem() {
            return m_smallestItem;
        }

        static T getLargestItem() {
            return m_largestItem;
        }

        unsigned size() const {
            return m_size;
        }

        unsigned capacity() const {
            return C;
        }

        virtual bool operator+=(const T& item);

        virtual void print(std::ostream& os) const;
    };

    // Static member initialization for generic types
    template <typename T, unsigned C>
    T Collection<T, C>::m_smallestItem = T(9999);

    template <typename T, unsigned C>
    T Collection<T, C>::m_largestItem = T(-9999);

    // Static member initialization for Book type with capacity 10
    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

    // Static member initialization for Book type with capacity 72
    template <>
    Book Collection<Book, 72>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 72>::m_largestItem = Book("", 10000, 1);

    // Protected member functions
    template <typename T, unsigned C>
    void Collection<T, C>::setSmallestItem(const T& item) {
        if (item < m_smallestItem) {
            m_smallestItem = item;
        }
    }

    template <typename T, unsigned C>
    void Collection<T, C>::setLargestItem(const T& item) {
        if (item > m_largestItem) {
            m_largestItem = item;
        }
    }

    template <>
    void Collection<Book, 10>::setSmallestItem(const Book& item) {
        if (item.pagesPerChapter() < m_smallestItem.pagesPerChapter()) {
            m_smallestItem = item;
        }
    }

    template <>
    void Collection<Book, 10>::setLargestItem(const Book& item) {
        if (item.pagesPerChapter() > m_largestItem.pagesPerChapter()) {
            m_largestItem = item;
        }
    }

    template <typename T, unsigned C>
    T& Collection<T, C>::operator[](unsigned index) {
        return m_items[index];
    }

    template <typename T, unsigned C>
    void Collection<T, C>::incrSize() {
        if (m_size < C) {
            m_size++;
        }
    }

    // Public member functions
    template <typename T, unsigned C>
    bool Collection<T, C>::operator+=(const T& item) {
        if (m_size >= C) {
            return false;
        }
        setSmallestItem(item);
        setLargestItem(item);
        m_items[m_size++] = item;
        return true;
    }

    // Specialization of print() for Book type with capacity 10 and 72
    template <>
    void Collection<Book, 10>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (unsigned i = 0; i < m_size; ++i) {
            os << "| ";
            os.setf(std::ios::right);
            os.width(56);
            os << m_items[i].getTitle() + "," + std::to_string(m_items[i].getNumChapters()) + "," + std::to_string(m_items[i].getNumPages());
            os << " | (";
            os.unsetf(std::ios::right);
            os.setf(std::ios::fixed);
            os.width(9);
            os.precision(6);
            os << m_items[i].pagesPerChapter() << ")     |\n";
            os.unsetf(std::ios::fixed);
        }
        os << "| ---------------------------------------------------------------------------|\n";
    }

    template <>
    void Collection<Book, 72>::print(std::ostream& os) const {
        os << "| ---------------------------------------------------------------------------|\n";
        for (unsigned i = 0; i < m_size; i++) {
            os << "| ";
            os.setf(std::ios::right);
            os.width(56);
            os << m_items[i].getTitle() + "," + std::to_string(m_items[i].getNumChapters()) + "," + std::to_string(m_items[i].getNumPages());
            os << " | (";
            os.unsetf(std::ios::right);
            os.setf(std::ios::fixed);
            os.width(9);
            os.precision(6);
            os << m_items[i].pagesPerChapter() << ")     |\n";
            os.unsetf(std::ios::fixed);
        }
        os << "| ---------------------------------------------------------------------------|\n";
    }

    // Generic print function
    template <typename T, unsigned C>
    void Collection<T, C>::print(std::ostream& os) const {
        os << "[";
        for (unsigned i = 0; i < m_size; ++i) {
            os << m_items[i];
            if (i < m_size - 1) {
                os << ",";
            }
        }
        os << "]" << std::endl;
    }
}

#endif // !SENECA_COLLECTION_H

