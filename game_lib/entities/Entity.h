#ifndef ENTITY_H
#define ENTITY_H

#include "memory"
#include "iostream"
#include "Entities_Declarations.h"

class Entity {
    enum Result {
        SUCCES,
        FAIL,
        NEUTRAL
    };
public:
    virtual bool interact(std::shared_ptr<Entity> entity) = 0;
    virtual bool interact(Creature& entity) = 0;
    virtual bool interact(Item& entity) = 0;
};

#endif //ENTITY_H
