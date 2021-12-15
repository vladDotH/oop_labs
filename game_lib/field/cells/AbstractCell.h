#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include <memory>
#include "../../entities/Entity.h"
#include "../../core/Cloneable.h"
#include "../../logging/Loggable.h"

class AbstractCell : public Cloneable<std::unique_ptr<AbstractCell>>, public Loggable {
protected:
    std::shared_ptr<Entity> entity;

public:
    std::shared_ptr<Entity> getEntity() {
        return entity;
    }

    bool moveTo(AbstractCell &cell) {
        if (this != &cell) {
            if (entity) {
                if (cell.putEntity(entity)) {
                    entity.reset();
                    notify(logDebug("object has been moved from cell"));
                    return true;
                } else notify(logDebug("object has not been moved from cell"));
            } else notify(logWarn("try to move empty entity"));
        } else notify(logWarn("try to move on same cell"));
        return false;
    }

    virtual bool putEntity(std::shared_ptr<Entity> entity) = 0;

    virtual ~AbstractCell() = default;
};


#endif //ABSTRACTCELL_H
