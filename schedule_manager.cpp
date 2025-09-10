#include "schedule.h"
#include "route.h"   // Для перевірок, якщо потрібно
#include <iostream>
#include <string>

void manageSchedules() {
    while (true) {
        std::cout << "\n=== Manage Schedules ===\n";
        std::cout << "1. Add Schedule\n";
        std::cout << "2. List Schedules\n";
        std::cout << "3. Update Schedule\n";
        std::cout << "4. Delete Schedule\n";
        std::cout << "0. Back\n";
        std::cout << "Choose option: ";

        int option;
        std::cin >> option;
        std::cin.ignore();

        if (option == 0) break;

        switch (option) {
            case 1: {
                int routeId;
                std::string time;

                std::cout << "Enter route ID: ";
                std::cin >> routeId;
                std::cin.ignore();

                std::cout << "Enter time (e.g., 08:30): ";
                std::getline(std::cin, time);

                createSchedule(routeId, time);
                std::cout << "Schedule added.\n";
                break;
            }
            case 2: {
                for (const auto& s : schedules) {
                    std::cout << "ID: " << s.id << ", RouteID: " << s.routeId << ", Time: " << s.time << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter schedule ID to update: ";
                int id; std::cin >> id; std::cin.ignore();

                Schedule* s = getScheduleById(id);
                if (!s) {
                    std::cout << "Schedule not found.\n";
                    break;
                }

                int newRouteId;
                std::string newTime;

                std::cout << "Enter new route ID: ";
                std::cin >> newRouteId;
                std::cin.ignore();

                std::cout << "Enter new time: ";
                std::getline(std::cin, newTime);

                updateSchedule(id, newRouteId, newTime);
                std::cout << "Schedule updated.\n";
                break;
            }
            case 4: {
                std::cout << "Enter schedule ID to delete: ";
                int id; std::cin >> id; std::cin.ignore();

                deleteSchedule(id);
                std::cout << "Schedule deleted if existed.\n";
                break;
            }
            default:
                std::cout << "Invalid option.\n";
        }
    }
}
