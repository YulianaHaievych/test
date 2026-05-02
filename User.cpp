#include "User.h"
#include <cstdlib>

User::User() : balance(0) {}

void User::setData(std::string i, std::string n, std::string s, double b) {
    id = i;
    name = n;
    surname = s;
    balance = b;
}

std::string User::getId() const { return id; }
std::string User::getName() const { return name; }
std::string User::getSurname() const { return surname; }
double User::getBalance() const { return balance; }

void User::deposit(double amount) {
    if (amount > 0)
        balance += amount;
}

void User::withdraw(double amount) {
    if (amount > 0 && amount <= balance)
        balance -= amount;
}