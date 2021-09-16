#ifndef CELL_H
#define CELL_H

#include "../entities/Entity.h"

class Cell {
public:
    enum Type {
        WALL,
        REGULAR,
        ENTRANCE,
        EXIT
    };

private:
    Type type;
    Entity *entity = nullptr;

public:
    Cell() = default;

    void setType(Type type);

    Type getType() const;

    void putEntity(Entity *entity);
    
    Entity *getEntity();
};

#endif //CELL_H
