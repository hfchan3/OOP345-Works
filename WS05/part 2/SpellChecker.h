#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <iostream>
#include <string>

namespace seneca {
    class SpellChecker {
    private:
        const static int SIZE = 6;
        std::string m_badWords[SIZE];
        std::string m_goodWords[SIZE];
        int m_replacementCounts[SIZE] = { 0 };

    public:
        SpellChecker(const char* filename);
        void operator()(std::string& text);
        void showStatistics(std::ostream& out) const;
    };
}

#endif // SENECA_SPELLCHECKER_H
