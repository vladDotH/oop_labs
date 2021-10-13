#ifndef CELL_H
#define CELL_H

#include "AbstractCell.h"

class Cell : public AbstractCell {
public:
    virtual bool putEntity(std::weak_ptr<Entity> entity) override {
        if (!this->entity.expired()) {
            if (!entity.lock()->interact(this->entity.lock()))
                return true;

            if (!this->entity.lock()->interact(entity.lock())) {
                this->entity = entity;
                return true;
            }

            return false;
        } else {
            this->entity = entity;
            return true;
        }
    }


    std::unique_ptr<AbstractCell> clone() override {
        return std::make_unique<Cell>();
    }
};


#endif //CELL_H
