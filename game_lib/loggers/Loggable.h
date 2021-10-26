#ifndef LOGGABLE_H
#define LOGGABLE_H

#include "Logger.h"
#include <set>
#include <memory>
#include <algorithm>

class Loggable : private std::set<std::shared_ptr<Logger>> {
public:
    bool addLogger(std::shared_ptr<Logger> logger) {
        return insert(logger).second;
    }

    bool removeLogger(std::shared_ptr<Logger> logger) {
        return erase(logger) > 0;
    }

protected:
    void notify(Log log) {
        for (std::shared_ptr<Logger> i: *this) {
            *(i) << log;
        }
    }
};


#endif //LOGGABLE_H
