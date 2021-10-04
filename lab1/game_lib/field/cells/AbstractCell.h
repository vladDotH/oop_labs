#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include "../../entities/Entity.h"

class AbstractCell {
protected:
    std::weak_ptr<Entity> entity;

public:
    AbstractCell() = default;

    virtual bool putEntity(std::weak_ptr<Entity> entity) = 0;

    virtual bool interact(std::weak_ptr<Entity> entity) = 0;

    virtual AbstractCell *copy() = 0;

    virtual std::weak_ptr<Entity> getEntity() {
        return entity;
    }

    virtual ~AbstractCell() = default;
};

#endif //ABSTRACTCELL_H
