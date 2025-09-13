#include <iostream>
#include "colors.h"
#include "menu.h"
#include "stop_manager.h"
#include "transport_manager.h"
#include "route_manager.h"
#include "schedule_manager.h"
#include "file_io.h"
#include "reports.h"

void showMainMenu() {
    std::cout << MINT << "\n====== Transport System ======\n" << RESET;
    std::cout << PEACH <<"1. Manage Stops\n";
    std::cout << "2. Manage Transports\n";
    std::cout << "3. Manage Routes\n";
    std::cout << "4. Manage Schedules\n" << RESET;
    std::cout << LAVENDER << "5. Reports\n" << RESET;
    std::cout << GREEN << "6. Save Data\n" << RESET;
    std::cout << BLUE << "7. Load Data\n" << RESET;
    std::cout << GRAY << "0. Exit\n" << RESET;
    std::cout << "==============================\n";
    std::cout << WHITE << "Enter choice: " << RESET;
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
            default: std::cout << RED << "Invalid choice. Try again.\n" << RESET; break;
        }
    }
}
