/*************************************************************************************************************************************
Name:              Hiu Fung CHAN
Seneca Email:      hfchan3@myseneca.ca
Seneca Student ID: 106184237
Date:              19 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
**************************************************************************************************************************************/
#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <fstream>
#include <utility>
#include <chrono>
#include <string>

namespace seneca {
	class TimedTask {
		int m_numRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		
		struct Task {
			std::string taskName;
			std::string unitsOfTime;
			std::chrono::steady_clock::duration taskDuration;
		};

		Task taskArr[10];

	public:
		TimedTask();
		void startClock();
		void stopClock();
		void addTask(const char* taskName);
		friend std::ostream& operator<<(std::ostream& ostr, TimedTask& tasks);
	};
}
#endif // !SENECA_TIMEDTASK_H