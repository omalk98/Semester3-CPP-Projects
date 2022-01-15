//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       2 
// Date:		   Sept 20, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H
#include <string>

namespace sdds {
	class StringSet
	{
		size_t m_noOfStrings;
		std::string* m_strings;
		void reset();
	public:
		StringSet();
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet(StringSet&&);
		~StringSet();
		StringSet& operator=(const StringSet&);
		StringSet& operator=(StringSet&&);
		size_t size()const;
		std::string operator[](size_t)const;
	};
}
#endif //!SDDS_STRINGSET_H