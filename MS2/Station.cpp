//////////////////////////////////////////////////////////////////////////////////////
// Name:               Hiu Fung Chan
// Seneca Student ID:  106184237 
// Seneca email:       hfchan3@myseneca.ca
// Date of completion: 10 July 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//////////////////////////////////////////////////////////////////////////////////////

#include "Station.h"

namespace seneca {
	size_t Station::m_widthField = 0;
	int Station::id_generator = 0;

	Station::Station(const std::string& record) {
		Utilities utils;
		size_t next_pos = 0;
		bool more = true;

        id_generator++;
        m_id = id_generator;
		m_itemName = utils.extractToken(record, next_pos, more);
		m_serialNumber = std::stoul(utils.extractToken(record, next_pos, more));
        m_quantity = std::stoul(utils.extractToken(record, next_pos, more));
       
        if (utils.getFieldWidth() > m_widthField) {
            m_widthField = utils.getFieldWidth();
        }
        m_description = utils.extractToken(record, next_pos, more);
    }

    const std::string& Station::getItemName() const {
        return m_itemName;
    }

    size_t Station::getNextSerialNumber() {
        return m_serialNumber++;
    }

    size_t Station::getQuantity() const {
        return m_quantity;
    }

    void Station::updateQuantity() {
        if (m_quantity > 0) {
            m_quantity--;
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        os.setf(std::ios::right);
        os.width(3);
        os.fill('0');
        os << m_id << " | ";
        os.unsetf(std::ios::right);

        os.setf(std::ios::left);
        os.width(m_widthField);
        os.fill(' ');
        os << m_itemName << " | ";
        os.unsetf(std::ios::left);

        os.setf(std::ios::right);
        os.width(6);
        os.fill('0');
        os << m_serialNumber << " | ";

        if (full) {
            os.width(4);
            os.fill(' ');
            os << m_quantity << " | " << m_description;
        }

        os << std::endl;
	}
}