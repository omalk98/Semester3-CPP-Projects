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
#include <sstream>
#include "Utilities.h"
#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(istream& is)
	{
		static bool chop = false;
		Vehicle* newV = nullptr;
		string chk{ };
		if (chop) getline(is, chk);
		getline(is, chk, ',');
		trim_s(chk);
		chop = false;
		if (chk == "c" || chk == "C")
			newV = new Car(is);
		else if (chk == "r" || chk == "R")
		{

			getline(is, chk);
			for (size_t i = chk.size() - 1; i > 0; --i)
				if (chk[i] == ',') { chk.at(i) = '\n'; break; }
			stringstream  iss{ chk };
			newV = new Racecar(iss);
		}
		else {
			chop = chk != "";
			if (chop) throw string{ "Unrecognized record type: [" + chk + "]" };
		}
		return newV;
	}

	void trim_s(string& data)
	{
		if (data != "" && data != " ") {
			for (size_t i = 0; i < data.size(); ++i)
				if (data[i] == ' ') data.erase(i--, 1);
				else break;
			for (size_t j = data.size() - 1; j > 0; --j)
				if (data[j] == ' ') data.erase(j, 1);
				else break;
		}
	}
}