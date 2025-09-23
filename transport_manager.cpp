#include "transport.h"
#include "colors.h"
#include <iostream>
#include <string>

void manageTransports() {
    while (true) {
        std::cout << "\n=== Manage Transports ===\n";
        std::cout << LIGHT_BLUE << "1. Add Transport\n";
        std::cout << "2. List Transports\n";
        std::cout << "3. Update Transport\n";
        std::cout << "4. Delete Transport\n" << RESET;
        std::cout << GRAY << "0. Back\n" << RESET;
        std::cout << "Choose option: ";

        int option;
        std::cin >> option;
        std::cin.ignore();

        if (option == 0) break;

        switch (option) {
            case 1: {
                std::cout << "Enter transport name: " << RESET;
                std::string name;
                std::getline(std::cin, name);
                createTransport(name);
                std::cout << GREEN << "Added transport.\n" << RESET;
                break;
            }
            case 2: {
                for (const auto& t : transports) {
                    std::cout << "ID: " << t.id << ", Name: " << t.name << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter transport ID to update: ";
                int id; std::cin >> id; std::cin.ignore();
                Transport* t = getTransportById(id);
                if (t) {
                    std::cout << "Enter new name: ";
                    std::string newName;
                    std::getline(std::cin, newName);
                    updateTransport(id, newName);
                    std::cout << GREEN << "Updated transport.\n" << RESET;
                } else {
                    std::cout << RED << "Transport not found.\n" << RESET;
                }
                break;
            }
            case 4: {
                std::cout << "Enter transport ID to delete: ";
                int id; std::cin >> id; std::cin.ignore();
                deleteTransport(id);
                std::cout << "Deleted transport if existed.\n";
                break;
            }
            default:
                std::cout << RED << "Invalid option.\n" << RESET;
        }
    }
}
