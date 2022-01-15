//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       6 
// Date:		   Oct 26, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <vector>
#include "Autoshop.h"

using namespace std;
namespace sdds {
	Autoshop& Autoshop::operator+=(Vehicle* vehicle)
	{
		m_vehicles.push_back(vehicle);
		return *this;
	}
	void Autoshop::display(ostream& os) const
	{
		os << "--------------------------------\n| Cars in the autoshop!        |\n--------------------------------\n";
		for (auto it = m_vehicles.begin(); it < m_vehicles.end(); ++it)
		{
			(*it)->display(os);
			os << endl;
		}
		os << "--------------------------------\n";
	}
	Autoshop::~Autoshop()
	{
		for (const auto vhc : m_vehicles)
			delete vhc;
	}
}