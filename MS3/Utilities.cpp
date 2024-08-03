//////////////////////////////////////////////////////////////////////////////////////
// Name:               Hiu Fung Chan
// Seneca Student ID:  106184237 
// Seneca email:       hfchan3@myseneca.ca
// Date of completion: 10 July 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//////////////////////////////////////////////////////////////////////////////////////

#include "Utilities.h"

namespace seneca {
	char Utilities::m_delimiter{};

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;

	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		std::string token{};
		more = false;
		std::string tempStr = str;
		size_t found = tempStr.find(m_delimiter, next_pos);
		if (found == next_pos) {
			throw "Delimeter found at the start position";
		}
		tempStr.erase(0, next_pos);
		found = tempStr.find(m_delimiter);


		if (found != std::string::npos) {
			size_t pos1 = tempStr.find_first_not_of(" ");
			size_t pos2 = tempStr.find_last_not_of(" ", found - 1);
			if (pos2 != std::string::npos) {
				token = tempStr.substr(pos1, pos2 - pos1 + 1);
			}
			else {
				token = tempStr.substr(pos1, found - pos1);
			}
			more = true;
			next_pos += (found + 1);
		}
		else {
			size_t pos1 = tempStr.find_first_not_of(" ");
			token = tempStr.substr(pos1);
			more = false;
		}

		if (token.length() == 0) {
			more = false;
		}
		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}
		return token;
	}

	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}