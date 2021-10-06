#ifndef CREATUREFACTORY_H
#define CREATUREFACTORY_H

#include "EntityAbstractFactory.h"

class CreatureFactory : EntityAbstractFactory {
protected:
    float hp, dmg, armor;

public:
    CreatureFactory(float hp, float dmg, float armor) : hp(hp), dmg(dmg), armor(armor) {}

    std::shared_ptr<Entity> build() override {
        return std::shared_ptr<Creature>(hp, dmg, armor);
    }
};

#endif //CREATUREFACTORY_H
