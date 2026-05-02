#include "UserService.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>

UserService::UserService(std::shared_ptr<IUserRepository> r,
                         std::shared_ptr<ILogger> l)
    : repo(r), logger(l) {}

void UserService::createUser() {
    std::string name, surname;
    double balance;

    std::cout << "Name: ";    std::cin >> name;
    std::cout << "Surname: "; std::cin >> surname;
    std::cout << "Balance: "; std::cin >> balance;

    std::string id = std::to_string(rand() % 1000000);

    User u;
    u.setData(id, name, surname, balance);

    repo->addUser(u);
    logger->log("User created: " + id + " " + name + " " + surname);

    std::cout << "Created user with ID: " << id << std::endl;
}

void UserService::showUsers() {
    auto users = repo->getAllUsers();

    if (users.empty()) {
        std::cout << "No users found.\n";
        return;
    }

    std::cout << "\n"
              << std::left
              << std::setw(10) << "ID"
              << std::setw(15) << "Name"
              << std::setw(15) << "Surname"
              << std::setw(10) << "Balance"
              << "\n";

    std::cout << std::string(50, '-') << "\n";

    for (auto& u : users) {
        std::cout << std::left
                  << std::setw(10) << u.getId()
                  << std::setw(15) << u.getName()
                  << std::setw(15) << u.getSurname()
                  << std::fixed << std::setprecision(2)
                  << u.getBalance()
                  << "\n";
    }
}

void UserService::deposit() {
    std::string id;
    double amount;

    std::cout << "ID: ";     std::cin >> id;
    std::cout << "Amount: "; std::cin >> amount;

    auto users = repo->getAllUsers();
    bool found = false;

    for (auto& u : users) {
        if (u.getId() == id) {
            u.deposit(amount);
            repo->updateUser(u);
            logger->log("Deposit " + std::to_string(amount) + " to " + id);
            std::cout << "New balance: " << u.getBalance() << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        std::cout << "User not found.\n";
}

void UserService::withdraw() {
    std::string id;
    double amount;

    std::cout << "ID: ";     std::cin >> id;
    std::cout << "Amount: "; std::cin >> amount;

    auto users = repo->getAllUsers();
    bool found = false;

    for (auto& u : users) {
        if (u.getId() == id) {
            if (amount > u.getBalance()) {
                std::cout << "Insufficient funds.\n";
            } else {
                u.withdraw(amount);
                repo->updateUser(u);
                logger->log("Withdraw " + std::to_string(amount) + " from " + id);
                std::cout << "New balance: " << u.getBalance() << "\n";
            }
            found = true;
            break;
        }
    }

    if (!found)
        std::cout << "User not found.\n";
}

void UserService::deleteUser() {
    std::string id;
    std::cout << "ID: "; std::cin >> id;

    repo->deleteUser(id);
    logger->log("Deleted user: " + id);
    std::cout << "User " << id << " deleted.\n";
}