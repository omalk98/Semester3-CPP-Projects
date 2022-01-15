//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       3 
// Date:		   Sept 28, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds {
	template <typename V, typename K>
	class Pair
	{
		V m_value;
		K m_key;
	protected:
		void operator+=(const Pair& rhs) { m_value += rhs.m_value; }
		void operator+=(const std::string& rhs) { m_value += rhs; }
	public:
		Pair() : m_value{  }, m_key{  } {}
		Pair(const K& key, const V& value) : Pair() { m_value = value; m_key = key; }
		const V& value()const { return m_value; }
		const K& key()const { return m_key; }
		virtual void display(std::ostream& os)const { os << m_key << " : " << m_value << std::endl; }
	};
	template <typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair) { pair.display(os); return os; }

}
#endif //!SDDS_PAIR_H