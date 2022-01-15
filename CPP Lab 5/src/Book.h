//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       5 
// Date:		   Oct 11, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <string>

namespace sdds {
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country_pub;
		size_t m_year_pub;
		double m_price;
		std::string m_description;
		void trim_s(std::string&);
	public:
		Book();
		Book(const std::string);
		const std::string title()const;
		const std::string country()const;
		const size_t& year()const;
		double& price();
		friend std::ostream& operator<<(std::ostream&, const Book&);

		template <typename T>
		void fixSpelling(T& spellChecker) { spellChecker(m_description); }
	};
}
#endif // !SDDS_BOOK_H
