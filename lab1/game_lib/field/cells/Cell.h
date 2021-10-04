#ifndef CELL_H
#define CELL_H

#include "AbstractCell.h"

class Cell : public AbstractCell {
public:
    virtual bool putEntity(Entity *entity) override {
        if (!interact(entity)){
            this->entity = entity;
            return true;
        }
        return false;
    }

    virtual bool interact(Entity *entity) override {
        if (this->entity) {
            entity->interact(this->entity);
            this->entity->interact(entity);
            return true;
        }
        return false;
    }

    AbstractCell *copy() override {
        return new Cell;
    }
};


#endif //CELL_H
