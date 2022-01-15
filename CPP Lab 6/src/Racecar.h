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
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include "Car.h"
namespace sdds {
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar();
		Racecar(std::istream&);
		void display(std::ostream&)const override;
		double topSpeed()const override;
	};
}
#endif //!SDDS_RACECAR_H