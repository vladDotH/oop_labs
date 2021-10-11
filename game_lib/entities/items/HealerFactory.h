#ifndef HEALERFACTORY_H
#define HEALERFACTORY_H

#include "ItemFactory.h"
#include "entities/creatures/Creature.h"

class HealerFactory : public ItemFactory {
public:
    HealerFactory(float hp) :
            ItemFactory([=](Creature &c) -> bool {
                return c.updHp(hp) > 0;
            }) {}
};

#endif //HEALERFACTORY_H
