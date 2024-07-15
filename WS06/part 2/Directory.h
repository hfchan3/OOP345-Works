/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H

#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Resource.h"
#include "Flags.h"

namespace seneca {
	class Directory : public Resource {
		std::vector<Resource*> m_contents;
	public:
		Directory(const std::string& name);
		void update_parent_path(const std::string& parentPath);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		Directory& operator+=(Resource* resource);
		Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {});
		~Directory();

		// Disable copy and move semantics
		Directory(const Directory& src) = delete;
		Directory& operator=(const Directory& src) = delete;
		Directory(const Directory&& src) = delete;
		Directory&& operator=(Directory&& src) = delete;

		void remove(const std::string& name, const std::vector<OpFlags>& flags = {});
		void display(std::ostream& os, const std::vector<FormatFlags>& flags = {}) const;
	};
}
#endif
