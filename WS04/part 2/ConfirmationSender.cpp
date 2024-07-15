 /*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				7 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include <iostream>
#include "ConfirmationSender.h"

namespace seneca {
    ConfirmationSender::ConfirmationSender() : reservations(nullptr), numRes(0) {}

    ConfirmationSender::ConfirmationSender(const ConfirmationSender& C) : numRes(C.numRes) {
        reservations = new const Reservation*[numRes];
        for (size_t i = 0; i < numRes; i++) {
            reservations[i] = C.reservations[i];
        }
    }

    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& C) {
        if (this != &C) {
            delete[] reservations;

            numRes = C.numRes;
            reservations = new const Reservation*[numRes];
            for (size_t i = 0; i < numRes; i++) {
                reservations[i] = C.reservations[i];
            }
        }
        return *this;
    }

    ConfirmationSender::ConfirmationSender(ConfirmationSender&& C) noexcept : reservations(C.reservations), numRes(C.numRes) {
        C.reservations = nullptr;
        C.numRes = 0;
    }

    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& C) noexcept {
        if (this != &C) {
            delete[] reservations;

            reservations = C.reservations;
            numRes = C.numRes;

            C.reservations = nullptr;
            C.numRes = 0;
        }
        return *this;
    }

    ConfirmationSender::~ConfirmationSender() {
        delete[] reservations;
    }

    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
        for (size_t i = 0; i < numRes; ++i) {
            if (reservations[i] == &res) {
                return *this;
            }
        }
        const Reservation** temp = new const Reservation * [numRes + 1];
        for (size_t i = 0; i < numRes; ++i) {
            temp[i] = reservations[i];
        }
        temp[numRes] = &res;
        delete[] reservations;
        reservations = temp;
        numRes++;
        return *this;
    }

    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
        bool found = false;
        // Searches the array for the address of res, sets the pointer in the array to nullptr if res is found
        for (size_t i = 0; i < numRes; i++) {
            if (reservations[i] == &res) {
                reservations[i] = nullptr;
                found = true;
            }
        }
        if (found) {
            size_t newSize = 0;
            for (size_t i = 0; i < numRes; i++) {
                if (reservations[i] != nullptr) {
                    newSize++;
                }
            }
            const Reservation** temp = new const Reservation* [newSize];
            size_t index = 0;

            for (size_t i = 0; i < numRes; i++) {
                if (reservations[i] != nullptr) {
                    temp[index++] = reservations[i];
                }
            }
            delete[] reservations;
            reservations = temp;
            numRes = newSize;
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender) {
        os << "--------------------------\n";
        os << "Confirmations to Send\n";
        os << "--------------------------\n";
        if (sender.numRes == 0) {
            os << "There are no confirmations to send!\n";
        }
        else {
            for (size_t i = 0; i < sender.numRes; ++i) {
                os << *sender.reservations[i];
            }
        }
        os << "--------------------------\n";
        return os;
    }
}