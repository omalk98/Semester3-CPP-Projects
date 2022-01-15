//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       3 
// Date:		   Sept 28, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <iostream>
#include "Set.h"

namespace sdds {
	template <const unsigned int N, typename T>
	class SetSummable : public Set<N, T> {
	public:
		T accumulate(const std::string filter)const {
			T set(filter);
			for (size_t i = 0; i < this->size(); ++i)
				if (set.isCompatibleWith(this->get(i))) set += this->get(i);
			return set;
		}
	};
}
#endif //!SDDS_SETSUMMABLE_H