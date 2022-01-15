//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       2 
// Date:		   Sept 20, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "StringSet.h"
using namespace std;

namespace sdds {
	void StringSet::reset() { m_noOfStrings = 0; delete[] m_strings; m_strings = nullptr; }
	StringSet::StringSet() { m_noOfStrings = 0; m_strings = nullptr; }
	StringSet::StringSet(const char* filename) : StringSet()
	{
		if (filename) {
			ifstream file(filename);
			if (file) {
				char ch = ' ';
				while (!file.eof())
				{
					file.get(ch);
					if (ch == ' ') ++m_noOfStrings;
				}
				if (m_noOfStrings) 
				{
					file.clear();
					file.seekg(0);
					m_strings = new string[++m_noOfStrings];
					for (size_t j = 0; j < m_noOfStrings && !file.eof();) {
						ch = ' ';
						file.get(ch);
						if (ch != ' ') m_strings[j] += ch;
						else ++j;
					}
				}
				file.close();
			}
		}
	}
	StringSet::StringSet(const StringSet& strings) : StringSet() { *this = strings; }
	StringSet::StringSet(StringSet&& strings) : StringSet() { *this = move(strings); }
	StringSet::~StringSet() { reset(); }

	StringSet& StringSet::operator=(const StringSet& strings)
	{
		if (this != &strings) 
		{
			reset();
			m_noOfStrings = strings.m_noOfStrings;
			m_strings = new string[m_noOfStrings];
			for (size_t i = 0; i < m_noOfStrings; ++i)
				m_strings[i] = strings.m_strings[i];
		}
		return *this;
	}

	StringSet& StringSet::operator=(StringSet&& strings)
	{
		if (this != &strings) 
		{
			reset();
			m_noOfStrings = strings.m_noOfStrings;
			m_strings = strings.m_strings;
			strings.m_strings = nullptr;
			strings.m_noOfStrings = 0;
		}
		return *this;
	}

	size_t StringSet::size()const { return m_noOfStrings; }

	string StringSet::operator[](size_t idx)const { return (idx < m_noOfStrings) ? m_strings[idx] : ""; }
}