#include <iostream>
#include <vector>
#include "stop.h"
#include "stop_manager.h"
#include "colors.h"

extern std::vector<Stop> stops;
int generateStopId();

void listStops() {
    if (stops.empty()) {
        std::cout << GRAY << "ℹ No stops available." << RESET << std::endl;
        return;
    }

    std::cout << PEACH << "\n=== All Stops ===" << RESET << std::endl;
    for (const auto& s : stops) {
        std::cout << MINT << "ID: " << RESET << s.id
                  << PEACH << ", Name: " << RESET << s.name
                  << LAVENDER << ", Location: " << RESET << s.location << std::endl;
    }
}

void addStop() {
    std::string name, location;
    std::cout << WHITE << "Enter stop name: " << RESET;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << WHITE << "Enter stop location: " << RESET;
    std::getline(std::cin, location);
    int id = generateStopId();
    stops.push_back({id, name, location});
    std::cout << GREEN << "✓ Stop added successfully." << RESET << std::endl;
}

void manageStops() {
    int choice;
    while (true) {
        std::cout << PEACH << "\n=== Manage Stops ===" << RESET << std::endl;
        std::cout << PEACH << "1. List stops" << std::endl;
        std::cout << "2. Add stop" << RESET << std::endl;
        std::cout << GRAY << "0. Back" << RESET << std::endl;
        std::cout << "Select: ";

        std::cin >> choice;
        switch (choice) {
            case 1: listStops(); break;
            case 2: addStop(); break;
            case 0: return;
            default: std::cout << ORANGE << "Invalid option." << RESET << std::endl; break;
        }
    }
}