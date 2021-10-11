#ifndef WALL_H
#define WALL_H

#include "AbstractCell.h"

class Wall : public AbstractCell {
public:
    bool putEntity(std::weak_ptr<Entity> entity) override {
        return false;
    }

    std::unique_ptr<AbstractCell> clone() override {
        return std::make_unique<Wall>();
    }
};


#endif //WALL_H
