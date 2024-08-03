#include "Station.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;
    // This constructor extracts name, starting serial number, and quantity from the string
    Station::Station(const std::string str) {
        Utilities utilities{};
        size_t next_pos{ 0 };
        bool more{ true };

        // Extracting the name
        m_item = utilities.extractToken(str, next_pos, more);

        // Extracting the Serial Number
        m_serial = std::stoi(utilities.extractToken(str, next_pos, more));
        // Extracting the quantity in stock
        m_quantity = std::stoi(utilities.extractToken(str, next_pos, more));

        // Updating (Station::m_widthField to the maximum value of Station::m_widthField and utilities::m_widthField)
        m_widthField = std::max(m_widthField, utilities.getFieldWidth());
        // Extracting the description
        m_description = utilities.extractToken(str, next_pos, more);

        // the id being incremented
        m_id = ++id_generator;
    }

    // Returns the name of the current Station object
    const std::string& Station::getItemName() const { return m_item; }

    // Returns the next serial number to be used on the assembly line and increments m_serialNumber
    size_t Station::getNextSerialNumber() { return m_serial++; }

    // Returns the remaining quantity of items in the Station object
    size_t Station::getQuantity() const { return m_quantity; }

    // subtracts 1 from the available quantity; should not drop below 0.
    void Station::updateQuantity() { (m_quantity > 0) ? m_quantity -= 1 : m_quantity; }

    // Inserts information about the current object into stream os
    void Station::display(std::ostream& os, bool full) const {
        char emptySpace = ' ';
        os << std::setfill('0') << std::right << std::setw(3) << m_id << " | ";
        os << std::setw(m_widthField + 1) << std::left << std::setfill(emptySpace) << m_item << " | ";
        os << std::setw(6) << std::right << std::setfill('0') << m_serial << " | ";
        if (full) {
            os << std::setfill(emptySpace) << std::setw(4) << std::right << m_quantity << " | ";
            os << std::left << m_description;
        }
        os << std::endl;
    }
}