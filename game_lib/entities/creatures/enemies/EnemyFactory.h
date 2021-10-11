#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "../CreatureFactory.h"

class EnemyFactory : public CreatureFactory {
public:
    EnemyFactory(float hp, float dmg, float armor) : CreatureFactory(hp, dmg, armor) {}

    std::shared_ptr<Entity> build() override {
        return std::make_shared<Enemy>(hp, dmg, armor);
    }
};

#endif //ENEMYFACTORY_H
