#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "entities/EntityFactory.h"
#include <functional>

class ItemFactory : public EntityFactory {
public:
    ItemFactory(std::shared_ptr<Item> e) : EntityFactory(e) {}
};

class HealerFactory : public ItemFactory {
public:
    HealerFactory(float hp = 50) : ItemFactory(std::make_shared<Healer>(hp)) {}
};

class ArmorFactory : public ItemFactory {
public:
    ArmorFactory(float arm = 3) : ItemFactory(std::make_shared<Armor>(arm)) {}
};

class WeaponFactory : public ItemFactory {
public:
    WeaponFactory(float dmg = 4) : ItemFactory(std::make_shared<Weapon>(dmg)) {}
};


#endif //ITEMFACTORY_H
