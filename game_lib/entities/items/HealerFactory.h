#ifndef HEALERFACTORY_H
#define HEALERFACTORY_H

#include "ItemFactory.h"
#include "entities/Creature.h"

class HealerFactory : ItemFactory {
public:
    HealerFactory(float hp) :
            ItemFactory([](Creature &c) -> bool {
                c.updHp(hp);
            }) {}
};

#endif //HEALERFACTORY_H
