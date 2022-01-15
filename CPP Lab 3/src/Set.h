//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       3 
// Date:		   Sept 28, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H
#define SDDS_SET_H

namespace sdds {
	template <const unsigned int N, typename T>
	class Set
	{
		size_t m_size = 0;
		T m_arr[N];
	public:
		size_t size()const { return m_size; }
		const T& get(size_t idx)const { return m_arr[idx]; }
		void operator+=(const T& item) { if (m_size < N) m_arr[m_size++] = item; }
	};
}
#endif //!SDDS_SET_H