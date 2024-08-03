/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				15 July 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>

namespace seneca {
	enum class Err_Status {
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	class Database {
		static std::shared_ptr<Database> instance;
		std::string keys[20];
		std::string values[20];
		size_t numEntries{};
		std::string filename{};

		Database(const std::string& filename);
	public:
		static std::shared_ptr<Database> getInstance(const std::string& filename);

		Err_Status GetValue(const std::string& key, std::string& value) const;
		Err_Status SetValue(const std::string& key, std::string& value);

		~Database();
	};
}
#endif //!SENECA_DATABASE_H