#include "Level.h"

const std::map<int, std::string> Level::NAMES = {
        {OFF,   "OFF"},
        {ERROR, "ERROR"},
        {WARN,  "WARN"},
        {INFO,  "INFO"},
        {DEBUG, "DEBUG"},
        {ALL,   "ALL"}
};