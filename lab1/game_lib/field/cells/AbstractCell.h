#ifndef ABSTRACTCELL_H
#define ABSTRACTCELL_H

#include "../../entities/Entity.h"

enum CELLS_ID {
    CELL,
    WALL,
    ENTRANCE,
    EXIT
};

class AbstractCell {
protected:
    Entity *entity = nullptr;

public:
    AbstractCell() = default;

    virtual CELLS_ID getID() const = 0 ;

    virtual bool putEntity(Entity *entity) = 0;

    virtual bool interact(Entity *entity) = 0;

    virtual AbstractCell *copy() = 0;

    virtual ~AbstractCell() = default;
};

#endif //ABSTRACTCELL_H
