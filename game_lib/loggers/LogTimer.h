#ifndef LOGTIMER_H
#define LOGTIMER_H

#include "Log.h"

class LogTimer {
private:
    static std::chrono::time_point<std::chrono::steady_clock> start;

public:
    LogTimer() = delete;

    static void reset() {
        start = std::chrono::steady_clock::now();
    }

    static std::chrono::time_point<std::chrono::steady_clock> get() {
        return start;
    }
};


#endif //LOGTIMER_H
