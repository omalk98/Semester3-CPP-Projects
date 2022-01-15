//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS1 
// Date:		   Nov 1, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <string>
#include "Station.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	size_t Station::m_widthField = 1;
	size_t Station::m_id_generator = 0;
	Station::Station() : m_id{ 0 }, m_item_name{}, m_description{}, m_next_serial{0}, m_quantity{0} { }
	Station::Station(const std::string& info) : Station()
	{
		if (info != "") {
			size_t pos = 0;
			bool ok = true;
			Utilities utils;
			m_id = ++m_id_generator;
			m_item_name = utils.extractToken(info, pos, ok);
			m_next_serial = stoi(utils.extractToken(info, pos, ok));
			m_quantity = stoi(utils.extractToken(info, pos, ok));
			if (m_widthField < m_item_name.size())
				m_widthField = m_item_name.size();
			else if (m_widthField < utils.getFieldWidth())
				m_widthField = utils.getFieldWidth();
			m_description = utils.extractToken(info, pos, ok);
		}
	}
	const std::string& Station::getItemName() const { return m_item_name; }
	size_t Station::getNextSerialNumber() { return m_next_serial++; }
	size_t Station::getQuantity() const { return m_quantity; }
	void Station::updateQuantity() { if (m_quantity) --m_quantity; }
	void Station::display(std::ostream& os, bool full)const
	{
		os << "[" << setfill('0') <<setw(3) << m_id << setfill(' ') << "] Item: " << left << setw(m_widthField) << m_item_name << " [" << right << setfill('0') << setw(6) << m_next_serial << setfill(' ') << "]";
		if (full)
			os << left << " Quantity: " << setw(m_widthField) << m_quantity << right << " Description: " << m_description;
		os << right << endl;
	}
}