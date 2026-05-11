cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 17)
find_package(SQLite3 REQUIRED)
add_executable(banking_app 
    main.cpp 
    FileLogger.cpp 
    SQLiteUserRepository.cpp 
    User.cpp
)
target_link_libraries(banking_app SQLite3::SQLite3)
