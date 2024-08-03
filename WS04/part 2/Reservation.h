/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              7 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_RESERVATION_H
#define SENECA_RESERVATION_H

#include <string>
#include <iostream>

namespace seneca {
	class Reservation {
		std::string resID;
		std::string resName;
		std::string resEmail;
		int numOfPeople;
		int partyDay;
		int partyHour;

		std::string trim(const std::string& str);

	public:
		Reservation();
		void update(int day, int time);
		Reservation(const std::string& res);
		friend std::ostream& operator<<(std::ostream& ostr, const Reservation& src);
	};
}
#endif //!SENECA_RESERVATION_H
