#ifndef CELL_H
#define CELL_H

#include "AbstractCell.h"

class Cell : public AbstractCell {
public:
    virtual bool putEntity(std::shared_ptr<Entity> entity) override {
        if (this->entity) {
            if (!entity->interact(this->entity)) {
                notify(logDebug("coming object has been destroyed"));
                return true;
            }

            if (!this->entity->interact(entity)) {
                this->entity = entity;
                notify(logDebug("object on cell has been destroyed"));
                return true;
            }

            return false;
        } else {
            notify(logDebug("object has been moved on empty cell"));
            this->entity = entity;
            return true;
        }
    }


    std::unique_ptr<AbstractCell> clone() override {
        return std::make_unique<Cell>();
    }
};


#endif //CELL_H
