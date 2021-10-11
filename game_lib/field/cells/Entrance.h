#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "Cell.h"

class Entrance : public Cell {
public:
    std::unique_ptr<AbstractCell> clone() override {
        return std::make_unique<Entrance>();
    }
};


#endif //ENTRANCE_H
