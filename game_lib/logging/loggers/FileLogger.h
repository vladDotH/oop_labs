#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "Logger.h"
#include <fstream>

class FileLogger : public Logger {
private:
    std::ofstream f;

public:
    FileLogger(std::string fName, LogLevel lvl = LogLevel::ALL,
               std::shared_ptr<Format> fmt = std::make_shared<EmptyFormat>()) : Logger(lvl, fmt) {
        f.open(fName);
    }

    ~FileLogger() override {
        f.close();
    }

protected:
    void log(Log l) override {
        f << l.msg << std::endl;
    }
};

#endif //FILELOGGER_H
