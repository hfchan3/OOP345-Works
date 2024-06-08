/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				31 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Reservation.h"

namespace seneca {
	std::string Reservation::trim(const std::string& str) {
		size_t first = str.find_first_not_of(' ');
		if (first == std::string::npos) return ""; // No non-space characters
		size_t last = str.find_last_not_of(' ');
		return str.substr(first, last - first + 1);
	}

	Reservation::Reservation() : resID{ "" }, resName(""), resEmail(""), numOfPeople(0), partyDay(0), partyHour(0) {}
	
	Reservation::Reservation(const std::string& res) {
		size_t start = 0;
		size_t end = res.find(':');
		resID = trim(res.substr(start, end - start));


		start = end + 1;
		end = res.find(',', start);
		resName = res.substr(start, end - start);
		resName = trim(resName);

		start = end + 1;
		end = res.find(',', start);
		resEmail = res.substr(start, end - start);
		resEmail = trim(resEmail);

		start = end + 1;
		end = res.find(',', start);
		numOfPeople = std::stoi(res.substr(start, end - start));

		start = end + 1;
		end = res.find(',', start);
		partyDay = std::stoi(res.substr(start, end - start));

		start = end + 1;
	    partyHour = std::stoi(res.substr(start));
	}

	void Reservation::update(int day, int time) {
		this->partyDay = day;
		this->partyHour = time;
	}

	std::ostream& operator<<(std::ostream& ostr, const Reservation& src) {
		std::string meal;
		if (src.partyHour >= 6 && src.partyHour <= 9) {
			meal = "Breakfast";
		}
		else if (src.partyHour >= 11 && src.partyHour <= 15) {
			meal = "Lunch";
		}
		else if (src.partyHour >= 17 && src.partyHour <= 21) {
			meal = "Dinner";
		}
		else {
			meal = "Drinks";
		}

		ostr << "Reservation "
			<< std::right << std::setw(10) << src.resID << ": "
			<< std::right << std::setw(20) << src.resName << "  "
			<< std::left << std::setw(20) << ("<" + src.resEmail + ">") << "    "
			<< meal << " on day " << src.partyDay << " @ " << src.partyHour << ":00 for "
			<< src.numOfPeople << " " << (src.numOfPeople == 1 ? "person." : "people.") << std::endl;
		
		return ostr;
	}
}
