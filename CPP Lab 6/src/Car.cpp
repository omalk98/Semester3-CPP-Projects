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
#include <string>
#include "Car.h"
#include "Utilities.h"

using namespace std;
namespace sdds {
	Car::Car() : m_maker{ }, m_condition{ }, m_top_speed{ 0 } { }
	Car::Car(istream& is) : Car()
	{
		string tmp{ };
		size_t cnt = 0, idx = 0;

		getline(is, tmp);

		m_maker = tmp.substr(idx, cnt = tmp.find(',', idx) - idx);
		idx += ++cnt;
		trim_s(m_maker);

		m_condition = tmp.substr(idx, cnt = tmp.find(',', idx) - idx);
		idx += ++cnt;
		trim_s(m_condition);
		if (m_condition == "" || m_condition == " ") m_condition = "n";
		else if (m_condition != "n" && m_condition != "u" && m_condition != "b") throw string{ "Invalid record!" };

		try {
			m_top_speed = stod(tmp.substr(idx, tmp.size() - idx));
		}
		catch (std::invalid_argument&) {
			throw string{ "Invalid record!" };
		}
	}

	string Car::condition() const { return m_condition; }
	double Car::topSpeed() const { return m_top_speed; }
	void Car::display(ostream& os)const 
	{
		os << "| " << setw(10) << m_maker << " | " << setw(6) << left <<;
		if (m_condition == "n")
			os << "new";
		else if (m_condition == "u")
			os << "used";
		else if (m_condition == "b")
			os << "broken";
		os << " | " << right <<  fixed << setprecision(2) << setw(6) << topSpeed() << " |"; }
}