#ifndef MEDIUMFACTORY_H
#define MEDIUMFACTORY_H

#include "../CreatureFactory.h"

class MediumFactory : CreatureFactory {
public:
    MediumFactory() : CreatureFactory(40, 4, 2) {}
};

#endif //MEDIUMFACTORY_H
