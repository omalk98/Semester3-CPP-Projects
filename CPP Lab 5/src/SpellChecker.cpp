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
#include <fstream>
#include <string>
#include <limits>
#include "SpellChecker.h"

using namespace std;
namespace sdds {
	unsigned int SpellChecker::bad_cnt[MAX_WORDS]{ 0 };
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream fptr{ filename };
		if (fptr) {
			for (auto i = 0; i < MAX_WORDS; ++i)
				fptr >> m_badWords[i] >> m_goodWords[i];
			fptr.close();
		}
		else throw "Bad file name!";
	}
	void SpellChecker::operator()(std::string& text)
	{
		unsigned int idx = 0;
		for (auto i = 0; i < MAX_WORDS; ++i)
		{
			idx = 0;
			for (; idx < text.size();) {
				idx = text.find(m_badWords[i], idx);
				if (idx != numeric_limits<unsigned int>::max()) {
					text.replace(idx, m_badWords[i].size(), m_goodWords[i]);
					++bad_cnt[i];
					idx += m_badWords[i].size();
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& os) const
	{
		os << "Spellchecker Statistics\n";
		for (auto i = 0; i < MAX_WORDS; ++i)
			os << setw(15) << m_badWords[i] << ": " << bad_cnt[i] << " replacements\n";
	}
}