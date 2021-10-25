#ifndef LOG_H
#define LOG_H

#include <string>
#include <ctime>
#include "Level.h"

struct Log {
public:
    Level lvl;
    std::time_t stamp;
    std::string msg;

    Log(Level lvl, std::string msg) : lvl(lvl), msg(msg), stamp(std::time(nullptr)) {
        if (lvl.value <= Level::OFF || lvl.value >= Level::ALL)
            throw std::invalid_argument("bad log level");
    }
};

Log error(std::string msg) {
    return Log(Level::ERROR, msg);
}

Log warn(std::string msg) {
    return Log(Level::WARN, msg);
}

Log info(std::string msg) {
    return Log(Level::INFO, msg);
}

Log debug(std::string msg) {
    return Log(Level::DEBUG, msg);
}


#endif //LOG_H
