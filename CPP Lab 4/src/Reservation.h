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
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>
#include <string>

namespace sdds {
	class Reservation
	{
		std::string m_res_id;
		std::string m_name;
		std::string m_email;
		size_t m_no_guests;
		size_t m_day;
		size_t m_hour;
		void trim_s(std::string&);
	public:
		Reservation();
		Reservation(const std::string&);
		void update(int, int);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
}
#endif //!SDDS_RESERVATION_H