#ifndef CREATUREFACTORY_H
#define CREATUREFACTORY_H

#include "../EntityFactory.h"

class CreatureFactory : public EntityFactory {
protected:
    float hp, dmg, armor;

public:
    CreatureFactory(float hp, float dmg, float armor) : hp(hp), dmg(dmg), armor(armor) {}

    std::shared_ptr<Entity> build() override {
        return std::make_shared<Creature>(hp, dmg, armor);
    }
};


#endif //CREATUREFACTORY_H
