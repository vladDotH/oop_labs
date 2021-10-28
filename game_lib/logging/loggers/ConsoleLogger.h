#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Logger.h"
#include <iostream>

class ConsoleLogger : public Logger {
private:
    std::ostream &os;

public:
    ConsoleLogger(std::ostream &os = std::cout, Level lvl = Level::ALL,
                  std::shared_ptr<Format> fmt = std::make_shared<EmptyFormat>()) : os(os), Logger(lvl, fmt) {}

protected:
    void log(Log l) override {
        std::cout << l.msg << std::endl;
    }
};


#endif //CONSOLELOGGER_H
