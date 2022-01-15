//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Final Project:  MS3 
// Date:		   Nov 5, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#include "LineManager.h"
#include "Workstation.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
	LineManager::LineManager(const std::string& filename, const std::vector<Workstation*>& stations)
	{
		if (filename != "") {
			ifstream file(filename);
			if (file) {
				string temp{}, check{};
				Utilities utils;
				size_t pos = 0;
				bool ok = false;
				utils.setDelimiter('|');
				while (!file.eof()) {
					pos = 0;
					getline(file, temp);
					check = utils.extractToken(temp, pos, ok);
					m_active_line.push_back(const_cast<Workstation*>
						(*find_if(stations.cbegin(), stations.cend(), [&](const Workstation* stn) {return check == stn->getItemName(); })));
					if (!m_first_station)
						m_first_station = m_active_line.front();
					if (ok) {
						check = utils.extractToken(temp, pos, ok);
						m_active_line.back()->setNextStation(const_cast<Workstation*>
							(*find_if(stations.cbegin(), stations.cend(), [&](const Workstation* stn) {return check == stn->getItemName(); })));
					}
				}
			}
			else throw string{ "ERROR: Unable to open file!" };
		}
		else throw string{ "ERROR: No filename provided!" };
	}
	void LineManager::linkStations()
	{
		vector<Workstation*> swap{};
		swap.push_back(m_first_station);
		for_each(m_active_line.begin(), m_active_line.end()-1, [&](Workstation*) {swap.push_back(*find_if(m_active_line.cbegin(), m_active_line.cend(), [&](const Workstation* stn) {return swap.back()->getNextStation() ? swap.back()->getNextStation()->getItemName() == stn->getItemName() : false; })); });
		m_active_line.swap(swap);
		swap.clear();
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t cnt_orders = pending.size();
		static size_t cnt = 0;
		os << "Line Manager Iteration: " << ++cnt << "\n";
		if (!pending.empty()) {
			m_first_station->operator+=(move(pending.front()));
			pending.pop_front();
		}
		for_each(m_active_line.begin(), m_active_line.end(), [&](Workstation* stn) { stn->fill(os); });
		for_each(m_active_line.begin(), m_active_line.end(), [&](Workstation* stn) { if (stn->attemptToMoveOrder()) ++m_cnt_cus_order; });
		return cnt_orders == m_cnt_cus_order;
	}
	void LineManager::display(std::ostream& os) const
	{
		for_each(m_active_line.cbegin(), m_active_line.cend(), [&](const Workstation* stn) {stn->display(os); });
	}
}