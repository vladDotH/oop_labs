#ifndef ARMORFACTORY_H
#define ARMORFACTORY_H

#include "ItemFactory.h"
#include "entities/creatures/Creature.h"

class ArmorFactory : public ItemFactory {
public:
    ArmorFactory(float armor) :
            ItemFactory([=](Creature &c) -> bool {
                c.updArmor(armor);
                return true;
            }) {}
};

#endif //ARMORFACTORY_H
