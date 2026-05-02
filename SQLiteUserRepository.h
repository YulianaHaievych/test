#pragma once
#include "IUserRepository.h"
#include <sqlite3.h>

class SQLiteUserRepository : public IUserRepository {
private:
    sqlite3* db;

public:
    SQLiteUserRepository();

    void addUser(const User& user) override;
    std::vector<User> getAllUsers() override;
    void updateUser(const User& user) override;
    void deleteUser(const std::string& id) override;

    ~SQLiteUserRepository();
};