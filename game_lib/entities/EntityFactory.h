#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"

class EntityFactory {
public:
    virtual std::shared_ptr<Entity> build() = 0;
};


#endif //ENTITYFACTORY_H
