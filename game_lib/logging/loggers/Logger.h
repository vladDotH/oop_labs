#ifndef LOGGER_H
#define LOGGER_H

#include "../Log.h"
#include <memory>
#include "../formats/Format.h"
#include "../formats/EmptyFormat.h"

class Logger {
protected:
    LogLevel lvl;
    std::shared_ptr<Format> fmt;

    virtual void log(Log l) = 0;

public:
    Logger(LogLevel lvl = LogLevel::ALL, std::shared_ptr<Format> fmt = std::make_shared<EmptyFormat>()) : lvl(lvl), fmt(fmt) {}

    void setLvl(LogLevel lvl) {
        this->lvl = lvl;
    }

    void setFmt(const std::shared_ptr<Format> &fmt) {
        Logger::fmt = fmt;
    }

    Logger &operator<<(Log l) {
        if (l.lvl.value <= lvl.value) {
            log(fmt->wrap(l));
        }
        return *this;
    }

    virtual ~Logger() = default;
};


#endif //LOGGER_H
