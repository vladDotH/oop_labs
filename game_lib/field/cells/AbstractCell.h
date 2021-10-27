#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <memory>
#include "../../entities/Entity.h"
#include "../../core/Cloneable.h"
#include "../../loggers/Loggable.h"

class AbstractCell : public Cloneable<std::unique_ptr<AbstractCell>>, public Loggable {
protected:
    std::weak_ptr<Entity> entity;

public:
    std::weak_ptr<Entity> getEntity() {
        return entity;
    }

    bool moveTo(AbstractCell &cell) {
        if (this != &cell && !entity.expired() && cell.putEntity(entity.lock())) {
            entity.reset();
            notify(debug("object has been moved from cell"));
            return true;
        }
        notify(debug("object has not been moved from cell"));
        return false;
    }

    virtual bool putEntity(std::weak_ptr<Entity> entity) = 0;

    virtual ~AbstractCell() = default;
};


#endif //ABSTRACTCELL_H
