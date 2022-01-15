#include <iostream>
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

typedef unsigned int unint;

namespace sdds {
	class Event
	{
		char* m_description;
		void parseTime()const;
	public:
		Event();
		~Event();
		void display()const;
		void set(char* info = nullptr);

	};
}
#endif //!SDDS_EVENT_H