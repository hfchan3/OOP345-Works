/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "Filesystem.h"
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <string>

namespace seneca {
    Filesystem::Filesystem(const std::string& fileName, const std::string& rootName) {
        std::ifstream file(fileName);
        if (!file) {
            throw std::invalid_argument("File is not found: " + fileName);
        }
        m_root = new Directory(rootName);
        m_current = m_root;
        std::string line;

        while (getline(file, line)) {
            std::string filePath, fileContents;
            size_t delimiter = line.find("|");
            size_t pos1 = line.find_first_not_of(" ");
            size_t pos2 = line.find_last_not_of(" ", delimiter - 1);
            filePath = line.substr(pos1, pos2 - pos1 + 1);

            line.erase(0, delimiter + 1);
            pos1 = line.find_first_not_of(" ");
            line.erase(0, pos1);
            pos2 = line.find_last_not_of(" ");
            fileContents = line.substr(0, pos2 + 1);

            size_t pos = 0;
            std::vector<seneca::OpFlags> oflags = { seneca::OpFlags::RECURSIVE };
            Directory* root = m_root;

            while ((pos = filePath.find("/")) != std::string::npos) {
                std::string dirName = filePath.substr(0, pos + 1);
                Resource* resFound = root->find(dirName, oflags);
                if (!resFound) {
                    Directory* dir = new Directory(dirName);
                    *root += dir;
                    root = dir;
                }
                else {
                    root = dynamic_cast<Directory*>(resFound);
                }
                filePath = filePath.substr(pos + 1);
            }

            if (delimiter != std::string::npos) {
                if (!root->find(filePath)) {
                    File* file = new File(filePath, fileContents);
                    *root += file;
                }
            }
        }
    }

    Filesystem::~Filesystem() {
        delete m_root;
    }

    Filesystem::Filesystem(Filesystem&& src) noexcept {
        *this = std::move(src);
    }

    Filesystem& Filesystem::operator=(Filesystem&& src) noexcept {
        if (this != &src) {
            delete m_root;
            m_root = src.m_root;
            m_current = src.m_current;
            src.m_root = nullptr;
            src.m_current = nullptr;
        }
        return *this;
    }

    Directory* Filesystem::get_current_directory() const {
        return m_current;
    }

    Directory* Filesystem::change_directory(const std::string& dirName) {
        if (dirName.empty()) {
            m_current = m_root;
        }
        else {
            std::vector<seneca::OpFlags> oflags = { seneca::OpFlags::RECURSIVE };
            Directory* getDir = dynamic_cast<Directory*>(m_current->find(dirName, oflags));
            if (getDir) {
                m_current = getDir;
            }
            else {
                throw std::invalid_argument("Cannot change directory! " + dirName + " not found.");
            }
        }
        return m_current;
    }

    Filesystem& Filesystem::operator+=(Resource* resource) {
        *m_current += resource;
        return *this;
    }
}