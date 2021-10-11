#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "entities/EntityAbstractFactory.h"
#include <functional>

class ItemFactory : public EntityAbstractFactory {
protected:
    std::function<bool(Creature &)> action;

public:
    ItemFactory(const std::function<bool(Creature &)> &action) : action(action) {}

    std::shared_ptr<Entity> build() final override {
        return std::make_shared<Item>(action);
    }
};


#endif //ITEMFACTORY_H
