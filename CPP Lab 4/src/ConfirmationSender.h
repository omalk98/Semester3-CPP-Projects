//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       4 
// Date:		   Oct 6, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include <iostream>
#include "Reservation.h"
namespace sdds {
	class ConfirmationSender
	{
		const Reservation** m_res_conf;
		size_t m_no_res;
		void reset();
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&) noexcept;
		ConfirmationSender& operator=(const ConfirmationSender&) noexcept;
		ConfirmationSender(ConfirmationSender&&) noexcept;
		~ConfirmationSender();
		ConfirmationSender& operator=(ConfirmationSender&&) noexcept;
		ConfirmationSender& operator+=(const Reservation&);
		ConfirmationSender& operator-=(const Reservation&);
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
	};
}
#endif //!SDDS_CONFIRMATIONSENDER_H