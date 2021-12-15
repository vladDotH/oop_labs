#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include "Entity.h"

class EntityFactory {
protected:
    std::shared_ptr<Entity> e;
public:
    EntityFactory(std::shared_ptr<Entity> e) : e(e) {}

    virtual std::shared_ptr<Entity> build() {
        return e ? e->clone() : nullptr;
    }
};


#endif //ENTITYFACTORY_H
