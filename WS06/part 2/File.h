/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include <string>
#include "Resource.h"

namespace seneca {
	class File : public Resource {
		std::string m_contents;
	public:
		File(const std::string& name, const std::string& contents = "");
		void update_parent_path(const std::string& parentPath);
		NodeType type() const;
		std::string path() const;
		std::string name() const;
		int count() const;
		size_t size() const;
		~File() {};
	};
}
#endif

