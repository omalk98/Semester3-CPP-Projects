//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       4 
// Date:		   Oct 6, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <utility>
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
	void ConfirmationSender::reset()
	{
		delete[] m_res_conf;
		m_res_conf = nullptr;
	}
	ConfirmationSender::ConfirmationSender()
	{
		m_res_conf = nullptr;
		m_no_res = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& conf) noexcept : ConfirmationSender() { *this = conf; }
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& conf) noexcept
	{
		if (this != &conf)
		{
			reset();
			m_res_conf = new const Reservation*[m_no_res = conf.m_no_res];
			for (size_t i = 0; i < m_no_res; ++i)
				m_res_conf[i] = conf.m_res_conf[i];
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& conf) noexcept : ConfirmationSender() { *this = move(conf); }
	ConfirmationSender::~ConfirmationSender() { reset(); }
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& conf) noexcept
	{
		if (this != &conf) 
		{
			reset();
			m_res_conf = conf.m_res_conf;
			m_no_res = conf.m_no_res;
			conf.m_res_conf = nullptr;
			conf.m_no_res = 0;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool exists = false;
		for (size_t i = 0; i < m_no_res && !exists; ++i)
			exists = m_res_conf[i] == &res;

		if (!exists)
		{
			const Reservation** temp{ nullptr };
			temp = new const Reservation*[++m_no_res];

			if (m_no_res - 1) 
				for (size_t i = 0; i < m_no_res - 1; ++i)
					temp[i] = m_res_conf[i];
			temp[m_no_res - 1] = &res;
			reset();
			m_res_conf = move(temp);
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		bool exists = false;
		size_t idx = 0;
		for (size_t i = 0; i < m_no_res && !exists; ++i)
			exists = m_res_conf[idx = i] == &res;

		if (exists) 
		{
			const Reservation** temp{ nullptr };
			temp = new const Reservation*[--m_no_res];

			for (size_t i = 0, j = 0; i < m_no_res + 1; ++i)
			{
				if (i == idx) continue;
				temp[j++] = m_res_conf[i];
			}
			reset();
			m_res_conf = move(temp);
		}
		return *this;
	}
	ostream& operator<<(ostream& os, const ConfirmationSender& conf)
	{
		os << "--------------------------\n" << "Confirmations to Send\n" << "--------------------------\n";
		if (conf.m_res_conf != nullptr)
			for (size_t i = 0; i < conf.m_no_res; ++i)
				os << *conf.m_res_conf[i];
		else os << "There are no confirmations to send!\n";
		return os << "--------------------------" << endl;
	}
}
