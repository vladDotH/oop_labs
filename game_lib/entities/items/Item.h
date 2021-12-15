#ifndef ITEM_H
#define ITEM_H

#include "../Entity.h"
#include "../creatures/Creature.h"
#include <functional>

class Item : public Entity {
protected:
    std::function<bool(Creature &)> action;

    bool interact(Creature &entity) override {
        action(entity);
        notify(logDebug("item interacted with creature"));
        return true;
    }

    bool interact(Item &entity) override {
        notify(logWarn("item interacted with item"));
        return true;
    }

public:
    Item(std::function<bool(Creature &)> f) : action(f) {}

    bool interact(std::shared_ptr<Entity> entity) override {
        return entity->interact(*this);
    }
};

class Healer : public Item {
private:
    float hp;
public:
    Healer(float hp) : hp(hp), Item([=](Creature &c) -> bool {
        return c.updHp(hp) > 0;
    }) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Healer>(hp);
    }
};

class Armor : public Item {
private:
    float arm;
public:
    Armor(float arm) : arm(arm), Item([=](Creature &c) -> bool {
        c.updArmor(arm);
        return true;
    }) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Armor>(arm);
    }
};

class Weapon : public Item {
private:
    float dmg;
public:
    Weapon(float dmg) : dmg(dmg), Item([=](Creature &c) -> bool {
        c.updDmg(dmg);
        return true;
    }) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Weapon>(dmg);
    }
};

#endif //ITEM_H
