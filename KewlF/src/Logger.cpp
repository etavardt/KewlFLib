#include "Logger.hpp"

#include "String.hpp"

// TODO: Add timestamp and logging to a file and some formatting?
std::ostream& Logger::log(LogLevel logLevel, String file, int line) {
    static const String loggerLevel[] = {
        "Fatal: ",
        "Error: ",
        "Warning: ",
        "Info: ",
        "Debug: ",
        "Trace: ",
        "" // May use an indicator in the future
    };
    
    switch (logLevel) {
    case ASIS:
        *m_log << loggerLevel[logLevel];
        break;
    default:
        *m_log << loggerLevel[logLevel] << file << "(" << line << "): ";
        break;
    }

    return *m_log;
}
//std::ostream& Logger::operator <<(const auto& data) {
//#if defined KEWLF_DEBUG
//    * m_log << data;
//#endif
//    return *m_log;
//}
