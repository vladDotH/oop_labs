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
        return NAMES.at(value);
    }

    Level(Level::_Level_ value) : value(value) {}

private:
    static const std::map<int, std::string> NAMES;
};


#endif //LEVEL_H
