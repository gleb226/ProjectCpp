#include <iostream>
#include <vector>
#include "stop.h"
#include "colors.h"
#include "stop_manager.h"

extern std::vector<Stop> stops;
int generateStopId();

void listStops() {
    if (stops.empty()) {
        std::cout << "No stops available.\n";
        return;
    }
    for (const auto& s : stops) {
        std::cout << "ID: " << s.id << ", Name: " << s.name << ", Location: " << s.location << "\n";
    }
}

void addStop() {
    std::string name, location;
    std::cout << "Enter stop name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter stop location: ";
    std::getline(std::cin, location);
    int id = generateStopId();
    stops.push_back({id, name, location});
    std::cout << GREEN << "Stop added successfully.\n" << RESET;
}

void manageStops() {
    int choice;
    while (true) {
        std::cout << "\n--- Manage Stops ---\n";
        std::cout << "1. List stops\n2. Add stop\n0. Back\nSelect: ";
        std::cin >> choice;
        switch (choice) {
            case 1: listStops(); break;
            case 2: addStop(); break;
            case 0: return;
            default: std::cout << RED << "Invalid option.\n" << RESET; break;
        }
    }
}
