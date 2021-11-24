#ifndef CREATURES_H
#define CREATURES_H

#include "Generator.h"
#include "entities/creatures/enemies/EnemyFactory.h"

template<int n>
class Creatures : public Generator<n, CreatureFactory> {
public:
    Creatures(std::shared_ptr<CreatureFactory> fct) : Generator<n, CreatureFactory>(fct) {}
};


#endif //CREATURES_H
