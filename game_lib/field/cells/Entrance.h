#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "Cell.h"

class Entrance : public Cell {
public:
    AbstractCell *copy() override {
        return new Entrance;
    }
};


#endif //ENTRANCE_H
