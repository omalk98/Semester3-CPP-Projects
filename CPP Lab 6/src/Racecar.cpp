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
#include <string>
#include "Racecar.h"
using namespace std;
namespace sdds {
	Racecar::Racecar() : Car(), m_booster{ 0 } { }
	Racecar::Racecar(std::istream& is) : Car(is), m_booster{ 0 } { is >> m_booster; }
	void Racecar::display(std::ostream& os) const { Car::display(os); os << "*"; }
	double Racecar::topSpeed() const { return Car::topSpeed() * (m_booster + 1); }
}