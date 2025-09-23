#include "reports.h"
#include "route.h"
#include "stop.h"
#include "transport.h"
#include "colors.h"
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
        std::cout << ORANGE << "No data available for report.\n" << RESET;
        return;
    }
    std::cout << LAVENDER << "\n=== Most Popular Stops ===\n" << RESET;
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
        std::cout << ORANGE << "No data available for report.\n" << RESET;
        return;
    }
    std::cout << MINT << "\n=== Most Popular Transport ===\n" << RESET;
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
        std::cout << ORANGE << "No routes available.\n" << RESET;
        return;
    }
    std::cout << PEACH << "\n=== Route Statistics ===\n" << RESET;
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

    std::cout << LIGHT_BLUE << "\n=== Stops without Routes ===\n" << RESET;
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
        std::cout << ORANGE << "No routes available.\n" << RESET;
        return;
    }
    std::vector<const Route*> sortedRoutes;
    for (const auto& r : routes) {
        sortedRoutes.push_back(&r);
    }
    std::sort(sortedRoutes.begin(), sortedRoutes.end(), [](const Route* a, const Route* b) {
        return a->stopIds.size() > b->stopIds.size();
    });

    std::cout << LIGHT_YELLOW << "\n=== Top Routes by Number of Stops ===\n" << RESET;
    int limit = std::min(5, (int)sortedRoutes.size());
    for (int i = 0; i < limit; i++) {
        const auto* route = sortedRoutes[i];
        std::cout << i + 1 << ". " << route->name << " | Stops: " << route->stopIds.size() << '\n';
    }
}

void showReports() {
    std::cout << "\n=== Reports Menu ===\n";
    std::cout << LIGHT_PINK << "1. Show most popular stops\n";
    std::cout << "2. Show most popular transport\n";
    std::cout << "3. Show route statistics\n";
    std::cout << "4. Show stops without routes\n";
    std::cout << "5. Show top routes by number of stops\n" << RESET;
    std::cout << GRAY << "0. Back\n" << RESET;
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
        default: std::cout << RED << "Invalid option.\n" << RESET;
    }
}
