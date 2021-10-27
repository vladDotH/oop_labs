#ifndef LOG_H
#define LOG_H

#include <string>
#include <chrono>
#include "Level.h"

struct Log {
    Level lvl;
    std::chrono::time_point<std::chrono::steady_clock> stamp;
    std::string msg;

    Log(Level lvl, std::string msg) : lvl(lvl), msg(msg), stamp(std::chrono::steady_clock::now()) {
        if (lvl.value <= Level::OFF || lvl.value >= Level::ALL)
            throw std::invalid_argument("bad log level");
    }
};

#define error(msg) Log(Level::ERROR, msg)
#define warn(msg) Log(Level::WARN, msg)
#define info(msg) Log(Level::INFO, msg)
#define debug(msg) Log(Level::DEBUG, msg)


#endif //LOG_H
