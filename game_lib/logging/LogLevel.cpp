#include "LogLevel.h"

const std::map<int, std::string> LogLevel::NAMES = {
        {OFF,   "OFF"},
        {ERROR, "ERROR"},
        {WARN,  "WARN"},
        {INFO,  "INFO"},
        {DEBUG, "DEBUG"},
        {ALL,   "ALL"}
};