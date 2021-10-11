#ifndef EXIT_H
#define EXIT_H

#include "Cell.h"

class Exit : public Cell {
public:
    std::unique_ptr<AbstractCell> clone() override {
        return std::make_unique<Exit>();
    }
};


#endif //EXIT_H
