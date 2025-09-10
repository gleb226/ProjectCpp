#include "reports.h"
#include "route.h"
#include "stop.h"
#include "transport.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

extern std::vector<Route> routes;
extern std::vector<Stop> stops;
extern std::vector<Transport> transports;

void showMostPopularStops() {
    std::map<int, int> stopUsageCount;
    for (const auto& route : routes) {
        for (int stopId : route.stopIds) {
            stopUsageCount[stopId]++;
        }
    }
    if (stopUsageCount.empty()) {
        std::cout << "No data available for report.\n";
        return;
    }
    std::cout << "\n=== Most Popular Stops ===\n";
    for (const auto& [stopId, count] : stopUsageCount) {
        auto it = std::find_if(stops.begin(), stops.end(), [stopId](const Stop& s) {
            return s.id == stopId;
        });
        if (it != stops.end()) {
            std::cout << "Stop: " << it->name << " | Times Used: " << count << '\n';
        }
    }
}

void showMostPopularTransport() {
    std::map<int, int> transportUsageCount;
    for (const auto& route : routes) {
        transportUsageCount[route.transportId]++;
    }
    if (transportUsageCount.empty()) {
        std::cout << "No data available for report.\n";
        return;
    }
    std::cout << "\n=== Most Popular Transport ===\n";
    for (const auto& [transportId, count] : transportUsageCount) {
        auto it = std::find_if(transports.begin(), transports.end(), [transportId](const Transport& t) {
            return t.id == transportId;
        });
        if (it != transports.end()) {
            std::cout << "Transport: " << it->name << " | Used in Routes: " << count << '\n';
        }
    }
}

void showRouteStatistics() {
    if (routes.empty()) {
        std::cout << "No routes available.\n";
        return;
    }
    std::cout << "\n=== Route Statistics ===\n";
    for (const auto& route : routes) {
        std::cout << "Route: " << route.name
                  << " | Number of Stops: " << route.stopIds.size() << '\n';
    }
}

void showStopsWithoutRoutes() {
    std::vector<int> stopsInRoutes;
    for (const auto& route : routes) {
        for (int stopId : route.stopIds) {
            stopsInRoutes.push_back(stopId);
        }
    }
    std::sort(stopsInRoutes.begin(), stopsInRoutes.end());
    stopsInRoutes.erase(std::unique(stopsInRoutes.begin(), stopsInRoutes.end()), stopsInRoutes.end());

    std::cout << "\n=== Stops without Routes ===\n";
    bool found = false;
    for (const auto& stop : stops) {
        if (!std::binary_search(stopsInRoutes.begin(), stopsInRoutes.end(), stop.id)) {
            std::cout << "Stop: " << stop.name << '\n';
            found = true;
        }
    }
    if (!found) {
        std::cout << "All stops are included in routes.\n";
    }
}

void showTopRoutesByStops() {
    if (routes.empty()) {
        std::cout << "No routes available.\n";
        return;
    }
    std::vector<const Route*> sortedRoutes;
    for (const auto& r : routes) {
        sortedRoutes.push_back(&r);
    }
    std::sort(sortedRoutes.begin(), sortedRoutes.end(), [](const Route* a, const Route* b) {
        return a->stopIds.size() > b->stopIds.size();
    });

    std::cout << "\n=== Top Routes by Number of Stops ===\n";
    int limit = std::min(5, (int)sortedRoutes.size());
    for (int i = 0; i < limit; i++) {
        const auto* route = sortedRoutes[i];
        std::cout << i + 1 << ". " << route->name << " | Stops: " << route->stopIds.size() << '\n';
    }
}

void showReports() {
    std::cout << "\n=== Reports Menu ===\n";
    std::cout << "1. Show most popular stops\n";
    std::cout << "2. Show most popular transport\n";
    std::cout << "3. Show route statistics\n";
    std::cout << "4. Show stops without routes\n";
    std::cout << "5. Show top routes by number of stops\n";
    std::cout << "0. Back\n";
    std::cout << "Select an option: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1: showMostPopularStops(); break;
        case 2: showMostPopularTransport(); break;
        case 3: showRouteStatistics(); break;
        case 4: showStopsWithoutRoutes(); break;
        case 5: showTopRoutesByStops(); break;
        case 0: return;
        default: std::cout << "Invalid option.\n";
    }
}
