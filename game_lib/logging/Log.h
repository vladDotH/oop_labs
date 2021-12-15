#ifndef LOG_H
#define LOG_H

#include <string>
#include <chrono>
#include "LogLevel.h"

struct Log {
    LogLevel lvl;
    std::chrono::time_point<std::chrono::steady_clock> stamp;
    std::string msg;

    Log(LogLevel lvl, std::string msg) : lvl(lvl), msg(msg), stamp(std::chrono::steady_clock::now()) {
        if (lvl.value <= LogLevel::OFF || lvl.value >= LogLevel::ALL)
            throw std::invalid_argument("bad log level");
    }
};

#define logErr(msg) Log(LogLevel::ERROR, msg)
#define logWarn(msg) Log(LogLevel::WARN, msg)
#define logInfo(msg) Log(LogLevel::INFO, msg)
#define logDebug(msg) Log(LogLevel::DEBUG, msg)


#endif //LOG_H
