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
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>
#include "Vehicle.h"
namespace sdds {
	Vehicle* createInstance(std::istream&);
	void trim_s(std::string&);
}
#endif // !SDDS_UTILITIES_H