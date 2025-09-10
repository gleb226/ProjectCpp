#include "utils.h"
#include <regex>
#include <algorithm>

extern std::vector<Stop> stops;
extern std::vector<Route> routes;
extern std::vector<Schedule> schedules;

Stop* findStopByName(const std::string& name) {
    for (auto& s : stops) {
        if (s.name == name) return &s;
    }
    return nullptr;
}

std::vector<Route*> findRoutesByStopName(const std::string& stopName) {
    std::vector<Route*> result;
    for (auto& r : routes) {
        for (int stopId : r.stopIds) {
            Stop* stop = getStopById(stopId);
            if (stop && stop->name == stopName) {
                result.push_back(&r);
                break;
            }
        }
    }
    return result;
}

std::vector<Schedule*> findSchedulesByDateTime(const std::string& date, const std::string& time) {
    std::vector<Schedule*> result;
    for (auto& s : schedules) {
        if (s.date == date && s.time == time) {
            result.push_back(&s);
        }
    }
    return result;
}

bool isValidTimeFormat(const std::string& time) {
    std::regex timePattern(R"(^([01]\d|2[0-3]):([0-5]\d)$)");
    return std::regex_match(time, timePattern);
}

bool isValidDateFormat(const std::string& date) {
    std::regex datePattern(R"(^\d{4}-\d{2}-\d{2}$)");
    return std::regex_match(date, datePattern);
}
