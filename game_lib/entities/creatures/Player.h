#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature {
public:
    Player() : Creature(200, 10, 10) {}
};


#endif //PLAYER_H
