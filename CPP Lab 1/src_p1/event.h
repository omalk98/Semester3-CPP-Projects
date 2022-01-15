//==============================================
// Name:           Omar Hussein
// Student Number: 118073204
// Email:          ohussein2@myseneca.ca
// Section:        NCC
// Workshop:       1 
// Date:		   Sept 11, 2021
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

typedef unsigned int unint;
extern unint g_sysClock;

namespace sdds {
	class Event
	{
		char* m_description = nullptr;
		unint m_startTime;
		void parseTime()const;
		void reset();
	public:
		Event();
		~Event();
		void display()const;
		void set(const char* info = nullptr);
		Event& operator=(const Event&);
		Event(const Event&);
	};
}
#endif //!SDDS_EVENT_H