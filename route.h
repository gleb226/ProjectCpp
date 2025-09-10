#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>

struct Route {
    int id;
    std::string name;
    int transportId;
    std::vector<int> stopIds;
};

extern std::vector<Route> routes;

void createRoute(const std::string& name, int transportId, const std::vector<int>& stopIds);
Route* getRouteById(int id);
void updateRoute(int id, const std::string& newName, int newTransportId, const std::vector<int>& newStopIds);
void deleteRoute(int id);

#endif
