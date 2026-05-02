#pragma once
#include <memory>
#include "IUserRepository.h"
#include "ILogger.h"

class UserService {
    std::shared_ptr<IUserRepository> repo;
    std::shared_ptr<ILogger> logger;

public:
    UserService(std::shared_ptr<IUserRepository> r,
                std::shared_ptr<ILogger> l);

    void createUser();
    void showUsers();
    void deposit();
    void withdraw();
    void deleteUser();
};