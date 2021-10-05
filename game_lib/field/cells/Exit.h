#ifndef EXIT_H
#define EXIT_H

#include "Cell.h"

class Exit : public Cell {
public:
    AbstractCell *copy() override {
        return new Exit;
    }
};


#endif //EXIT_H
