#ifndef LIGHTFACTORY_H
#define LIGHTFACTORY_H

#include "../CreatureFactory.h"

class LightFactory : CreatureFactory {
public:
    LightFactory() : CreatureFactory(20, 5, 0) {}
};

#endif //LIGHTFACTORY_H
