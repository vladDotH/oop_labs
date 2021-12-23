#ifndef ITEM_H
#define ITEM_H

#include "../Entity.h"
#include "../creatures/Creature.h"
#include <functional>

class Item : public Entity {
protected:
    float val;
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
    Item(float val, std::function<bool(Creature &)> f) : val(val), action(f) {}

    bool interact(std::shared_ptr<Entity> entity) override {
        return entity->interact(*this);
    }

    float getVal() const {
        return val;
    }
};

class Healer : public Item {
public:
    Healer(float hp) : Item(hp, [=](Creature &c) -> bool {
        return c.updHp(hp) > 0;
    }) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Healer>(val);
    }
};

class Armor : public Item {
public:
    Armor(float arm) : Item(arm, [=](Creature &c) -> bool {
        c.updArmor(arm);
        return true;
    }) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Armor>(val);
    }
};

class Weapon : public Item {
public:
    Weapon(float dmg) : Item(dmg, [=](Creature &c) -> bool {
        c.updDmg(dmg);
        return true;
    }) {}

    std::shared_ptr<Entity> clone() override {
        return std::make_shared<Weapon>(val);
    }
};

#endif //ITEM_H
