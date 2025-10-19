#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>

struct Schedule {
    int id;
    int routeId;
    std::string time;
    std::string date;
};

extern std::vector<Schedule> schedules;

void createSchedule(int routeId, const std::string &time);

Schedule *getScheduleById(int id);

void updateSchedule(int id, int newRouteId, const std::string &newTime);

void deleteSchedule(int id);

#endif
