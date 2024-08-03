/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              15 July 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_DATABASE_H
#define SENECA_DATABASE_H

#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <algorithm>
#include <iterator>

namespace seneca {
	enum class Err_Status {
		Err_Success,
		Err_NotFound,
		Err_OutOfMemory,
	};

	template<typename T>
	class Database {
		static std::shared_ptr<Database> instance;
		std::string keys[20];
		T values[20];
		size_t numEntries{};
		std::string filename{};

		Database(const std::string& filename) : numEntries(0), filename(filename) {
			std::cout << "[" << this << "] Database(const std::string&)" << std::endl;

			std::ifstream dataFile(filename);
			if (dataFile.is_open()) {
				std::string key;
				T value;
				while (dataFile >> key >> value && numEntries < 20) {
					std::replace(key.begin(), key.end(), '_', ' ');
					encryptDecrypt(value);
					SetValue(key, value);
				}
				dataFile.close();
			}
		}

		void encryptDecrypt(T& value);
	public:
		static std::shared_ptr<Database> getInstance(const std::string& filename) {
			if (!instance) {
				instance = std::shared_ptr<Database>(new Database(filename));
			}
			return instance;
		}

		Err_Status GetValue(const std::string& key, T& value) {
			Err_Status success = Err_Status::Err_NotFound;
			for (size_t i = 0; i < numEntries; ++i) {
				if (keys[i] == key) {
					value = values[i];
					success = Err_Status::Err_Success;
				}
			}
			return success;
		}

		Err_Status SetValue(const std::string& key, const T& value) {
			Err_Status success = Err_Status::Err_OutOfMemory;
			if (numEntries < 20) {
				keys[numEntries] = key;
				values[numEntries] = value;
				numEntries++;
				success = Err_Status::Err_Success;
			}
			return success;
		}

		~Database() {
			std::cout << "[" << this << "] ~Database()" << std::endl;

			std::ofstream backupFile(filename + ".bkp.txt");
			for (size_t i = 0; i < numEntries; i++) {
				encryptDecrypt(values[i]);
				backupFile.setf(std::ios::left);
				backupFile.width(25);
				backupFile << keys[i] << " -> " << values[i];
				backupFile.unsetf(std::ios::left);
				backupFile << std::endl;
		    }
			backupFile.close();
		}

	};

	// Initialisation of static member
	template<typename T>
	std::shared_ptr<Database<T>> Database<T>::instance = nullptr;

	// Specialization for std::string in case of encryption/decryption
	template<>
	void Database<std::string>::encryptDecrypt(std::string& value) {
		const char secret[] = "secret encryption key";
		std::for_each(value.begin(), value.end(), [&](char& C) {
			std::for_each(std::begin(secret), std::end(secret) - 1, [&](const char& k) {
				C ^= k;
			});
		});
	}

	// Specialization for long long in case of encryption/decryption
	template<>
	void Database<long long>::encryptDecrypt(long long& value) {
	    const char secret[] = "super secret encryption key";
		char* B = reinterpret_cast<char*>(&value);
		std::for_each(B, B + sizeof(long long), [&](char& byte) {
			std::for_each(std::begin(secret), std::end(secret) - 1, [&](const char& k) {
				byte ^= k;
			});
		});
	}
}
#endif //!SENECA_DATABASE_H
