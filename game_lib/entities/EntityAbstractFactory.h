#ifndef ENTITYABSTRACTFACTORY_H
#define ENTITYABSTRACTFACTORY_H

#include "Entity.h"

class EntityAbstractFactory {
public:
    virtual std::shared_ptr<Entity> build() = 0;
};

#endif //ENTITYABSTRACTFACTORY_H
