#pragma once
#include <vector>
#include <string>
#include "User.h"

class IUserRepository {
public:
    virtual void addUser(const User& user) = 0;
    virtual std::vector<User> getAllUsers() = 0;
    virtual void updateUser(const User& user) = 0;
    virtual void deleteUser(const std::string& id) = 0;
    virtual ~IUserRepository() {}
};