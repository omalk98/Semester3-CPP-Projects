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
#include <iomanip>
#include <cstring>
#include "event.h"

#define _CRT_SECURE_NO_WARNINGS

unint g_sysClock = 0;

void sdds::Event::parseTime() const
{
	unint hour = m_startTime / 3600, min = (m_startTime - (hour * 3600)) / 60, sec = (m_startTime - (hour * 3600)) % 60;
	if (min >= 60)
	{
		hour += min / 60;
		min %= 60;
	}
	if (hour >= 24) hour %= 24;
	std::cout.fill('0');
	std::cout << std::setw(2) << hour << ":" << std::setw(2) << min << ":" << std::setw(2) << sec;
	std::cout.fill(' ');
}

void sdds::Event::reset() { if (m_description) delete[] m_description; m_description = nullptr; }

sdds::Event::Event() { m_description = nullptr; m_startTime = 0; }

sdds::Event::~Event() { reset(); }

void sdds::Event::display()const
{
	static unint counter = 0;

	std::cout << std::setw(2) << ++counter << ". ";
	if (m_description)
	{
		parseTime();
		std::cout << " => " << m_description;
	}
	else std::cout << "| No Event |";
	std::cout << std::endl;
}

void sdds::Event::set(const char* info)
{
	reset();
	if (info) {
		m_description = new char[strlen(info) + 1];
		strcpy(m_description, info);
		m_startTime = g_sysClock;
	}
}

sdds::Event& sdds::Event::operator=(const Event& Event)
{
	if (this != &Event && Event.m_description) 
	{
		reset();
		m_description = new char[strlen(Event.m_description) + 1];
		strcpy(m_description, Event.m_description);
		m_startTime = Event.m_startTime;
	}
	return *this;
}

sdds::Event::Event(const Event& Event) : sdds::Event::Event() { *this = Event; }
