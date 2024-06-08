/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				7 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_RESTAURANT_H
#define SENECA_RESTAURANT_H

#include <iostream>
#include <string>
#include "Reservation.h"

namespace seneca {
	class Restaurant {
		Reservation** reservations;
		size_t numRes;
	public:
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& R);
		Restaurant& operator=(const Restaurant& R);
		Restaurant(Restaurant&& R) noexcept;
		Restaurant& operator=(Restaurant&& R) noexcept;
		~Restaurant();

		size_t size() const;

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif //!SENECA_RESTAURANT_H