//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS1 
// Date:		   Nov 1, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <string>
namespace sdds {
	class Station
	{
		int m_id;
		std::string m_item_name;
		std::string m_description;
		size_t m_next_serial;
		size_t m_quantity;
		static size_t m_widthField;
		static size_t m_id_generator;
	public:
		Station();
		Station(const std::string&);
		const std::string& getItemName()const;
		size_t getNextSerialNumber();
		size_t getQuantity()const;
		void updateQuantity();
		void display(std::ostream&, bool) const;
	};
}
#endif // !SDDS_STATION_H