#include "file_io.h"
#include "stop.h"
#include "transport.h"
#include "route.h"
#include "schedule.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

extern std::vector<Stop> stops;
extern std::vector<Transport> transports;
extern std::vector<Route> routes;
extern std::vector<Schedule> schedules;


void saveStopsToFile(const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& stop : stops) {
        out << stop.id << ';' << stop.name << ';' << stop.location << '\n';
    }

    std::cout << "Stops saved to " << filename << "\n";
}

void loadStopsFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "No file " << filename << " found to load.\n";
        return;
    }

    stops.clear();
    std::string line;
    while (std::getline(in, line)) {
        size_t p1 = line.find(';');
        size_t p2 = line.find(';', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        Stop stop;
        stop.id = std::stoi(line.substr(0, p1));
        stop.name = line.substr(p1 + 1, p2 - p1 - 1);
        stop.location = line.substr(p2 + 1);

        stops.push_back(stop);
    }

    std::cout << "Stops loaded from " << filename << "\n";
}


void saveTransportsToFile(const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& t : transports) {
        out << t.id << ';' << t.name << '\n';
    }

    std::cout << "Transports saved to " << filename << "\n";
}

void loadTransportsFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "No file " << filename << " found to load.\n";
        return;
    }

    transports.clear();
    std::string line;
    while (std::getline(in, line)) {
        size_t sep = line.find(';');
        if (sep == std::string::npos) continue;

        Transport t;
        t.id = std::stoi(line.substr(0, sep));
        t.name = line.substr(sep + 1);

        transports.push_back(t);
    }

    std::cout << "Transports loaded from " << filename << "\n";
}


void saveRoutesToFile(const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& r : routes) {
        out << r.id << ';' << r.name << ';' << r.transportId << ';';
        for (size_t i = 0; i < r.stopIds.size(); ++i) {
            out << r.stopIds[i];
            if (i + 1 < r.stopIds.size()) out << ',';
        }
        out << '\n';
    }

    std::cout << "Routes saved to " << filename << "\n";
}

void loadRoutesFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "No file " << filename << " found to load.\n";
        return;
    }

    routes.clear();
    std::string line;
    while (std::getline(in, line)) {
        size_t p1 = line.find(';');
        size_t p2 = line.find(';', p1 + 1);
        size_t p3 = line.find(';', p2 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos || p3 == std::string::npos) continue;

        Route r;
        r.id = std::stoi(line.substr(0, p1));
        r.name = line.substr(p1 + 1, p2 - p1 - 1);
        r.transportId = std::stoi(line.substr(p2 + 1, p3 - p2 - 1));

        std::string stopsStr = line.substr(p3 + 1);
        r.stopIds.clear();
        size_t pos = 0;
        while ((pos = stopsStr.find(',')) != std::string::npos) {
            r.stopIds.push_back(std::stoi(stopsStr.substr(0, pos)));
            stopsStr.erase(0, pos + 1);
        }
        if (!stopsStr.empty()) {
            r.stopIds.push_back(std::stoi(stopsStr));
        }

        routes.push_back(r);
    }

    std::cout << "Routes loaded from " << filename << "\n";
}


void saveSchedulesToFile(const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Failed to open " << filename << " for writing.\n";
        return;
    }

    for (const auto& s : schedules) {
        out << s.id << ';' << s.routeId << ';' << s.time << '\n';
    }

    std::cout << "Schedules saved to " << filename << "\n";
}

void loadSchedulesFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "No file " << filename << " found to load.\n";
        return;
    }

    schedules.clear();
    std::string line;
    while (std::getline(in, line)) {
        size_t p1 = line.find(';');
        size_t p2 = line.find(';', p1 + 1);
        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        Schedule s;
        s.id = std::stoi(line.substr(0, p1));
        s.routeId = std::stoi(line.substr(p1 + 1, p2 - p1 - 1));
        s.time = line.substr(p2 + 1);

        schedules.push_back(s);
    }

    std::cout << "Schedules loaded from " << filename << "\n";
}


void saveAllData() {
    saveStopsToFile("stops.txt");
    saveTransportsToFile("transports.txt");
    saveRoutesToFile("routes.txt");
    saveSchedulesToFile("schedules.txt");
}

void loadAllData() {
    loadStopsFromFile("stops.txt");
    loadTransportsFromFile("transports.txt");
    loadRoutesFromFile("routes.txt");
    loadSchedulesFromFile("schedules.txt");
}
