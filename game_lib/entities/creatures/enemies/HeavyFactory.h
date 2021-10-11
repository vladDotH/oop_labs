#ifndef HEAVYFACTORY_H
#define HEAVYFACTORY_H

#include "EnemyFactory.h"

class HeavyFactory : public EnemyFactory {
public:
    HeavyFactory() : EnemyFactory(60, 2, 5) {}
};

#endif //HEAVYFACTORY_H
