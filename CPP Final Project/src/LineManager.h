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
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "Workstation.h"
namespace sdds {
	class LineManager
	{
		std::vector<Workstation*> m_active_line{};
		size_t m_cnt_cus_order{ 0 };
		Workstation* m_first_station{ nullptr };
	public:
		LineManager(const std::string&, const std::vector<Workstation*>&);
		void linkStations();
		bool run(std::ostream&);
		void display(std::ostream&)const;
	};
}
#endif // !SDDS_LINEMANAGER_H