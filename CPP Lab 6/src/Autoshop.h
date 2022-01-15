//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       6 
// Date:		   Oct 26, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds {
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle*);
		void display(std::ostream&)const;
		~Autoshop();
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (const auto vhc : m_vehicles)
				if (test(vhc)) vehicles.push_back(vhc);
		}
	};
}
#endif //!SDDS_AUTOSHOP_H