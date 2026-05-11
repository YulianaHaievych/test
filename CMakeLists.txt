cmake_minimum_required(VERSION 3.10)
project(BankingSystem)

set(CMAKE_CXX_STANDARD 17)

find_package(SQLite3 REQUIRED)

set(SOURCE_FILES
    main.cpp 
    FileLogger.cpp 
    SQLiteUserRepository.cpp 
    User.cpp
)

add_executable(banking_app ${SOURCE_FILES})
target_include_directories(banking_app PRIVATE ${SQLITE3_INCLUDE_DIRS})
target_link_libraries(banking_app ${SQLITE3_LIBRARIES})
