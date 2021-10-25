#ifndef LEVEL_H
#define LEVEL_H

#include <map>

struct Level {
    enum _Level_ {
        OFF,
        ERROR,
        WARN,
        INFO,
        DEBUG,
        ALL
    } value;

    std::string toString() {
        return NAMES[value];
    }

    Level(Level::_Level_ value) : value(value) {}

private:
    static std::map<int, std::string> NAMES;
};

std::map<int, std::string> Level::NAMES = {
        {OFF,   "OFF"},
        {ERROR, "ERROR"},
        {WARN,  "WARN"},
        {INFO,  "INFO"},
        {DEBUG, "DEBUG"},
        {ALL,   "ALL"}
};


#endif //LEVEL_H
