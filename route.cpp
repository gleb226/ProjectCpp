#include "route.h"
#include <algorithm>

std::vector<Route> routes;
static int currentRouteId = 1;

void createRoute(const std::string& name, int transportId, const std::vector<int>& stopIds) {
    Route r;
    r.id = currentRouteId++;
    r.name = name;
    r.transportId = transportId;
    r.stopIds = stopIds;
    routes.push_back(r);
}

Route* getRouteById(int id) {
    for (auto& r : routes) {
        if (r.id == id) return &r;
    }
    return nullptr;
}

void updateRoute(int id, const std::string& newName, int newTransportId, const std::vector<int>& newStopIds) {
    Route* r = getRouteById(id);
    if (r) {
        r->name = newName;
        r->transportId = newTransportId;
        r->stopIds = newStopIds;
    }
}

void deleteRoute(int id) {
    routes.erase(std::remove_if(routes.begin(), routes.end(),
        [id](const Route& r) { return r.id == id; }), routes.end());
}
