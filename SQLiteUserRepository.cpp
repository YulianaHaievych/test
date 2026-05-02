#include "SQLiteUserRepository.h"
#include <iostream>

SQLiteUserRepository::SQLiteUserRepository() {
    sqlite3_open("users.db", &db);

    std::string sql =
        "CREATE TABLE IF NOT EXISTS users("
        "id TEXT,"
        "name TEXT,"
        "surname TEXT,"
        "balance REAL);";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

void SQLiteUserRepository::addUser(const User& user) {
    std::string sql =
        "INSERT INTO users VALUES('" +
        user.getId() + "','" +
        user.getName() + "','" +
        user.getSurname() + "'," +
        std::to_string(user.getBalance()) + ");";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

std::vector<User> SQLiteUserRepository::getAllUsers() {
    std::vector<User> users;

    std::string sql = "SELECT * FROM users;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            User u;
            u.setData(
                (const char*)sqlite3_column_text(stmt, 0),
                (const char*)sqlite3_column_text(stmt, 1),
                (const char*)sqlite3_column_text(stmt, 2),
                sqlite3_column_double(stmt, 3)
            );
            users.push_back(u);
        }
        sqlite3_finalize(stmt);
    }

    return users;
}

void SQLiteUserRepository::updateUser(const User& user) {
    std::string sql =
        "UPDATE users SET balance=" +
        std::to_string(user.getBalance()) +
        " WHERE id='" + user.getId() + "';";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

void SQLiteUserRepository::deleteUser(const std::string& id) {
    std::string sql =
        "DELETE FROM users WHERE id='" + id + "';";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

SQLiteUserRepository::~SQLiteUserRepository() {
    sqlite3_close(db);
}