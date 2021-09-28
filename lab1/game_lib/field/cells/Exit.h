#ifndef EXIT_H
#define EXIT_H

#include "Cell.h"

class Exit : public Cell {
public:
    CELLS_ID getID() const override {
        return EXIT;
    }

    AbstractCell *copy() override {
        return new Exit;
    }
};


#endif //EXIT_H
