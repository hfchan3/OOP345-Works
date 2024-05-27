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
#include <utility>
#include <chrono>
#include <string>
#include "ProteinDatabase.h"

namespace seneca {
	ProteinDatabase::ProteinDatabase() = default;

	ProteinDatabase::ProteinDatabase(std::string fileName) {
		std::ifstream file(fileName);
		std::string line;
		size_t count = 0;

		// Count the number of protein sequences
		for (; std::getline(file, line);) {
			if (!line.empty() && line[0] == '>') {
				count++;
			}
		}

		// Set the number of proteins
		m_numProteins = count;
		// Allocate memory for the protein array
		m_proteinArr = new std::string[m_numProteins];

		// Reset file stream to the beginning state
		file.clear();
		file.seekg(0, std::ios::beg);

		size_t index = 0;
		bool isProtein = false;

		// Read and store protein sequences
		for (; std::getline(file, line);) {
			if (!line.empty() && line[0] == '>') {
				if (isProtein) {
					index++;
				}
				isProtein = true;
			}
			else if (isProtein) {
				m_proteinArr[index] += line;
			}
		}
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
		*this = src;
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& src) {
		// Take control of the resources of the src object
		m_proteinArr = src.m_proteinArr;
		m_numProteins = src.m_numProteins;

		// Reset the src object
		src.m_proteinArr = nullptr;
		src.m_numProteins = 0;
	}

	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src) {
		// Check self-assignment
		if (this != &src) {
			delete[] m_proteinArr;

			// Take control of the resources of the src object
			m_proteinArr = src.m_proteinArr;
			m_numProteins = src.m_numProteins;

			// Reset the src object
			src.m_proteinArr = nullptr;
			src.m_numProteins = 0;
		}
		return *this;
	}

	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src) {
		if (this != &src) {
			delete[] m_proteinArr;
			m_numProteins = src.m_numProteins;
			m_proteinArr = new std::string[m_numProteins];
			for (size_t i = 0; i < m_numProteins; i++) {
				m_proteinArr[i] = src.m_proteinArr[i];
			}
		}
		return *this;
	}

	ProteinDatabase::~ProteinDatabase() {
		delete[] m_proteinArr;
	}

	size_t ProteinDatabase::size() const {
		return m_numProteins;
	}

	std::string ProteinDatabase::operator[](size_t index) const {
		std::string result = "";
		if (index >= 0 && index < m_numProteins && m_numProteins > 0) {
			result = m_proteinArr[index];
		}
		return result;
	}
}