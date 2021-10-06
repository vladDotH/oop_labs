#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include "../../entities/Entity.h"
#include "memory"

class AbstractCell {
protected:
    std::weak_ptr<Entity> entity;

public:
    std::weak_ptr<Entity> getEntity() {
        return entity;
    }

    bool moveTo(AbstractCell &cell) {
        if (!entity.expired() && cell.putEntity(entity.lock())) {
            entity.reset();
            return true;
        }
        return false;
    }

    virtual bool putEntity(std::weak_ptr<Entity> entity) = 0;

    virtual std::unique_ptr<AbstractCell> copy() = 0;

    virtual ~AbstractCell() = default;
};

#endif //ABSTRACTCELL_H
