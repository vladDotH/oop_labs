#ifndef ARMORFACTORY_H
#define ARMORFACTORY_H

#include "ItemFactory.h"
#include "entities/Creature.h"

class ArmorFactory : ItemFactory {
public:
    ArmorFactory(float armor) :
            ItemFactory([](Creature &c) -> bool {
                c.updArmor(armor);
            }) {}
};

#endif //ARMORFACTORY_H
