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

	ProteinDatabase::ProteinDatabase(std::string fileName)
	{
		m_numProteins = 0;
		std::string dataFile;
		std::ifstream in;
		in.open(fileName);
		in.ignore();

		while (in)
		{
			std::getline(in, dataFile, '>');
			m_numProteins++;
		}

		m_numProteins--;

		in.clear();
		in.seekg(0);
		in.ignore();

		m_proteinArr = new std::string[m_numProteins];
		for (size_t i = 0; i < m_numProteins; i++)
		{
			in.ignore(1000, '\n');
			std::getline(in, dataFile, '>');
			m_proteinArr[i] = fileString;
		}
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& src) {
		*this = src;
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
	if (index >= 0 && index < m_numProteins && m_numProteins > 0) {
			return m_proteinArr[index];
		}
		else {
			return "";
		}
	}
}