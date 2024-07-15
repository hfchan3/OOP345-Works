/*************************************************************************************************************************************
Name:				Hiu Fung CHAN
Seneca Email :		hfchan3@myseneca.ca
Seneca Student ID : 106184237
Date :				27 June 2024

I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my
workshops and assignments.This submitted piece of work has not been shared with any other student or 3rd party content provider.
***************************************************************************************************************************************/
#include "Directory.h"

namespace seneca {
	Directory::Directory(const std::string& name) {
		m_name = name;
	}

	void Directory::update_parent_path(const std::string& parentPath) {
		m_parent_path = parentPath;
		std::string newParentPath = path();

		for (auto i = m_contents.begin(); i != m_contents.end(); ++i) {
			(*i)->update_parent_path(newParentPath);
		}
	}

	NodeType Directory::type() const {
		return NodeType::DIR;
	}

	std::string Directory::path() const {
		return m_parent_path + m_name;
	}

	std::string Directory::name() const {
		return m_name;
	}

	int Directory::count() const {
		return m_contents.size();
	}

	size_t Directory::size() const {
		size_t totalSize = 0;
		for (Resource* resource : m_contents) {
			totalSize += resource->size();
		}
		return totalSize;
	}

	Directory& Directory::operator+=(Resource* resource) {
		for (Resource* existingResource : m_contents) {
			if (existingResource->name() == resource->name()) {
				throw std::runtime_error("Resource with the same name already exists in the directory!");
			}
		}
		m_contents.push_back(resource);
		resource->update_parent_path(path());
		return *this;
	}

	Resource* Directory::find(const std::string& name, const std::vector<OpFlags>& flags) {
		for (Resource* resource : m_contents) {
			if (resource->name() == name) {
				return resource;
			}
		}

		bool recursiveSearch = false;
		for (OpFlags flag : flags) {
			if (flag == OpFlags::RECURSIVE) {
				recursiveSearch = true;
				break;
			}
		}

		if (recursiveSearch) {
			for (Resource* resource : m_contents) {
				if (resource->type() == NodeType::DIR) {
					Directory* dir = dynamic_cast<Directory*>(resource);
					if (dir) {
						Resource* found = dir->find(name, flags);
						if (found) {
							return found;
						}
					}
				}
			}
		}
		return nullptr;
	}

	Directory::~Directory() {
		for (Resource* resource : m_contents) {
			delete resource;
		}
	}
}