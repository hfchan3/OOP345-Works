/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				7 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <string>
#include "Restaurant.h"

namespace seneca {
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : numRes(cnt) {
		this->reservations = new Reservation*[cnt];
		for (size_t i = 0; i < cnt; i++) {
			this->reservations[i] = new Reservation(*reservations[i]);
		}
	}

	Restaurant::Restaurant(const Restaurant& R) : numRes(R.numRes) {
		reservations = new Reservation*[numRes];
		for (size_t i = 0; i < numRes; i++) {
			reservations[i] = new Reservation(*R.reservations[i]);
		}
	}

	Restaurant& Restaurant::operator=(const Restaurant& R) {
		if (this != &R) {
			for (size_t i = 0; i < numRes; i++) {
				delete reservations[i];
			}
			delete[] reservations;
			
			numRes = R.numRes;
			reservations = new Reservation*[numRes];
			for (size_t i = 0; i < numRes; i++) {
				reservations[i] = new Reservation(*R.reservations[i]);
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& R) noexcept : reservations(R.reservations), numRes(R.numRes) {
		R.reservations = nullptr;
		R.numRes = 0;
	}

	Restaurant& Restaurant::operator=(Restaurant&& R) noexcept {
		if (this != &R) {
			for (size_t i = 0; i < numRes; i++) {
				delete reservations[i];
			}
			delete[] reservations;

			reservations = R.reservations;
			numRes = R.numRes;

			R.reservations = nullptr;
			R.numRes = 0;
		}
		return *this;
	}

	Restaurant::~Restaurant() {
		for (size_t i = 0; i < numRes; i++) {
			delete reservations[i];
		}
		delete[] reservations;
	}

	size_t Restaurant::size() const {
		return numRes;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
		static int CALL_CNT = 0;
		CALL_CNT++;

		os << "--------------------------\n";
		os << "Fancy Restaurant (" << CALL_CNT << ")\n";
		os << "--------------------------\n";
		if (res.numRes == 0) {
			os << "This restaurant is empty!\n";
		}
		else {
			for (size_t i = 0; i < res.numRes; i++) {
				os << *res.reservations[i];
			}
		}
		os << "--------------------------\n";
		return os;
	}
};