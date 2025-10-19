#include "stop.h"
#include <vector>
#include <string>
#include <algorithm>

std::vector<Stop> stops;

int generateStopId() {
    static int currentId = 1;
    return currentId++;
}

void createStop(const std::string &name, const std::string &location) {
    Stop s;
    s.id = generateStopId();
    s.name = name;
    s.location = location;
    stops.push_back(s);
}

Stop *getStopById(int id) {
    for (auto &s: stops) {
        if (s.id == id) return &s;
    }
    return nullptr;
}

void updateStop(int id, const std::string &newName, const std::string &newLocation) {
    for (auto &s: stops) {
        if (s.id == id) {
            s.name = newName;
            s.location = newLocation;
            break;
        }
    }
}

void deleteStop(int id) {
    stops.erase(std::remove_if(stops.begin(), stops.end(),
                               [id](const Stop &s) { return s.id == id; }), stops.end());
}
