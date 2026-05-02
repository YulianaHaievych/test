#pragma once
#include <string>

class User {
    std::string id;
    std::string name;
    std::string surname;
    double balance;

public:
    User();

    void setData(std::string i, std::string n, std::string s, double b);

    std::string getId() const;
    std::string getName() const;
    std::string getSurname() const;
    double getBalance() const;

    void deposit(double amount);
    void withdraw(double amount);
};