#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <climits>
#include <cfloat>
#include "Book.h"

namespace seneca {
    template <typename T, unsigned C>
    class Collection {
        T m_items[C];
        unsigned m_size = 0;
        static T m_smallestItem;
        static T m_largestItem;

    protected:
        void setSmallestItem(const T& item) {
            if (item < m_smallestItem) {
                m_smallestItem = item;
            }
        }

        void setLargestItem(const T& item) {
            if (item > m_largestItem) {
                m_largestItem = item;
            }
        }

    public:
        Collection() = default;

        unsigned size() const {
            return m_size;
        }

        unsigned capacity() const {
            return C;
        }

        bool operator+=(const T& item) {
            if (m_size < C) {
                m_items[m_size++] = item;
                setSmallestItem(item);
                setLargestItem(item);
                return true;
            }
            return false;
        }

        void print(std::ostream& os) const {
            os << "[";
            for (unsigned i = 0; i < m_size; ++i) {
                os << m_items[i];
                if (i < m_size - 1) {
                    os << ",";
                }
            }
            os << "]" << std::endl;
        }

        static T getSmallestItem() {
            return m_smallestItem;
        }

        static T getLargestItem() {
            return m_largestItem;
        }
    };

    // Template specializations for Book type and capacity 10
    template <>
    Book Collection<Book, 10>::m_smallestItem = Book("", 1, 10000);

    template <>
    Book Collection<Book, 10>::m_largestItem = Book("", 10000, 1);

    template <>
    int Collection<int, 10>::m_smallestItem = INT_MAX;

    template <>
    int Collection<int, 10>::m_largestItem = INT_MIN;

    template <>
    double Collection<double, 10>::m_smallestItem = DBL_MAX;

    template <>
    double Collection<double, 10>::m_largestItem = DBL_MIN;
}

#endif // !SENECA_COLLECTION_H

