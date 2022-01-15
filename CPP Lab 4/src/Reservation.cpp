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
#include <iomanip>
#include <string>
#include "Reservation.h"

using namespace std;

namespace sdds {
	void Reservation::trim_s(std::string& data)
	{
		for (size_t i = 0; i < data.size(); ++i)
			if (data[i] == ' ') data.erase(i--, 1);
			else break;
		for (size_t j = data.size() - 1; j > 0; --j)
			if (data[j] == ' ') data.erase(j, 1);
			else break;
	}
	Reservation::Reservation()
	{
		m_res_id = {};
		m_name = {};
		m_email = {};
		m_no_guests = 0;
		m_day = 0;
		m_hour = 0;
	}
	Reservation::Reservation(const string& res) : Reservation()
	{
		size_t cnt = 0, idx = 0;
		m_res_id = res.substr(idx, cnt = res.find(':'));
		idx += ++cnt;
		trim_s(m_res_id);
		m_name = res.substr(idx, cnt = res.find(',', idx) - idx);
		idx += ++cnt;
		trim_s(m_name);
		m_email = res.substr(idx, cnt = res.find(',', idx) - idx);
		idx += ++cnt;
		trim_s(m_email);
		m_no_guests = stoi(res.substr(idx, cnt = res.find(',', idx) - idx));
		idx += ++cnt;
		m_day = stoi(res.substr(idx, cnt = res.find(',', idx) - idx));
		idx += ++cnt;
		m_hour = stoi(res.substr(idx, res.size() - idx));
	}
	void Reservation::update(int day, int time) { m_day = day; m_hour = time; }

	ostream& operator<<(ostream& os, const Reservation& res)
	{
		os << "Reservation " << setw(10) << res.m_res_id << ": " << setw(20) << res.m_name << "  " << setw(20) << left << "<" + res.m_email + ">" << right << setw(4) << " ";
		if (res.m_hour >= 6 && res.m_hour <= 9)
			os << "Breakfast on day ";
		else if (res.m_hour >= 11 && res.m_hour <= 15)
			os << "Lunch on day ";
		else if (res.m_hour >= 17 && res.m_hour <= 21)
			os << "Dinner on day ";
		else
			os << "Drinks on day ";
		os << res.m_day << " @ " << res.m_hour << ":00 for " << res.m_no_guests;
		(res.m_no_guests == 1) ? os << " person." : os << " people.";
		return os << endl;
	}
}