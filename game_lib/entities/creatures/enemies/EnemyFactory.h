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

class LightFactory : public EnemyFactory {
public:
    LightFactory() : EnemyFactory(20, 5, 0) {}
};

class MediumFactory : public EnemyFactory {
public:
    MediumFactory() : EnemyFactory(40, 4, 2) {}
};

class HeavyFactory : public EnemyFactory {
public:
    HeavyFactory() : EnemyFactory(60, 2, 5) {}
};


#endif //ENEMYFACTORY_H
