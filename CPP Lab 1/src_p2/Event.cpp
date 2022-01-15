#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "event.h"

extern unint g_sysClock;

void sdds::Event::parseTime() const
{
	unint hour = g_sysClock / 3600, min = (g_sysClock - (hour * 60)) / 60, sec = (g_sysClock - (hour * 60)) % 60;
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

sdds::Event::Event() { m_description = nullptr; }

sdds::Event::~Event() { delete[] m_description; }

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

void sdds::Event::set(char* info)
{
	if (info) {
		delete[] m_description;
		m_description = new char[strlen(info) + 1];
		strcpy(m_description, info);
	}
	else if(m_description) delete[] m_description;
}
