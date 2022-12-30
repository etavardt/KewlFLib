#pragma once

#include <iostream>
#include <ostream>
#include "String.hpp"

// Severity level enum.
enum Level {
    FATAL = 0,
    ERROR = 1,
    WARNING = 2,
    INFO = 3,
    DEBUG = 4,
    TRACE = 5
};

//String loggerLevel[] = {
//        "Fatal",
//        "Error",
//        "Warning",
//        "Info",
//        "Debug",
//        "Trace"
//};

class Logger {
private:
    static std::ostream& m_Log;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    Logger() {};

    std::ostream& operator <<(const auto& data) {
        m_Log << data;
        return m_Log;
    }

    static Logger& getInstance() { static Logger log; return log; };

};

#define LOG(x) Logger::getInstance() << #x  << ": "