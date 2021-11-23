#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Logger.h"
#include <iostream>

class ConsoleLogger : public Logger {
private:
    std::ostream &os;

public:
    ConsoleLogger(std::ostream &os = std::cout, LogLevel lvl = LogLevel::ALL,
                  std::shared_ptr<Format> fmt = std::make_shared<EmptyFormat>()) : os(os), Logger(lvl, fmt) {}

protected:
    void log(Log l) override {
        os << l.msg << std::endl;
    }
};


#endif //CONSOLELOGGER_H
