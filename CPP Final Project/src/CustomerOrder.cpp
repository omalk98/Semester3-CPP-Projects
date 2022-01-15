//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS2 
// Date:		   Nov 2, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace sdds{
	size_t CustomerOrder::m_widthField = 1;
	void CustomerOrder::deleteItems(bool spec)
	{
		if (m_list_item && m_item_count) {
			for (size_t i = 0; i < (spec ? m_item_count - 1 : m_item_count); ++i)
			{
				delete m_list_item[i];
				m_list_item[i] = nullptr;
			}
		}
		delete[] m_list_item;
		m_list_item = nullptr;
	}
	CustomerOrder::CustomerOrder() : m_list_item{ nullptr } { }
	CustomerOrder::CustomerOrder(const string& str) : CustomerOrder()
	{
		size_t pos = 0;
		bool ok = false;
		Utilities utils;
		m_customer_name = utils.extractToken(str, pos, ok);
		m_product_name = utils.extractToken(str, pos, ok);
		while (ok) {
			++m_item_count;
			Item** temp = new Item*[m_item_count];
			if (m_list_item) {
				for (size_t i = 0; i < m_item_count - 1; ++i) {
					temp[i] = new Item(m_list_item[i]->m_itemName);
					temp[i]->m_serialNumber = m_list_item[i]->m_serialNumber;
					temp[i]->m_isFilled = m_list_item[i]->m_isFilled;
				}
				deleteItems(true);
			}
			temp[m_item_count - 1] = new Item(utils.extractToken(str, pos, ok));
			m_list_item = move(temp);
			temp = nullptr;
		}
		if (m_widthField < utils.getFieldWidth()) m_widthField = utils.getFieldWidth();
	}
	CustomerOrder::CustomerOrder(const CustomerOrder&) { throw std::string{ "ERROR: Cannot copy a CustomerOrder" }; }
	CustomerOrder::CustomerOrder(CustomerOrder&& order) noexcept : CustomerOrder() { *this = move(order); }
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& order) noexcept
	{
		if (this != &order) {
			deleteItems();
			m_list_item = order.m_list_item;
			m_customer_name = order.m_customer_name;
			m_product_name = order.m_product_name;
			m_item_count = order.m_item_count;
			order.m_list_item = nullptr;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder() { deleteItems(); }
	bool CustomerOrder::isFilled() const
	{
		bool filled = false;
		for (size_t i = 0; i < m_item_count; ++i)
		{
			filled = m_list_item[i]->m_isFilled;
			if (!filled) break;
		}
		return filled;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool filled = true;
		for (size_t i = 0; i < m_item_count; ++i) 
		{
			if (m_list_item[i]->m_itemName == itemName)
			{
				filled = m_list_item[i]->m_isFilled;
				if (!filled) break;
			}
		}
		return filled;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_item_count; ++i) 
		{
			if (station.getItemName() == m_list_item[i]->m_itemName) {
				if (station.getQuantity() > 0) {
					station.updateQuantity();
					m_list_item[i]->m_serialNumber = station.getNextSerialNumber();
					m_list_item[i]->m_isFilled = true;
					os << "    Filled " << m_customer_name << ", " << m_product_name << " [" << m_list_item[i]->m_itemName << "]\n";
				}
				else os << "    Unable to fill " << m_customer_name << ", " << m_product_name << " [" << m_list_item[i]->m_itemName << "]\n";
			}
		}
	}
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_customer_name << " - " << m_product_name << "\n";
		for (size_t i = 0; i < m_item_count; ++i)
			os << "[" << setfill('0') << setw(6) << m_list_item[i]->m_serialNumber << "] " << setfill(' ') << left << setw(m_widthField) << m_list_item[i]->m_itemName << right << " - " << (m_list_item[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << "\n";
	}
}