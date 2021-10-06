#ifndef HEAVYFACTORY_H
#define HEAVYFACTORY_H

#include "../CreatureFactory.h"

class HeavyFactory : CreatureFactory {
public:
    HeavyFactory() : CreatureFactory(60, 2, 5) {}
};

#endif //HEAVYFACTORY_H
