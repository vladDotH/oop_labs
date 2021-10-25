#ifndef LOGGER_H
#define LOGGER_H

#include "Log.h"

class Logger {
protected:
    Level lvl;

    virtual void log(Log l) = 0;

public:
    Logger(Level lvl = Level::ALL) : lvl(lvl) {}

    void setLvl(Level lvl) {
        Logger::lvl = lvl;
    }

    Logger &operator<<(Log l) {
        if (l.lvl.value <= lvl.value) {
            log(l);
        }
        return *this;
    }

    virtual ~Logger() = default;
};


#endif //LOGGER_H
