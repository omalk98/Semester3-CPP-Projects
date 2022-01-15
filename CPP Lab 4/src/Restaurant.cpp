//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       4 
// Date:		   Oct 6, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <utility>
#include "Restaurant.h"
#include "Reservation.h"

using namespace std;

namespace sdds {
	void Restaurant::reset()
	{
		m_no_res = 0;
		delete[] m_cur_res;
		m_cur_res = nullptr;
	}
	Restaurant::Restaurant()
	{
		m_cur_res = nullptr;
		m_no_res = 0;
	}
	Restaurant::~Restaurant() { reset(); }
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) : Restaurant()
	{
		m_cur_res = new Reservation[m_no_res = cnt];
		for (size_t i = 0; i < cnt; ++i)
			m_cur_res[i] = *reservations[i];
	}
	Restaurant::Restaurant(const Restaurant& loc) : Restaurant() { *this = loc; }
	Restaurant& Restaurant::operator=(const Restaurant& loc)
	{
		if (this != &loc) {
			reset();
			m_cur_res = new Reservation[m_no_res = loc.m_no_res];
			for (size_t i = 0; i < loc.m_no_res; ++i)
				m_cur_res[i] = loc.m_cur_res[i];
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& loc) : Restaurant() { *this = move(loc); }
	Restaurant& Restaurant::operator=(Restaurant&& loc)
	{
		if (this != &loc) {
			reset();
			m_cur_res = loc.m_cur_res;
			m_no_res = loc.m_no_res;
			loc.m_cur_res = nullptr;
			loc.m_no_res = 0;
		}
		return *this;
	}
	size_t Restaurant::size() const { return m_no_res; }
	ostream& operator<<(ostream& os, const Restaurant& loc)
	{
		static size_t func_cnt = 0;
		os << "--------------------------\n" << "Fancy Restaurant (" << ++func_cnt  << ")\n" << "--------------------------\n";
		if (loc.m_no_res) for (size_t i = 0; i < loc.m_no_res; ++i) os << loc.m_cur_res[i];
		else os << "This restaurant is empty!\n";
		return os << "--------------------------" << endl;
	}
}
