#ifndef LOGLEVEL_H
#define LOGLEVEL_H

#include <map>

struct LogLevel {
    enum _LogLevel_ {
        OFF,
        ERROR,
        WARN,
        INFO,
        DEBUG,
        ALL
    } value;

    std::string toString() {
        return NAMES.at(value);
    }

    LogLevel(LogLevel::_LogLevel_ value) : value(value) {}

private:
    static const std::map<int, std::string> NAMES;
};


#endif //LOGLEVEL_H
