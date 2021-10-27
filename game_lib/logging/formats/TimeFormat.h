#ifndef TIMEFORMAT_H
#define TIMEFORMAT_H

#include "Format.h"
#include "../LogTimer.h"
#include <chrono>

class TimeFormat : public Format {
    std::chrono::time_point<std::chrono::steady_clock> stamp;
public:
    TimeFormat(std::chrono::time_point<std::chrono::steady_clock> start = LogTimer::get()) : stamp(start) {}

    Log wrap(Log l) override {
        return Log(l.lvl, "[" + std::to_string(
                std::chrono::duration_cast<std::chrono::milliseconds>(l.stamp - LogTimer::get()).count()) + "ms]"
                          + l.msg);
    }
};

#endif //TIMEFORMAT_H
