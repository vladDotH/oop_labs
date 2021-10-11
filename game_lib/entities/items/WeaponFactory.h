#ifndef WEAPONFACTORY_H
#define WEAPONFACTORY_H

#include "ItemFactory.h"
#include "entities/creatures/Creature.h"

class WeaponFactory : public ItemFactory {
public:
    WeaponFactory(float dmg) :
            ItemFactory([=](Creature &c) -> bool {
                c.updDmg(dmg);
                return true;
            }) {}
};

#endif //WEAPONFACTORY_H
