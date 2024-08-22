/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              6 July 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "Bakery.h"

namespace seneca {
    Bakery::Bakery(const std::string& filename) {
        auto parseBakedType = [](const std::string& str) -> BakedType {
            std::string type = str;
            std::transform(type.begin(), type.end(), type.begin(), ::toupper); 
            if (type == "BREAD") return BakedType::Bread;
            if (type == "PASTRY") return BakedType::Pastry;
            throw std::invalid_argument("Invalid BakedType: " + str);
            };

        auto trim = [](const std::string& str) -> std::string {
            size_t first = str.find_first_not_of(' ');
            size_t last = str.find_last_not_of(' ');
            return str.substr(first, (last - first + 1));
            };

        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        std::string fileContent((std::istreambuf_iterator<char>(file)),
            std::istreambuf_iterator<char>());

        std::istringstream iss(fileContent);
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(iss, line)) {
            lines.push_back(line);
        }

        std::transform(lines.begin(), lines.end(), std::back_inserter(goods), [&](const std::string& line) {
            BakedGood good;
            std::string typeStr = trim(line.substr(0, 8));
            std::string description = trim(line.substr(8, 20));
            std::string shelfLifeStr = trim(line.substr(28, 14));
            std::string stockStr = trim(line.substr(42, 8));
            std::string priceStr = trim(line.substr(50, 6));

            good.m_type = parseBakedType(typeStr);
            good.m_description = description;
            good.m_shelfLife = std::stoi(shelfLifeStr);
            good.m_stock = std::stoi(stockStr);
            good.m_price = std::stod(priceStr);

            return good;
            });
    }

    void Bakery::showGoods(std::ostream& os) const {
        std::for_each(goods.begin(), goods.end(), [&os](const BakedGood& good) {
            os << good << std::endl;
            });
    }

    std::ostream& operator<<(std::ostream& out, const BakedGood& b) {
        std::string typeStr = (b.m_type == BakedType::Bread) ? "Bread" : "Pastry";
        out << std::left << "* " << std::setw(10) << typeStr << " * "
            << std::left << std::setw(20) << b.m_description << " * "
            << std::left << std::setw(5) << b.m_shelfLife << " * "
            << std::left << std::setw(5) << b.m_stock << " * "
            << std::right << std::fixed << std::setprecision(2) << std::setw(8) << b.m_price << " *";
        return out;
    }
}
