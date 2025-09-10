#include "schedule.h"
#include <algorithm>

std::vector<Schedule> schedules;
static int currentScheduleId = 1;

void createSchedule(int routeId, const std::string& time) {
    Schedule s;
    s.id = currentScheduleId++;
    s.routeId = routeId;
    s.time = time;
    schedules.push_back(s);
}

Schedule* getScheduleById(int id) {
    for (auto& s : schedules) {
        if (s.id == id) return &s;
    }
    return nullptr;
}

void updateSchedule(int id, int newRouteId, const std::string& newTime) {
    Schedule* s = getScheduleById(id);
    if (s) {
        s->routeId = newRouteId;
        s->time = newTime;
    }
}

void deleteSchedule(int id) {
    schedules.erase(std::remove_if(schedules.begin(), schedules.end(),
        [id](const Schedule& s) { return s.id == id; }), schedules.end());
}
