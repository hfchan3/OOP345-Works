 /*************************************************************************************************************************************
Name:              Hiu Fung CHAN
Seneca Email:      hfchan3@myseneca.ca
Seneca Student ID: 106184237
Date:              17 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
**************************************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "FoodOrder.h"

using namespace std;

double g_taxrate{};
double g_dailydiscount{};

namespace seneca
{
    // Default Constructor
    FoodOrder::FoodOrder() {
        m_custName[0] = '\0';
        m_foodDesc = nullptr;
        m_price = 0;
        m_isDailySpecial = false;
    }

    // Destructor
    FoodOrder::~FoodOrder() {
        delete[] m_foodDesc;
    }

    // Modifier to read data from an input stream into the FoodOrder object
    void FoodOrder::read(std::istream& in) {
        if (in) {
            char status{}; 
            in.getline(m_custName, NAME_LEN, ',');
            if (m_foodDesc) {
                delete[] m_foodDesc;
            }
           
            // Temporary string to hold the food description read from the input stream
            string temp;
            getline(in, temp, ',');
            m_foodDesc = new char[temp.length() + 1];
            strcpy(m_foodDesc, temp.c_str());
            in >> m_price;
            in.ignore(); 
            in >> status;
            if (status == 'Y') {
                m_isDailySpecial = true;
            }
            else if (status == 'N') {
                m_isDailySpecial = false;
            }
            in.ignore();
        }
    }

    // Query to display the details of a FoodOrder object in a formatted way
    void FoodOrder::display() const {
        static int index = 0;
        cout.setf(ios::left);
        cout.width(2);
        cout << ++index << ". ";
        double taxedPrice = m_price + (m_price * g_taxrate);
        if (m_custName[0] != '\0') {
            cout.width(10);
            cout << m_custName << "|";
            cout.width(25);
            cout << m_foodDesc << "|";
            cout.width(12);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << taxedPrice << "|";
            cout.unsetf(ios::left);

            if (m_isDailySpecial) {
                cout.width(13);
                cout << taxedPrice - g_dailydiscount << endl;
            }
            else {
                cout << endl;
            }
            cout.unsetf(ios::fixed);
        }
        else {
            cout << "No Order" << endl;
        }
    }


    // Copy Constructor of food order
    FoodOrder::FoodOrder(const FoodOrder& src) {
        // Shallow copy of non-dynamic data members
        strcpy(m_custName, src.m_custName);
        m_price = src.m_price;
        m_isDailySpecial = src.m_isDailySpecial;

        // Deep copy of dynamic data member
        m_foodDesc = new char[strlen(src.m_foodDesc) + 1];
        strcpy(m_foodDesc, src.m_foodDesc);
    }

    // Copy assignment operator of food order
    FoodOrder& FoodOrder::operator=(const FoodOrder& src) {
        // Check for self-assignment
        if (this != &src) {
            // Shallow copy of non-dynamic data members
            strcpy(m_custName, src.m_custName);
            m_price = src.m_price;
            m_isDailySpecial = src.m_isDailySpecial;

            // Deleting any previous allocation on m_foodDesc
            delete[] m_foodDesc;

            // Deep copy of dynamic data member
            if (src.m_foodDesc != nullptr) {
                m_foodDesc = new char[strlen(src.m_foodDesc) + 1];
                strcpy(m_foodDesc, src.m_foodDesc);
            }
        }
        return *this;
    }
}
