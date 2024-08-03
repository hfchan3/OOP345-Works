/////////////////////////////////////////////////////////////
// Name:               Hiu Fung Chan
// Seneca Student ID:  106184237 
// Seneca email:       hfchan3@myseneca.ca
// Date of completion: 19 July 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
/////////////////////////////////////////////////////////////

#include <vector>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace seneca
{
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& record) {
        Utilities utils;
        size_t next_pos = 0;
        bool more = true;

        m_name = utils.extractToken(record, next_pos, more);
        m_product = utils.extractToken(record, next_pos, more);
        m_cntItem = 0;

        std::vector<Item*> items;
        while (more) {
            Item* item = new Item{ utils.extractToken(record, next_pos, more) };
            items.push_back(item);
        }

        m_cntItem = items.size();
        m_lstItem = new Item* [m_cntItem];
        for (size_t i = 0; i < m_cntItem; i++) {
            m_lstItem[i] = items[i];
        }

        if (utils.getFieldWidth() > m_widthField) {
            m_widthField = utils.getFieldWidth();
        }
    }

    CustomerOrder::CustomerOrder(const CustomerOrder&) {
        throw std::runtime_error("Copy constructor is not allowed to be called!");
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
        *this = std::move(src);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
        if (this != &src) {
            if (m_lstItem) {
                for (size_t i = 0; i < m_cntItem; i++) {
                    delete m_lstItem[i];
                }
                delete[] m_lstItem;
            }

            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;
            m_lstItem = src.m_lstItem;

            src.m_lstItem = nullptr;
            src.m_cntItem = 0;
        }
        return *this;
    }

    CustomerOrder::~CustomerOrder()
    {
        for (size_t i = 0; i < m_cntItem; i++)
        {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    };

    bool CustomerOrder::isOrderFilled() const {
        bool success = true;
        for (size_t i = 0; i < m_cntItem; i++) {
            if (!m_lstItem[i]->m_isFilled) {
                success = false;
            }
        }
        return success;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == itemName) {
                if (!m_lstItem[i]->m_isFilled) {
                    return false; // Return false if any matching item is not filled
                }
            }
        }
        return true; // Return true if all matching items are filled or if no matching items are found
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled) {
                if (station.getQuantity() > 0) {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                    return;
                }
                else {
                    os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    };

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0; i < m_cntItem; i++) {
            os << "[";
            os.width(6);
            os.fill('0');
            os << m_lstItem[i]->m_serialNumber << "] ";
            os.width(m_widthField);
            os.fill(' ');
            os.setf(std::ios::left, std::ios::adjustfield);
            os << m_lstItem[i]->m_itemName << " - ";
            os.unsetf(std::ios::left);
            if (m_lstItem[i]->m_isFilled) {
                os << "FILLED";
            }
            else {
                os << "TO BE FILLED";
            }
            os << std::endl;
        }
    };

}