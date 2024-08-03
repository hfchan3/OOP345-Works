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

        // Proceed only if next_pos is not at the end of the string
        if (next_pos < str.length()) {
            // Find the position of the delimiter starting from next_pos
            size_t found = str.find(m_delimiter, next_pos);

            if (found == next_pos) {
                throw "Delimiter found at the start position";
            }

            // Extract the token
            if (found != std::string::npos) {
                token = str.substr(next_pos, found - next_pos);
                next_pos = found + 1;
                more = true;
            }
            else {
                token = str.substr(next_pos);
                next_pos = str.length();
            }

            // Trim leading and trailing whitespace from the token
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            if (start != std::string::npos) {
                token = token.substr(start, end - start + 1);
            }
            else {
                token.clear(); // In case the token is all spaces, clear it
            }

            // Update m_widthField if necessary
            if (token.length() > m_widthField) {
                m_widthField = token.length();
            }
            // If token is empty, set more to false
            if (token.empty()) {
                more = false;
            }
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