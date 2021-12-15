#ifndef CREATURE_H
#define CREATURE_H

#include "../Entity.h"

class Creature : public Entity {
protected:
    float hp, dmg, armor;

    bool interact(Creature &entity) override {
        float d = -dmg + entity.armor;
        notify(logDebug("creature has interacted with creature with resulting dmg:" + std::to_string(d)));
        return entity.updHp(d < 0 ? d : 0) > 0;
    }

    bool interact(Item &entity) override {
        notify(logDebug("creature has interacted with item"));
        return false;
    }

public:
    Creature(float hp, float dmg, float armor) : hp(hp), dmg(dmg), armor(armor) {}

    bool interact(std::shared_ptr<Entity> entity) override {
        return entity->interact(*this);
    }

    float updHp(float hp) {
        notify(logDebug("hp has been increased by: " + std::to_string(hp)));
        return this->hp += hp;
    }

    float updDmg(float dmg) {
        notify(logDebug("damage has been increased by: " + std::to_string(dmg)));
        return this->dmg += dmg;
    }

    float updArmor(float armor) {
        notify(logDebug("armor has been increased by: " + std::to_string(armor)));
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
};


#endif //CREATURE_H
