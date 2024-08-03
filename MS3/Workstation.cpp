//////////////////////////////////////////////////////////////////////////////////////
// Name:               Hiu Fung Chan
// Seneca Student ID:  106184237 
// Seneca email:       hfchan3@myseneca.ca
// Date of completion: 17 July 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//////////////////////////////////////////////////////////////////////////////////////
#include "Workstation.h"

namespace seneca
{
    std::deque<CustomerOrder> g_pending{};
    std::deque<CustomerOrder> g_completed{};
    std::deque<CustomerOrder> g_incomplete{};

    Workstation::Workstation(const std::string& record) : Station{ record } {};

    void Workstation::fill(std::ostream& os) {
        if (!m_orders.empty()) {
            m_orders.front().fillItem(*this, os);
        }
    };

    bool Workstation::attemptToMoveOrder() {
        bool isMoved = false;
        if (!m_orders.empty()) {
            if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
                if (m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                }
                else {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                m_orders.pop_front();
                isMoved = true;
            }
        }
        return isMoved;
    };

    void Workstation::setNextStation(Workstation* station) { 
        m_pNextStation = station; 
    };

    Workstation* Workstation::getNextStation() const { 
        return m_pNextStation; 
    };

    void Workstation::display(std::ostream& os) const {
        os << getItemName() << " --> ";
        if (m_pNextStation) {
            os << m_pNextStation->getItemName();
        }
        else {
            os << "End of Line";
        }
        os << std::endl;
    };

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    };
}