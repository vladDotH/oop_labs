#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H

#include "ItemFactory.h"
#include "entities/Creature.h"

class WeaponFactory : ItemFactory {
public:
    WeaponFactory(float dmg) :
            ItemFactory([](Creature &c) -> bool {
                c.updDmg(dmg);
            }) {}
};

#endif //WEAPONFACTORY_H
