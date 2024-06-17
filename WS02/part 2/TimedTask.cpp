/*************************************************************************************************************************************
Name:              Hiu Fung CHAN
Seneca Email:      hfchan3@myseneca.ca
Seneca Student ID: 106184237
Date:              19 May 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.
**************************************************************************************************************************************/
#include <iostream>
#include <fstream>
#include <chrono>
#include <utility>
#include <string>
#include "TimedTask.h"

namespace seneca {
	TimedTask::TimedTask() {
		m_numRecords = 0;
	}

	void TimedTask::startClock() {
		startTime = std::chrono::steady_clock::now();
	}

	void TimedTask::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(const char* taskName) {
		if (m_numRecords < 10) {
			taskArr[m_numRecords].taskName = taskName;
			taskArr[m_numRecords].unitsOfTime = "nanoseconds";
			taskArr[m_numRecords].taskDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
			m_numRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& ostr, TimedTask& tasks) {
		ostr << "--------------------------\n";
		ostr << "Execution Times:\n--------------------------\n";
		for (int i = 0; i < tasks.m_numRecords; i++) {
			ostr.setf(std::ios::left);
			ostr.width(21);
			ostr << tasks.taskArr[i].taskName;
			ostr.unsetf(std::ios::left);
			ostr.setf(std::ios::right);
			ostr.width(13);
			ostr << tasks.taskArr[i].taskDuration.count();
			ostr.unsetf(std::ios::right);
			ostr << " " << tasks.taskArr[i].unitsOfTime << std::endl;
		}
		ostr << "--------------------------" << std::endl;
		return ostr;
	}
}