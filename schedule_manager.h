#ifndef SCHEDULE_MANAGER_H
#define SCHEDULE_MANAGER_H

#include "schedule.h"
#include <vector>

void manageSchedules();

class ScheduleManager {
public:
    std::vector<Schedule*> schedules;

    void addSchedule(Schedule* s);
    void listSchedules();
};

#endif
