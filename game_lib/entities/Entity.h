#ifndef ENTITY_H
#define ENTITY_H

#include <memory>
#include <iostream>
#include "entities_declarations.h"
#include "../core/Cloneable.h"
#include "../loggers/Loggable.h"

class Entity : public Cloneable<std::shared_ptr<Entity>>, public Loggable {
public:
    virtual bool interact(std::shared_ptr<Entity> entity) = 0;

    virtual bool interact(Creature &entity) = 0;

    virtual bool interact(Item &entity) = 0;
};


#endif //ENTITY_H
