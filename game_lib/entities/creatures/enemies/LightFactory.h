#ifndef LIGHTFACTORY_H
#define LIGHTFACTORY_H

#include "EnemyFactory.h"

class LightFactory : public EnemyFactory {
public:
    LightFactory() : EnemyFactory(20, 5, 0) {}
};

#endif //LIGHTFACTORY_H
