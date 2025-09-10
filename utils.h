#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include "stop.h"
#include "route.h"
#include "schedule.h"

Stop* getStopById(int id);
Stop* findStopByName(const std::string& name);
std::vector<Route*> findRoutesByStopName(const std::string& stopName);
std::vector<Schedule*> findSchedulesByDateTime(const std::string& date, const std::string& time);
bool isValidTimeFormat(const std::string& time);
bool isValidDateFormat(const std::string& date);

#endif
