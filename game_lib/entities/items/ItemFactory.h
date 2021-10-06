#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "entities/EntityAbstractFactory.h"
#include <functional>

class ItemFactory : EntityAbstractFactory {
protected:
    std::function<bool(Creature &)> action;

public:
    ItemFactory(const std::function<bool(Creature &)> &action) : action(f) {}

    std::shared_ptr<Entity> build() final override {
        return std::shared_ptr<Item>(action);
    }
};


#endif //ITEMFACTORY_H
