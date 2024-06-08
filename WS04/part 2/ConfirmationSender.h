/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				7 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_CONFIRMATIONSENDER_H
#define SENECA_CONFIRMATIONSENDER_H

#include <iostream>
#include "Reservation.h"

namespace seneca {
	class ConfirmationSender {
		const Reservation** reservations;
		size_t numRes;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& C);
		ConfirmationSender& operator=(const ConfirmationSender& C);
		ConfirmationSender(ConfirmationSender&& C) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& C) noexcept;
		~ConfirmationSender();

		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender);
	};
}
#endif // !SENECA_CONFIRMATIONSENDER_H