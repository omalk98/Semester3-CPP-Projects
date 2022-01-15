//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       5 
// Date:		   Oct 11, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

using namespace std;
namespace sdds {
	void Movie::trim_s(string& data)
	{
		for (size_t i = 0; i < data.size(); ++i)
			if (data[i] == ' ') data.erase(i--, 1);
			else break;
		for (size_t j = data.size() - 1; j > 0; --j)
			if (data[j] == ' ') data.erase(j, 1);
			else break;
	}
	Movie::Movie()
	{
		m_title = {};
		m_year = 0;
		m_description = {};
	}
	Movie::Movie(const string& movieStr) : Movie()
	{
		size_t cnt = 0, idx = 0;
		m_title = movieStr.substr(idx, cnt = movieStr.find(','));
		idx += ++cnt;
		trim_s(m_title);
		m_year = stoi(movieStr.substr(idx, cnt = movieStr.find(',', idx) - idx));
		idx += ++cnt;
		m_description = movieStr.substr(idx, movieStr.size() - idx);
		trim_s(m_description);
	}
	const string Movie::title() const { return m_title; }
	ostream& operator<<(ostream& os, const Movie& movie) { return os << setw(40) << movie.m_title << " | " << setw(4) << movie.m_year << " | " << movie.m_description << endl; }
}