#include <iostream>
#include "menu.h"
#include "stop_manager.h"
#include "transport_manager.h"
#include "route_manager.h"
#include "schedule_manager.h"
#include "file_io.h"
#include "reports.h"
#include "colors.h"

void showMainMenu() {
    std::cout << "\n====== Transport System ======\n";
    std::cout << "1. Manage Stops\n";
    std::cout << "2. Manage Transports\n";
    std::cout << "3. Manage Routes\n";
    std::cout << "4. Manage Schedules\n";
    std::cout << "5. Reports\n";
    std::cout << "6. Save Data\n";
    std::cout << "7. Load Data\n";
    std::cout << "0. Exit\n";
    std::cout << "==============================\n";
    std::cout << "Enter choice: ";
}

void handleUserInput() {
    int choice;
    bool running = true;

    while (running) {
        showMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: manageStops(); break;
            case 2: manageTransports(); break;
            case 3: manageRoutes(); break;
            case 4: manageSchedules(); break;
            case 5: showReports(); break;
            case 6: saveAllData(); break;
            case 7: loadAllData(); break;
            case 0: running = false; break;
            default: std::cout << "Invalid choice. Try again.\n"; break;
        }
    }
}
