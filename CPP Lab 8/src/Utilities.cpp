// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       8 
// Date:		   Nov 14, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product* pair = nullptr;
					pair = new Product(desc[i].desc, price[j].price);
					pair->validate();
					priceList.operator+=(*pair);
					delete pair;
					break;
				}
			}
		}

		return priceList;
	}
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t j = 0; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					unique_ptr<Product> pair(new Product(desc[i].desc, price[j].price));
					pair->validate();
					priceList.operator+=(*pair);
					break;
				}
			}
		}

		return priceList;
	}
}