#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "entities/EntityFactory.h"
#include <functional>

class ItemFactory : public EntityFactory {
protected:
    std::function<bool(Creature &)> action;

public:
    ItemFactory(const std::function<bool(Creature &)> &action) : action(action) {}

    std::shared_ptr<Entity> build() final override {
        return std::make_shared<Item>(action);
    }
};

class HealerFactory : public ItemFactory {
public:
    HealerFactory(float hp) :
            ItemFactory([=](Creature &c) -> bool {
                return c.updHp(hp) > 0;
            }) {}
};

class ArmorFactory : public ItemFactory {
public:
    ArmorFactory(float armor) :
            ItemFactory([=](Creature &c) -> bool {
                c.updArmor(armor);
                return true;
            }) {}
};

class WeaponFactory : public ItemFactory {
public:
    WeaponFactory(float dmg) :
            ItemFactory([=](Creature &c) -> bool {
                c.updDmg(dmg);
                return true;
            }) {}
};


#endif //ITEMFACTORY_H
