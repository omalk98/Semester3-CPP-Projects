//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       3 
// Date:		   Sept 28, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds {
	template<typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V m_init_val;
		static size_t m_min_width;
	public:
		PairSummable() : Pair<V, K>() { }
		PairSummable(const K& key, const V& value = {  }) : Pair<V, K>(key, value) { if (m_min_width < key.size()) m_min_width = key.size(); }
		bool isCompatibleWith(const PairSummable& b)const { return this->key() == b.key(); }
		PairSummable& operator+=(const PairSummable& rhs) { Pair<V, K>::operator+=(rhs); return *this; }
		void display(std::ostream& os)const override { Pair<V, K>::display(os << std::left << std::setw(m_min_width)); os << std::right; }
	};
	template <typename V, typename K>
	V PairSummable<V, K>::m_init_val{ };
	template <typename V, typename K>
	size_t PairSummable<V, K>::m_min_width = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& rhs) 
	{ 
		m_init_val = this->value();
		Pair::operator+=((m_init_val.size() > 0) ? ", " + rhs.value() : rhs.value());
		return *this;
	}
}

#endif //!SDDS_PAIRSUMMABLE_H