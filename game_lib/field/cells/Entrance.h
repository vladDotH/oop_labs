#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "Cell.h"

class Entrance : public Cell {
public:
    std::unique_ptr<AbstractCell> copy() override {
        return std::make_unique<Entrance>();
    }
};


#endif //ENTRANCE_H
