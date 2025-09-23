#include "route.h"
#include "transport.h"
#include "colors.h"
#include <iostream>
#include <string>
#include <sstream>

void manageRoutes() {
    while (true) {
        std::cout << "\n=== Manage Routes ===\n";
        std::cout << LAVENDER << "1. Add Route\n";
        std::cout << "2. List Routes\n";
        std::cout << "3. Update Route\n";
        std::cout << "4. Delete Route\n" << RESET;
        std::cout << GRAY << "0. Back\n" << RESET;
        std::cout << "Choose option: ";

        int option;
        std::cin >> option;
        std::cin.ignore();

        if (option == 0) break;

        switch (option) {
            case 1: {
                std::string name;
                int transportId;
                std::vector<int> stopIds;

                std::cout << "Enter route name: ";
                std::getline(std::cin, name);

                std::cout << "Enter transport ID: ";
                std::cin >> transportId;
                std::cin.ignore();

                std::cout << "Enter stop IDs separated by space: ";
                std::string line;
                std::getline(std::cin, line);
                std::istringstream iss(line);
                int stopId;
                while (iss >> stopId) {
                    stopIds.push_back(stopId);
                }

                createRoute(name, transportId, stopIds);
                std::cout << GREEN << "Route added.\n" << RESET;
                break;
            }
            case 2: {
                for (const auto& r : routes) {
                    std::cout << "ID: " << r.id << ", Name: " << r.name << ", TransportID: " << r.transportId << ", Stops: ";
                    for (int sid : r.stopIds) std::cout << sid << ' ';
                    std::cout << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter route ID to update: ";
                int id; std::cin >> id; std::cin.ignore();

                Route* r = getRouteById(id);
                if (!r) {
                    std::cout << ORANGE << "Route not found.\n";
                    break;
                }

                std::string newName;
                int newTransportId;
                std::vector<int> newStopIds;

                std::cout << "Enter new route name: ";
                std::getline(std::cin, newName);

                std::cout << "Enter new transport ID: ";
                std::cin >> newTransportId;
                std::cin.ignore();

                std::cout << "Enter new stop IDs separated by space: ";
                std::string stopsLine;
                std::getline(std::cin, stopsLine);
                std::istringstream iss(stopsLine);
                int sid;
                while (iss >> sid) newStopIds.push_back(sid);

                updateRoute(id, newName, newTransportId, newStopIds);
                std::cout << LIGHT_GREEN << "Route updated.\n" << RESET;
                break;
            }
            case 4: {
                std::cout << "Enter route ID to delete: ";
                int id; std::cin >> id; std::cin.ignore();

                deleteRoute(id);
                std::cout << "Route deleted if existed.\n";
                break;
            }
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
        }
    }
}
