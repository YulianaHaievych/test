#pragma once
#include "ILogger.h"

class FileLogger : public ILogger {
public:
    void log(const std::string& msg) override;
};