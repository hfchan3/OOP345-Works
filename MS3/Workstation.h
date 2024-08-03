//////////////////////////////////////////////////////////////////////////////////////
// Name:               Hiu Fung Chan
// Seneca Student ID:  106184237 
// Seneca email:       hfchan3@myseneca.ca
// Date of completion: 17 July 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//////////////////////////////////////////////////////////////////////////////////////

#ifndef SENECA_WORKSTATION_H
#define SENECA_WORKSTATION_H
#include <iostream>
#include <deque>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"

namespace seneca
{
    extern std::deque<CustomerOrder> g_pending;
    extern std::deque<CustomerOrder> g_completed;
    extern std::deque<CustomerOrder> g_incomplete;

    class Workstation : public Station
    {
        std::deque<CustomerOrder> m_orders{};
        Workstation* m_pNextStation{};

    public:
        Workstation() = default;
        Workstation(const std::string& record);
        void fill(std::ostream& ostr);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station = nullptr);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder);
    };

}
#endif
