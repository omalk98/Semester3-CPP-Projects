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
#include <iomanip>
#include <string>
#include <chrono>
#include "TimedEvents.h"

using namespace std;

namespace sdds {
	TimedEvents::TimedEvents() { m_noOfRecs = 0; }
	TimedEvents::TimedEvents(const TimedEvents& events) : TimedEvents() { *this = events; }
	TimedEvents& TimedEvents::operator=(const TimedEvents& events)
	{
		if (this != &events) 
		{
			m_noOfRecs = events.m_noOfRecs;
			m_startTime = events.m_startTime;
			m_endTime = events.m_endTime;
			*m_events = *(events.m_events);
		}
		return *this;
	}
	void TimedEvents::startClock() { m_startTime = chrono::steady_clock::now(); }
	void TimedEvents::stopClock() { m_endTime = chrono::steady_clock::now(); }
	void TimedEvents::addEvent(const char* evntName)
	{
		m_events[m_noOfRecs].m_eventName = evntName;
		m_events[m_noOfRecs].m_timeUnits = " nanoseconds";
		m_events[m_noOfRecs++].m_duration =	chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
	}
	
	ostream& operator<<(ostream& ostr, const TimedEvents& events)
	{
		ostr << "--------------------------\nExecution Times:\n--------------------------\n";
		for (unsigned int i = 0; i < events.m_noOfRecs; ++i) {
			ostr << setw(21) << left << events.m_events[i].m_eventName 
				<< setw(13) << right << events.m_events[i].m_duration.count() 
				<< events.m_events[i].m_timeUnits << endl;
		}
		ostr << "--------------------------\n";
		return ostr;
	}

}