#ifndef WALL_H
#define WALL_H

#include "AbstractCell.h"

class Wall : public AbstractCell {
public:
    CELLS_ID getID() const override {
        return WALL;
    }

    bool putEntity(Entity *entity) override {
        return false;
    }

    bool interact(Entity *entity) override {
        return false;
    }

    AbstractCell *copy() override {
        return new Wall;
    }
};


#endif //WALL_H
