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
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <string>
namespace sdds {
	const int MAX_WORDS = 6;
	class SpellChecker
	{
		std::string m_badWords[MAX_WORDS]{};
		std::string m_goodWords[MAX_WORDS]{};
		static unsigned int bad_cnt[MAX_WORDS];
	public:
		SpellChecker(const char*);
		void operator()(std::string&);
		void showStatistics(std::ostream&)const;

	};
}
#endif //!SDDS_SPELLCHECKER_H