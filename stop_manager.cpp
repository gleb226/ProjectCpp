#include <iostream>
#include <vector>
#include "stop.h"
#include "stop_manager.h"
#include "colors.h"

extern std::vector<Stop> stops;

int generateStopId();

void listStops() {
    if (stops.empty()) {
        std::cout << GRAY << "ℹ No stops available. \n" << RESET;
        return;
    }

    std::cout << PEACH << "\n=== All Stops === \n" << RESET;
    for (const auto &s: stops) {
        std::cout << MINT << "ID: " << RESET << s.id
                << PEACH << ", Name: " << RESET << s.name
                << LAVENDER << ", Location: \n" << RESET << s.location;
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
    std::cout << GREEN << "Stop added successfully. \n" << RESET;
}

void manageStops() {
    int choice;
    while (true) {
        std::cout << "=== Manage Stops === \n";
        std::cout << MINT << "1. List stops \n";
        std::cout << "2. Add stop \n" << RESET;
        std::cout << GRAY << "0. Back \n" << RESET;
        std::cout << "Select: ";

        std::cin >> choice;
        switch (choice) {
            case 1: listStops();
                break;
            case 2: addStop();
                break;
            case 0: return;
            default: std::cout << RED << "Invalid option. \n" << RESET;
                break;
        }
    }
}
