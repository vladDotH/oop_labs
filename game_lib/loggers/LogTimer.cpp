#include "LogTimer.h"

std::chrono::time_point<std::chrono::steady_clock> LogTimer::start = std::chrono::steady_clock::now();