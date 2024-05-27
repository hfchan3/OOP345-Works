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
#define CUST_NAME_LEN 10
#define FOOD_DESC_LEN 25
#include <iostream>

extern double g_dailydiscount;
extern double g_taxrate;

namespace seneca
{
    class FoodOrder
    {
        char name[CUST_NAME_LEN + 1];
        char foodDesc[FOOD_DESC_LEN + 1];
        double price{};
        bool isDailySpecial;

    public:
        void read(std::istream& istr);
        void display() const;
    };
}

#endif // !SENECA_FOODORDER_H
