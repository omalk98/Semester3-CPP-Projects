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
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <ostream>
#include "Reservation.h"
namespace sdds {
	class Restaurant
	{
		Reservation* m_cur_res;
		size_t m_no_res;
		void reset();
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		~Restaurant();
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		size_t size()const;
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};
}
#endif //!SDDS_RESTAURANT_H