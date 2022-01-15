//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS1 
// Date:		   Nov 1, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <string>
#include "Utilities.h"
using namespace std;
namespace sdds{
	char Utilities::m_delimiter = '\0';
	void Utilities::setFieldWidth(size_t width) { m_widthField = width; }
	size_t Utilities::getFieldWidth() const { return m_widthField; }
	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		string temp{};
		size_t idx = str.find(m_delimiter, next_pos);
		if (idx == string::npos) { more = false; idx = str.size(); }
		if (idx != next_pos) {
				temp = str.substr(next_pos, idx - next_pos);
				next_pos = ++idx;
				if (m_widthField < temp.size()) m_widthField = temp.size();
				more = next_pos <= str.size();
		}
		else {
			more = false;
			throw string{ "ERROR: Cannot read string further!" };
		}
		return temp;
	}
	void Utilities::setDelimiter(char delimiter) { m_delimiter = delimiter; }
	char Utilities::getDelimiter() { return m_delimiter; }
}