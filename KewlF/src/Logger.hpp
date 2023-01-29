#pragma once

#include <iostream>
#include <ostream>
#include <fstream>
#include "String.hpp"

// Severity level enum.
enum LogLevel {
    FATAL = 0,
    ERROR = 1,
    WARNING = 2,
    INFO = 3,
    DEBUG = 4,
    TRACE = 5,
    ASIS = 6 
};

class Logger {
private:
#if defined KEWLF_DEBUG
    bool dynamic = false;
    std::ostream* m_log = &std::cout;
#else
    bool dynamic = true;
    //    std::ostream& m_log = static_cast<std::ostream&>(std::ofstream("/dev/null"));
//    std::ostream& m_log = std::ofstream("/dev/null");
    std::ostream* m_log = new std::ofstream("/dev/null");
#endif

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    Logger() {};
    ~Logger() {
        if (dynamic) delete m_log;
    }
public:

    std::ostream& log(LogLevel logLevel, String file, int line);

    //std::ostream& operator <<(const auto& data);
    std::ostream& operator <<(const auto& data) {
        if (!dynamic) {
            *m_log << data;
        }
        return *m_log;
    }
    static inline Logger& getInstance() {
        static Logger log;
        return log;
    };

};

//#define LOG(x) Logger::getInstance() << #x  << ": " << __FILE__ << "(" <<  __LINE__ << "): " 
//#if defined KEWLF_DEBUG
#define LOG(x) Logger::getInstance().log(x,  __FILE__, __LINE__) 
//#ifdef KEWLF_DEBUG
//#define LOG(x) Logger::getInstance().log(x,  __FILE__, __LINE__) 
//#else
//#define LOG(x) Logger::getInstance()
//#endif