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
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <string>
namespace sdds {
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
		void trim_s(std::string&);
	public:
		Movie();
		Movie(const std::string&);
		const std::string title()const;
		friend std::ostream& operator<<(std::ostream&, const Movie&);

		template <typename T>
		void fixSpelling(T& spellChecker) { spellChecker(m_description); spellChecker(m_title); }
	};
}
#endif //!SDDS_MOVIE_H