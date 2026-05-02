#include "FileLogger.h"
#include <fstream>

void FileLogger::log(const std::string& msg) {
    std::ofstream file("log.txt", std::ios::app);
    file << msg << std::endl;
}