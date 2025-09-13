#include "file_io.h"
#include "colors.h"
#include <iostream>
#include <fstream>
#include "stop.h"
#include "transport.h"
#include "route.h"
#include "schedule.h"

extern std::vector<Stop> stops;
extern std::vector<Transport> transports;
extern std::vector<Route> routes;
extern std::vector<Schedule> schedules;

void saveAllData() {
    std::cout << MINT << "\n=== Saving Data ===" << RESET << std::endl;

    saveStops();
    saveTransports();
    saveRoutes();
    saveSchedules();

    std::cout << GREEN << "✓ All data saved successfully!" << RESET << std::endl;
}

void loadAllData() {
    std::cout << MINT << "\n=== Loading Data ===" << RESET << std::endl;

    loadStops();
    loadTransports();
    loadRoutes();
    loadSchedules();

    std::cout << BLUE << "✓ All data loaded successfully!" << RESET << std::endl;
}

void saveStops() {
    std::ofstream file("stops.txt");
    if (!file.is_open()) {
        std::cout << ORANGE << "⚠ Failed to open stops.txt for writing." << RESET << std::endl;
        return;
    }

    for (const auto& stop : stops) {
        file << stop.id << "|" << stop.name << "|" << stop.location << std::endl;
    }

    std::cout << PEACH << "→ Stops saved to file" << RESET << std::endl;
    file.close();
}

void saveTransports() {
    std::ofstream file("transports.txt");
    if (!file.is_open()) {
        std::cout << ORANGE << "⚠ Failed to open transports.txt for writing." << RESET << std::endl;
        return;
    }

    for (const auto& transport : transports) {
        file << transport.id << "|" << transport.name << std::endl;
    }

    std::cout << LIGHT_BLUE << "→ Transports saved to file" << RESET << std::endl;
    file.close();
}

void saveRoutes() {
    std::ofstream file("routes.txt");
    if (!file.is_open()) {
        std::cout << ORANGE << "⚠ Failed to open routes.txt for writing." << RESET << std::endl;
        return;
    }

    for (const auto& route : routes) {
        file << route.id << "|" << route.name << "|" << route.transportId << "|";
        for (size_t i = 0; i < route.stopIds.size(); ++i) {
            if (i > 0) file << ",";
            file << route.stopIds[i];
        }
        file << std::endl;
    }

    std::cout << LIGHT_PURPLE << "→ Routes saved to file" << RESET << std::endl;
    file.close();
}

void saveSchedules() {
    std::ofstream file("schedules.txt");
    if (!file.is_open()) {
        std::cout << ORANGE << "⚠ Failed to open schedules.txt for writing." << RESET << std::endl;
        return;
    }

    for (const auto& schedule : schedules) {
        file << schedule.id << "|" << schedule.routeId << "|"
             << schedule.time << std::endl;  // ✅ ВИПРАВЛЕНО
    }

    std::cout << LIGHT_YELLOW << "→ Schedules saved to file" << RESET << std::endl;
    file.close();
}
void loadStops() {
    std::ifstream file("stops.txt");
    if (!file.is_open()) {
        std::cout << GRAY << "ℹ No stops.txt found, starting with empty data" << RESET << std::endl;
        return;
    }

    stops.clear();
    std::string line;
    while (std::getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos) {
            Stop stop;
            stop.id = std::stoi(line.substr(0, pos1));
            stop.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            stop.location = line.substr(pos2 + 1);
            stops.push_back(stop);
        }
    }

    std::cout << PEACH << "✓ Loaded " << stops.size() << " stops" << RESET << std::endl;
    file.close();
}

void loadTransports() {
    std::ifstream file("transports.txt");
    if (!file.is_open()) {
        std::cout << GRAY << "ℹ No transports.txt found, starting with empty data" << RESET << std::endl;
        return;
    }

    transports.clear();
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        if (pos != std::string::npos) {
            Transport transport;
            transport.id = std::stoi(line.substr(0, pos));
            transport.name = line.substr(pos + 1);
            transports.push_back(transport);
        }
    }

    std::cout << LIGHT_BLUE << "✓ Loaded " << transports.size() << " transports" << RESET << std::endl;
    file.close();
}

void loadRoutes() {
    std::ifstream file("routes.txt");
    if (!file.is_open()) {
        std::cout << GRAY << "ℹ No routes.txt found, starting with empty data" << RESET << std::endl;
        return;
    }

    routes.clear();
    std::string line;
    while (std::getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        size_t pos3 = line.find('|', pos2 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos) {
            Route route;
            route.id = std::stoi(line.substr(0, pos1));
            route.name = line.substr(pos1 + 1, pos2 - pos1 - 1);
            route.transportId = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));

            std::string stopIdsStr = line.substr(pos3 + 1);
            if (!stopIdsStr.empty()) {
                size_t start = 0;
                size_t comma = stopIdsStr.find(',');
                while (comma != std::string::npos) {
                    route.stopIds.push_back(std::stoi(stopIdsStr.substr(start, comma - start)));
                    start = comma + 1;
                    comma = stopIdsStr.find(',', start);
                }
                route.stopIds.push_back(std::stoi(stopIdsStr.substr(start)));
            }

            routes.push_back(route);
        }
    }

    std::cout << LIGHT_PURPLE << "✓ Loaded " << routes.size() << " routes" << RESET << std::endl;
    file.close();
}

void loadSchedules() {
    std::ifstream file("schedules.txt");
    if (!file.is_open()) {
        std::cout << GRAY << "ℹ No schedules.txt found, starting with empty data" << RESET << std::endl;
        return;
    }

    schedules.clear();
    std::string line;
    while (std::getline(file, line)) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);

        if (pos1 != std::string::npos && pos2 != std::string::npos) {  // ✅ ВИПРАВЛЕНО
            Schedule schedule;
            schedule.id = std::stoi(line.substr(0, pos1));
            schedule.routeId = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
            schedule.time = line.substr(pos2 + 1);  // ✅ ВИПРАВЛЕНО
            schedules.push_back(schedule);
        }
    }

    std::cout << LIGHT_YELLOW << "✓ Loaded " << schedules.size() << " schedules" << RESET << std::endl;
    file.close();
}
