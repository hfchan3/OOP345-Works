//////////////////////////////////////////////////////////////////////////////////////
// Name:               Hiu Fung Chan
// Seneca Student ID:  106184237 
// Seneca email:       hfchan3@myseneca.ca
// Date of completion: 17 July 2024
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
//////////////////////////////////////////////////////////////////////////////////////

#include "LineManager.h"
#include "Workstation.h"
#include "Utilities.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>


namespace seneca {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
        std::ifstream dataFile(file);
        if (!dataFile) {
            throw std::runtime_error("Failed to open file: " + file);
        }

        std::vector<std::pair<std::string, std::string>> wsPairs;
        std::string line;

        while (std::getline(dataFile, line)) {
            std::istringstream iss(line);
            std::string stationItem, nextStationItem;
            std::getline(iss, stationItem, '|');
            std::getline(iss, nextStationItem);

            wsPairs.push_back({ stationItem, nextStationItem });
        }

        std::for_each(wsPairs.begin(), wsPairs.end(), [&](const std::pair<std::string, std::string>& stationPair) {
            auto stationFound = std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                return ws->getItemName() == stationPair.first;
            });

            if (stationFound != stations.end()) {
                auto foundNextStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* ws) {
                    return ws->getItemName() == stationPair.second;
                });
                if (foundNextStation != stations.end()) {
                    (*stationFound)->setNextStation(*foundNextStation);
                }
                m_activeLine.push_back(*stationFound);
            }
        });

        auto firstStationIt = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
            return std::none_of(stations.begin(), stations.end(), [&](Workstation* ws) {
                return ws->getNextStation() == station;
            });
        });

        if (firstStationIt != stations.end()) {
            m_firstStation = *firstStationIt;
        }

        m_cntCustomerOrder = g_pending.size();
    }

    void LineManager::reorderStations() {
        m_activeLine.clear();
        Workstation* current = m_firstStation;

        while (current) {
            m_activeLine.push_back(current);
            current = current->getNextStation();
        }
    }

    bool LineManager::run(std::ostream& os) {
        static size_t iteration = 0;
        os << "Line Manager Iteration: " << ++iteration << std::endl;

        // Move one order from g_pending to the first station if g_pending is not empty
        if (!g_pending.empty()) {
            *m_firstStation += std::move(g_pending.front());
            g_pending.pop_front();
        }

        // Fill orders at each workstation
        for (auto& station : m_activeLine) {
            station->fill(os);
        }

        // Attempt to move orders through each workstation
        for (auto& station : m_activeLine) {
            station->attemptToMoveOrder();
        }

        // Return true if all customer orders have been processed
        return (m_cntCustomerOrder == g_completed.size() + g_incomplete.size());
    }

    void LineManager::display(std::ostream& os) const {
        std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
	    ws->display(os);
	});
    }
}
