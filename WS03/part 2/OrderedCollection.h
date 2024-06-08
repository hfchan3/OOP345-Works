/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_ORDEREDCOLLECTION_H
#define SENECA_ORDEREDCOLLECTION_H

#include <iostream>
#include <string>
#include "Collection.h"

namespace seneca {
    template <typename T>
    class OrderedCollection : public Collection<T, 72> {
    public:
        bool operator+=(const T& item);
        void print(std::ostream& os) const;
    };

    template <typename T>
    bool OrderedCollection<T>::operator+=(const T& item) {
        bool result = false;
        if (this->size() < this->capacity()) {
            unsigned i = 0;
            // Find the correct position for the new item
            while (i < this->size() && !(item < (*this)[i])) {
                i++;
            }

            // Shift elements to the right to make space for the new item
            for (unsigned j = this->size(); j > i; j--) {
                (*this)[j] = (*this)[j - 1];
            }

            // Insert the new item
            (*this)[i] = item;
            this->incrSize();

            // Update smallest and largest item if necessary
            if (item < this->getSmallestItem()) {
                this->setSmallestItem(item);
            }

            if (item > this->getLargestItem()) {
                this->setLargestItem(item);
            }
            result = true;
        }
        return result;
    }

    template <typename T>
    void OrderedCollection<T>::print(std::ostream& os) const {
        os.setf(std::ios::fixed);
        os.precision(2);
        os.unsetf(std::ios::fixed);
        Collection<T, 72>::print(os);
    }
}

#endif // SENECA_ORDEREDCOLLECTION_H