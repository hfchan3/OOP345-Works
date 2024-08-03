#include <iostream>
#include <iomanip>
#include "FoodOrder.h"
#include <cstring>
#include <string>

using namespace std;
double g_dailydiscount{};
double g_taxrate{};
namespace seneca
{

    // `read()`: a modifier that receives an `istream` reference.
    void FoodOrder::read(std::istream& istr) {
        char y_n{};
        if (!istr.fail()) {
            istr.getline(this->cstr, CSTR_MAX, ',');
            istr.getline(this->cstr_desc, CSTR_STRING, ',');
            istr >> price_value;
            istr.ignore(100, ',');
            istr >> y_n;
            istr.ignore(100, '\n');

            y_n == 'N' ? dailySpecial = false : dailySpecial = true;
        }
    }

    // `display()`: a query that displays to the screen the content of an `Food Order`

    void FoodOrder::display() const {
        static int counter = 0;
        cout << left << setw(2) << ++counter << ". ";
        double priceTaxed = price_value + (price_value * g_taxrate);
        if (cstr[0] != '\0') {
            cout << left << setw(10) << cstr << "|"
                << left << setw(25) << cstr_desc << "|" << left << setw(12) << fixed << setprecision(2) << priceTaxed << "|";

            if (dailySpecial) {
                cout << right << setw(13) << fixed << priceTaxed - g_dailydiscount << std::endl;
            }
            else {
                cout << endl;
            }
        }
        else {
            cout << "No Order" << endl;
        }
    }

}
