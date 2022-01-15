//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS2 
// Date:		   Nov 2, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include "Station.h"
namespace sdds {
	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };

			Item(const std::string& src) : m_itemName(src) {};
		} **m_list_item;
		std::string m_customer_name{};
		std::string m_product_name{};
		size_t m_item_count{ 0 };
		static size_t m_widthField;
		void deleteItems(bool spec = false);
	public:
		CustomerOrder();
		CustomerOrder(const std::string&);
		CustomerOrder(const CustomerOrder&);
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&&)noexcept;
		CustomerOrder& operator=(CustomerOrder&&)noexcept;
		~CustomerOrder();
		bool isFilled()const;
		bool isItemFilled(const std::string&)const;
		void fillItem(Station&, std::ostream&);
		void display(std::ostream&)const;
	};
}
#endif // !SDDS_CUSTOMERORDER_H