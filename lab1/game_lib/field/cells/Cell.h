#ifndef CELL_H
#define CELL_H

#include "AbstractCell.h"

class Cell : public AbstractCell {
public:
    virtual CELLS_ID getID() const override {
        return CELL;
    }

    virtual bool putEntity(std::shared_ptr<Entity> entity) override {
        if (!interact(entity)){
            this->entity = entity;
            return true;
        }
        return false;
    }

    virtual bool interact(std::shared_ptr<Entity> entity) override {
        if (this->entity.lock()) {
            entity->interact(this->entity.lock());
            this->entity.lock()->interact(entity);
            return true;
        }
        return false;
    }

    AbstractCell *copy() override {
        return new Cell;
    }
};


#endif //CELL_H
