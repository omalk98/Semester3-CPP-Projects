//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS3 
// Date:		   Nov 5, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <iostream>
#include <string>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"
namespace sdds {
	class Workstation;
	extern std::deque<CustomerOrder> pending;
	extern std::deque<CustomerOrder> completed;
	extern std::deque<CustomerOrder> incomplete;
	class Workstation : public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_ptr_nxt_sttn;
	public:
		Workstation();
		Workstation(const std::string&);
		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;
		void fill(std::ostream&);
		bool attemptToMoveOrder();
		void setNextStation(Workstation*);
		Workstation* getNextStation()const;
		void display(std::ostream&)const;
		Workstation& operator+=(CustomerOrder&&);

	};
}
#endif // !SDDS_WORKSTATION_H