#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "../CreatureFactory.h"

class EnemyFactory : public CreatureFactory {
public:
    EnemyFactory(std::shared_ptr<Enemy> e) : CreatureFactory(e) {}
};

class LightFactory : public EnemyFactory {
public:
    LightFactory() : EnemyFactory(std::make_shared<Light>()) {}
};

class MediumFactory : public EnemyFactory {
public:
    MediumFactory() : EnemyFactory(std::make_shared<Medium>()) {}
};

class HeavyFactory : public EnemyFactory {
public:
    HeavyFactory() : EnemyFactory(std::make_shared<Heavy>()) {}
};


#endif //ENEMYFACTORY_H
