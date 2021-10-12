#ifndef CREATURE_H
#define CREATURE_H

#include "../Entity.h"

class Creature : public Entity {
protected:
    float hp, dmg, armor;

    bool interact(Creature &entity) override {
        std::cout << "creature with creature\n";
        float d = -dmg + entity.armor;
        return entity.updHp(d < 0 ? d : 0) > 0;
    }

    bool interact(Item &entity) override {
        std::cout << "creature with item\n";
        return false;
    }

public:
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

    float getHp() const {
        return hp;
    }

    float getDmg() const {
        return dmg;
    }

    float getArmor() const {
        return armor;
    }

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Creature>(hp, dmg, armor);
    }
};


#endif //CREATURE_H
