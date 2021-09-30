#ifndef WALL_H
#define WALL_H

#include "AbstractCell.h"
#include "memory"

class Wall : public AbstractCell {
public:
    CELLS_ID getID() const override {
        return WALL;
    }

    bool putEntity(std::shared_ptr<Entity> entity) override {
        return false;
    }

    bool interact(std::shared_ptr<Entity> entity) override {
        return false;
    }

    AbstractCell *copy() override {
        return new Wall;
    }
};


#endif //WALL_H
