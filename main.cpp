#include <iostream>
#include "Container.h"
#include "UserService.h"
#include "SQLiteUserRepository.h"
#include "FileLogger.h"

int main() {
    Container c;

    c.registerService<IUserRepository>("repo", []() {
        return std::make_shared<SQLiteUserRepository>();
    });

    c.registerService<ILogger>("logger", []() {
        return std::make_shared<FileLogger>();
    });

    auto repo = c.resolve<IUserRepository>("repo");
    auto logger = c.resolve<ILogger>("logger");

    UserService service(repo, logger);

    int ch;

    do {
        std::cout ;
        "\n1 Create"
        "\n2 Show"
        "\n3 Deposit"
        "\n4 Withdraw"
        "\n5 Delete"
        "\n0 Exit\n";

        std::cin >> ch;

        if (ch == 1) service.createUser();
        if (ch == 2) service.showUsers();
        if (ch == 3) service.deposit();
        if (ch == 4) service.withdraw();
        if (ch == 5) service.deleteUser();

    } while (ch != 0);
}