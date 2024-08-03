/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              7 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include "Reservation.h"

namespace seneca {
	// Helper function to eliminate all leading and trailing spaces from the beginning and end of any token extracted from the string.
	std::string Reservation::trim(const std::string& res) {
		size_t start = 0;
		while (start < res.length() && std::isspace(res[start])) {
			start++;
		}
		if (start == res.length()) {
			return "";
		}

		size_t end = res.length() - 1;
		while (end > start && std::isspace(res[end])) {
			end--;
		}

		return res.substr(start, end - start + 1);
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

	std::ostream& operator<<(std::ostream& os, const Reservation& res) {
		std::string meal;
		if (res.partyHour >= 6 && res.partyHour <= 9) {
			meal = "Breakfast";
		}
		else if (res.partyHour >= 11 && res.partyHour <= 15) {
			meal = "Lunch";
		}
		else if (res.partyHour >= 17 && res.partyHour <= 21) {
			meal = "Dinner";
		}
		else {
			meal = "Drinks";
		}

		os << "Reservation ";
		os.setf(std::ios::right);
		os.width(10);
		os << res.resID << ": ";
		os.width(20);
		os << res.resName << "  ";
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os.width(20);
		os << ("<" + res.resEmail + ">") << "    " << meal << " on day " << res.partyDay << " @ " << res.partyHour << ":00 for "
		   << res.numOfPeople << " " << (res.numOfPeople == 1 ? "person." : "people.") << std::endl;
		os.unsetf(std::ios::left);
	
		return os;
	}
}
