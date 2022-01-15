//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       2 
// Date:		   Sept 20, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include <iostream>
#include <string>
#include <chrono>

namespace sdds {
	const int MAX_NO_EVENTS = 10;
	
	class TimedEvents
	{
		unsigned int m_noOfRecs;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		struct Event {
			std::string m_eventName;
			std::string m_timeUnits;
			std::chrono::steady_clock::duration m_duration;
		} m_events[MAX_NO_EVENTS];
	public:
		TimedEvents();
		TimedEvents(const TimedEvents&);
		TimedEvents& operator=(const TimedEvents&);
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}
#endif //!SDDS_TIMEDEVENTS_H