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
        "Trace: "
    };
    
    *m_log << loggerLevel[logLevel] << file << "(" << line << "): ";
    return *m_log;
}
//std::ostream& Logger::operator <<(const auto& data) {
//#if defined KEWLF_DEBUG
//    * m_log << data;
//#endif
//    return *m_log;
//}
