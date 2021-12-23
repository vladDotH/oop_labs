#ifndef ENEMY_H
#define ENEMY_H

#include "../Creature.h"

class Enemy : public Creature {
public:
    Enemy(float hp, float dmg, float armor) : Creature(hp, dmg, armor) {}
};

class Light : public Enemy {
public:
    constexpr static const float HP = 20, DMG = 7, ARM = 0;

    Light() : Enemy(HP, DMG, ARM) {}

    Light(float hp, float dmg, float armor) : Enemy(hp, dmg, armor) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Light>();
    }
};

class Medium : public Enemy {
public:
    constexpr static const float HP = 40, DMG = 6, ARM = 2;

    Medium() : Enemy(HP, DMG, ARM) {}

    Medium(float hp, float dmg, float armor) : Enemy(hp, dmg, armor) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Medium>();
    }
};

class Heavy : public Enemy {
public:
    constexpr static const float HP = 50, DMG = 5, ARM = 4;

    Heavy() : Enemy(HP, DMG, ARM) {}

    Heavy(float hp, float dmg, float armor) : Enemy(hp, dmg, armor) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Heavy>();
    }
};

#endif //ENEMY_H
