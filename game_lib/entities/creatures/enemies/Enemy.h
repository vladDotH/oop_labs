#ifndef ENEMY_H
#define ENEMY_H

#include "../Creature.h"

class Enemy : public Creature {
public:
    Enemy(float hp, float dmg, float armor) : Creature(hp, dmg, armor) {}
};

#endif //ENEMY_H
