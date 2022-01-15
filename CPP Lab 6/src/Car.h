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
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "Vehicle.h"
namespace sdds {
	class Car : public Vehicle
	{
		std::string m_maker;
		std::string m_condition;
		double m_top_speed;
	public:
		Car();
		Car(std::istream&);
		std::string condition()const override;
		double topSpeed()const override;
		void display(std::ostream&)const override;
	};
}
#endif // !SDDS_CAR_H