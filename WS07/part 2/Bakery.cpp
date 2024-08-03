/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				6 July 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "Bakery.h"

namespace seneca {
    Bakery::Bakery(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        std::string line;
        while (std::getline(file, line)) {
            BakedGood good;

            std::string typeStr = line.substr(0, 8);
            size_t spacePos = typeStr.find_last_not_of(' ');
            typeStr = typeStr.substr(0, spacePos + 1);
            std::transform(typeStr.begin(), typeStr.end(), typeStr.begin(), ::toupper);
            if (typeStr == "BREAD") {
                good.m_type = BakedType::BREAD;
            }
            else if (typeStr == "PASTRY") {
                good.m_type = BakedType::PASTERY;
            }
            else {
                throw std::invalid_argument("Invalid BakedType: " + typeStr);
            }
            line.erase(0, 8);

            std::string description = line.substr(0, 20);
            spacePos = description.find_last_not_of(' ');
            good.m_description = description.substr(0, spacePos + 1);
            line.erase(0, 20);

            std::string shelfLifeStr = line.substr(0, 14);
            spacePos = shelfLifeStr.find_last_not_of(' ');
            good.m_shelfLife = std::stoi(shelfLifeStr.substr(0, spacePos + 1));
            line.erase(0, 14);

            std::string stockStr = line.substr(0, 8);
            spacePos = stockStr.find_last_not_of(' ');
            good.m_stock = std::stoi(stockStr.substr(0, spacePos + 1));
            line.erase(0, 8);

            std::string priceStr = line.substr(0, 6);
            spacePos = priceStr.find_last_not_of(' ');
            good.m_price = std::stod(priceStr.substr(0, spacePos + 1));

            goodsCollection.push_back(good);
        }
    }

    void Bakery::showGoods(std::ostream& os) const {
        double totalPrice = 0.0;
        int totalStock = 0;

        std::for_each(goodsCollection.begin(), goodsCollection.end(), [&](const BakedGood& good) {
            totalPrice += good.m_price;
            totalStock += good.m_stock;
            os << good << std::endl;
        });

        os << "Total Stock: " << totalStock << std::endl;
        os << "Total Price: " << std::fixed << std::setprecision(2) << totalPrice << std::endl;
    }

    void Bakery::sortBakery(const std::string& field) {
        if (field == "Description") {
            std::sort(goodsCollection.begin(), goodsCollection.end(), [](const BakedGood& bg1, const BakedGood& bg2) {
                return bg1.m_description < bg2.m_description;
            });
        }
        else if (field == "Shelf") {
            std::sort(goodsCollection.begin(), goodsCollection.end(), [](const BakedGood& bg1, const BakedGood& bg2) {
                return bg1.m_shelfLife < bg2.m_shelfLife;
            });
        }
        else if (field == "Stock") {
            std::sort(goodsCollection.begin(), goodsCollection.end(), [](const BakedGood& bg1, const BakedGood& bg2) {
                return bg1.m_stock < bg2.m_stock;
            });
        }
        else if (field == "Price") {
            std::sort(goodsCollection.begin(), goodsCollection.end(), [](const BakedGood& bg1, const BakedGood& bg2) {
                return bg1.m_price < bg2.m_price;
            });
        }
        else {
            throw std::invalid_argument("Invalid sort field: " + field);
        }
    }

    std::vector<BakedGood> Bakery::combine(Bakery& src) {
        // Sort both bakeries by price before merging
        sortBakery("Price");
        src.sortBakery("Price");

        // Reserve enough space to avoid reallocations
        std::vector<BakedGood> combined;
        combined.reserve(goodsCollection.size() + src.goodsCollection.size());

        // Merge sorted ranges
        std::merge(goodsCollection.begin(), goodsCollection.end(), src.goodsCollection.begin(), src.goodsCollection.end(), std::back_inserter(combined),
            [](const BakedGood& bg1, const BakedGood& bg2) {
                return bg1.m_price < bg2.m_price;
            });

        return combined;
    }

    bool Bakery::inStock(const std::string& description, BakedType type) const {
        auto it = std::find_if(goodsCollection.begin(), goodsCollection.end(), [&](const BakedGood& good) {
            return good.m_description == description && good.m_type == type && good.m_stock > 0;
        });
        return it != goodsCollection.end();
    }

    std::list<BakedGood> Bakery::outOfStock(BakedType type) const {
        // Create a vector to hold the collection of out of stock goods
        std::vector<BakedGood> outOfStockGoods;

        // Copy out of stock goods to the vector
        std::copy_if(goodsCollection.begin(), goodsCollection.end(), std::back_inserter(outOfStockGoods),
            [&](const BakedGood& good) {
                return good.m_type == type && good.m_stock == 0;
            });

        // Partially sort the vector by price
        std::partial_sort_copy(outOfStockGoods.begin(), outOfStockGoods.end(),
            outOfStockGoods.begin(), outOfStockGoods.end(), [](const BakedGood& bg1, const BakedGood& bg2) {
                return bg1.m_price < bg2.m_price;
            });

        // Create a list and copy sorted goods into it
        std::list<BakedGood> sortedOutOfStock(outOfStockGoods.begin(), outOfStockGoods.end());

        return sortedOutOfStock;
    }


    std::ostream& operator<<(std::ostream& out, const BakedGood& bg) {
        std::string typeStr = (bg.m_type == BakedType::BREAD) ? "Bread" : "Pastry";   
        out << std::left << "* " << std::setw(10) << typeStr << " * "
            << std::left << std::setw(20) << bg.m_description << " * "
            << std::left << std::setw(5) << bg.m_shelfLife << " * "
            << std::left << std::setw(5) << bg.m_stock << " * "
            << std::right << std::fixed << std::setprecision(2) << std::setw(8) << bg.m_price << " * ";

        return out;
    }
}