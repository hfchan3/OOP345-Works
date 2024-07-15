/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				6 July 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_BAKERY_H
#define SENECA_BAKERY_H
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <string>
#include <sstream>
#include <stdexcept>

namespace seneca {
	enum class BakedType {
		Bread,
		Pastry
	};

	struct BakedGood {
		BakedType m_type;
		std::string m_description{};
		int m_shelfLife{};
		int m_stock{};
		double m_price{};
	};

	class Bakery {
		std::vector<BakedGood> goods;
	public:
		Bakery(const std::string& filename);
		void showGoods(std::ostream& os) const;
	};
 
	std::ostream& operator<<(std::ostream& out, const BakedGood& b);
}
#endif // !SENECA_BAKERY_H
