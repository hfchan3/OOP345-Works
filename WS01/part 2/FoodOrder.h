/*************************************************************************************************************************************
Name:              Hiu Fung CHAN
Seneca Email:      hfchan3@myseneca.ca
Seneca Student ID: 106184237
Date:              17 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my 
workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
**************************************************************************************************************************************/
#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#define NAME_LEN 10

#include <iostream>
#include <fstream>
#include <string>

// Declaration of global varaiables
extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca
{
    class FoodOrder
    {
        char m_custName[NAME_LEN];
        char* m_foodDesc;
        double m_price;
        bool m_isDailySpecial;

    public:
        FoodOrder();
        ~FoodOrder();
        void read(std::istream& in);
        void display() const;
        FoodOrder(const FoodOrder& src);
        FoodOrder& operator=(const FoodOrder& src);
    };
}

#endif // !SENECA_FOODORDER_H