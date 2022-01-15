//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS3 
// Date:		   Nov 5, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <string>
#include <utility>
#include <deque>
#include "Workstation.h"
#include "Station.h"
#include "CustomerOrder.h"
using namespace std;
namespace sdds {
	std::deque<CustomerOrder> pending{};
	std::deque<CustomerOrder> completed{};
	std::deque<CustomerOrder> incomplete{};
	Workstation::Workstation() : Station(), m_ptr_nxt_sttn{ nullptr } { }
	Workstation::Workstation(const string& str) : Station(str), m_ptr_nxt_sttn{ nullptr } { }
	void Workstation::fill(ostream& os) {
		if (!m_orders.empty()) {
			 m_orders.front().fillItem(*this, os);
		}
	}
	bool Workstation::attemptToMoveOrder()
	{
		bool ok = false;
		if (!m_orders.empty()) {
			if (m_orders.front().isItemFilled(getItemName()))
			{
				if (m_ptr_nxt_sttn) {
					m_ptr_nxt_sttn->operator+=(move(m_orders.front()));
					m_orders.pop_front();
				}
				else if(m_orders.front().isFilled())
				{
					completed.push_back(move(m_orders.front()));
					m_orders.pop_front();
					ok = true;
				}
				else {
					incomplete.push_back(move(m_orders.front()));
					m_orders.pop_front();
					ok = true;
				}
			}
			else if (!m_orders.front().isItemFilled(getItemName()) && !getQuantity())
			{
				if (m_ptr_nxt_sttn) {
					m_ptr_nxt_sttn->operator+=(move(m_orders.front()));
					m_orders.pop_front();
				}
				else {
					incomplete.push_back(move(m_orders.front()));
					m_orders.pop_front();
					ok = true;
				}
			}
		}
		return ok;
	}
	void Workstation::setNextStation(Workstation* station) { m_ptr_nxt_sttn = station; }
	Workstation* Workstation::getNextStation()const { return m_ptr_nxt_sttn; }
	void Workstation::display(std::ostream& os) const { os << getItemName() << " --> " << (m_ptr_nxt_sttn ? m_ptr_nxt_sttn->getItemName() : "End of Line") << "\n"; }
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}
}