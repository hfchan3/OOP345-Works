/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				15 July 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "Database.h"
#include <algorithm>
#include <iomanip>

namespace seneca {
	std::shared_ptr<Database> Database::instance = nullptr;

	Database::Database(const std::string& file) : numEntries(0), filename(file) {
		std::cout << "[" << this << "] Database(const std::string&)" << std::endl;
		
		std::ifstream infile(file);
		if (infile.is_open()) {
			std::string key, value;
			while (infile >> key >> value && numEntries < 20) {
				std::replace(key.begin(), key.end(), '_', ' ');
				keys[numEntries] = key;
				values[numEntries] = value;
				numEntries++;
			}
			infile.close();
		}
	}

	std::shared_ptr<Database> Database::getInstance(const std::string& filename) {
		if (!instance) {
			instance = std::shared_ptr<Database>(new Database(filename));
		}
		return instance;
	}

	Err_Status Database::GetValue(const std::string& key, std::string& value) const {
		for (size_t i = 0; i < numEntries; i++) {
			if (keys[i] == key) {
				value = values[i];
				return Err_Status::Err_Success;
			}
		}
		return Err_Status::Err_NotFound;
	}

	Err_Status Database::SetValue(const std::string& key, std::string& value) {
		if (numEntries < 20) {
			keys[numEntries] = key;
			values[numEntries] = value;
			numEntries++;
			return Err_Status::Err_Success;
		}
		return Err_Status::Err_OutOfMemory;
	}

	Database::~Database() {
		std::cout << "[" << this << "] ~Database()" << std::endl;

		std::ofstream backupFile(filename + ".bkp.txt");
		if (backupFile.is_open()) {
			for (size_t i = 0; i < numEntries; i++) {
				backupFile << std::left << std::setw(25) << keys[i] << " -> " << values[i] << std::endl;
			}
			backupFile.close();
		}
	}
}