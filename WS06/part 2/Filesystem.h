/*************************************************************************************************************************************
Name:               Hiu Fung CHAN
Seneca Email :      hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :              27 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#ifndef SENECA_FILESYSTEM_H
#define SENECA_FILESYSTEM_H

#include <string>
#include <iostream>
#include "Directory.h"
#include "File.h"

namespace seneca {
	class Filesystem {
        Directory* m_root;
        Directory* m_current;

    public:
        Filesystem(const std::string& fileName, const std::string& rootName = "");
        ~Filesystem();

        // Disallow copy operations
        Filesystem(const Filesystem& src) = delete;
        Filesystem& operator=(const Filesystem& src) = delete;

        // Allow move operations
        Filesystem(Filesystem&& src) noexcept;
        Filesystem& operator=(Filesystem&& src) noexcept;

        Directory* get_current_directory() const;
        Directory* change_directory(const std::string& dirName = "");
        Filesystem& operator+=(Resource* resource);
	};
}
#endif
