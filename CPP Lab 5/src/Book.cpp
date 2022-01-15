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
#include "Book.h"

using namespace std;
namespace sdds {
	void Book::trim_s(std::string& data)
	{
		for (size_t i = 0; i < data.size(); ++i)
			if (data[i] == ' ') data.erase(i--, 1);
			else break;
		for (size_t j = data.size() - 1; j > 0; --j)
			if (data[j] == ' ') data.erase(j, 1);
			else break;
	}
	Book::Book()
	{
		m_author = {};
		m_title = {};
		m_country_pub = {};
		m_year_pub = 0;
		m_price = 0;
		m_description = {};
	}
	Book::Book(const string bookStr) : Book()
	{
			size_t cnt = 0, idx = 0;
			m_author = bookStr.substr(idx, cnt = bookStr.find(','));
			idx += ++cnt;
			trim_s(m_author);
			m_title = bookStr.substr(idx, cnt = bookStr.find(',', idx) - idx);
			idx += ++cnt;
			trim_s(m_title);
			m_country_pub = bookStr.substr(idx, cnt = bookStr.find(',', idx) - idx);
			idx += ++cnt;
			trim_s(m_country_pub);
			m_price = stod(bookStr.substr(idx, cnt = bookStr.find(',', idx) - idx));
			idx += ++cnt;
			m_year_pub = stoi(bookStr.substr(idx, cnt = bookStr.find(',', idx) - idx));
			idx += ++cnt;
			m_description = bookStr.substr(idx, bookStr.size() - idx);
			trim_s(m_description);
	}
	const string Book::title() const { return m_title; }
	const string Book::country() const { return m_country_pub; }
	const size_t& Book::year() const { return m_year_pub; }
	double& Book::price() { return m_price; }
	ostream& operator<<(ostream& os, const Book& book)
	{
		return os << setw(20) << book.m_author << " | " << setw(22) << book.m_title << " | " << setw(5) << book.m_country_pub << " | " << setw(4) << book.m_year_pub << " | " << setw(6) << fixed << setprecision(2) << book.m_price << " | " << book.m_description << endl;
	}
}