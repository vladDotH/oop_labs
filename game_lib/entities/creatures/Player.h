#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature {
public:
    constexpr static const float HP = 100, DMG = 7, ARM = 1;

    Player() : Creature(HP, DMG, ARM) {}

    std::shared_ptr<Entity> clone() override {
        return std::shared_ptr<Player>();
    }
};


#endif //PLAYER_H
