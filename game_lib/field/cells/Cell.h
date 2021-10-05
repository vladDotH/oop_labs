#ifndef CELL_H
#define CELL_H

#include "AbstractCell.h"

class Cell : public AbstractCell {
public:
    virtual bool putEntity(std::weak_ptr<Entity> entity) override {
        if (!interact(entity.lock())){
            this->entity = entity;
            return true;
        }
        return false;
    }

    virtual bool interact(std::weak_ptr<Entity> entity) override {
        if (this->entity.lock()) {
            entity.lock()->interact(this->entity.lock());
            this->entity.lock()->interact(entity.lock());
            return true;
        }
        return false;
    }

    AbstractCell *copy() override {
        return new Cell;
    }
};


#endif //CELL_H
