#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"

class Creature : public Entity {
protected:
    float hp, dmg, armor;

    bool interact(Creature &entity) override {
        std::cout << "creature with creature\n";
        return entity.updHp(-dmg + entity.armor) > 0;
    }

    bool interact(Item &entity) override {
        std::cout << "creature with item\n";
        return true;
    }

public:
    Creature() = default;

    Creature(float hp, float dmg, float armor) : hp(hp), dmg(dmg), armor(armor) {}

    bool interact(std::shared_ptr<Entity> entity) override {
        return entity->interact(*this);
    }

    float updHp(float hp) {
        return this->hp += hp;
    }

    float updDmg(float dmg) {
        return this->dmg += dmg;
    }

    float updArmor(float armor) {
        return this->armor += armor;
    }
};

#endif //CREATURE_H
