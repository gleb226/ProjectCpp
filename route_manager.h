#ifndef ROUTE_MANAGER_H
#define ROUTE_MANAGER_H

#include "route.h"
#include <vector>

void manageRoutes();

class RouteManager {
public:
    std::vector<Route *> routes;

    void addRoute(Route *r);

    void listRoutes();
};

#endif
