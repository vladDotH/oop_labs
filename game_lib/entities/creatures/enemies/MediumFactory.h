#ifndef MEDIUMFACTORY_H
#define MEDIUMFACTORY_H

#include "EnemyFactory.h"

class MediumFactory : public EnemyFactory {
public:
    MediumFactory() : EnemyFactory(40, 4, 2) {}
};

#endif //MEDIUMFACTORY_H
