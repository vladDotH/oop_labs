#ifndef ENTITYSNAPSHOT_H
#define ENTITYSNAPSHOT_H

#include "QJsonObject"
#include "entities/Entity.h"
#include "entities/creatures/Player.h"
#include "entities/creatures/enemies/Enemy.h"
#include "entities/items/Item.h"
#include <memory>
#include "SerializeException.h"
#include "Snapshot.h"

class EntitySnapshot : public Snapshot<std::shared_ptr<Entity>, std::shared_ptr<Entity>> {
public:
    static bool isCreature(std::string name) {
        return (name == typeid(Player).name()) || (name == typeid(Light).name()) ||
               (name == typeid(Medium).name()) || (name == typeid(Heavy).name());
    }

    static bool isItem(std::string name) {
        return (name == typeid(Healer).name()) || (name == typeid(Armor).name()) ||
               (name == typeid(Weapon).name());
    }

    QJsonObject serialize(std::shared_ptr<Entity> e) override {
        QJsonObject obj;
        obj["name"] = typeid(*e).name();
        std::shared_ptr<Creature> c = std::dynamic_pointer_cast<Creature>(e);
        if (c) {
            obj["hp"] = c->getHp();
            obj["armor"] = c->getArmor();
            obj["dmg"] = c->getDmg();
        }

        std::shared_ptr<Item> it = std::dynamic_pointer_cast<Item>(e);
        if (it) {
            obj["val"] = std::dynamic_pointer_cast<Item>(e)->getVal();
        }

        return obj;
    }

    std::shared_ptr<Entity> deserialize(QJsonObject obj) override {
        if (!(obj.contains("name") && obj["name"].isString()))
            throw (SerializeException("bad entity name"));

        std::string name = obj["name"].toString().toStdString();
        if (isCreature(name)) {
            if (!(obj.contains("hp") && obj.contains("armor") && obj.contains("dmg")
                  && obj["hp"].isDouble() && obj["armor"].isDouble() && obj["dmg"].isDouble())) {
                throw SerializeException("bad object");
            }
            float hp = obj["hp"].toDouble(), armor = obj["armor"].toDouble(), dmg = obj["dmg"].toDouble();

            if (name == typeid(Player).name())
                return std::make_shared<Player>(hp, dmg, armor);
            else if (name == typeid(Light).name())
                return std::make_shared<Light>(hp, dmg, armor);
            else if (name == typeid(Medium).name())
                return std::make_shared<Medium>(hp, dmg, armor);
            else if (name == typeid(Heavy).name())
                return std::make_shared<Heavy>(hp, dmg, armor);
            else
                throw SerializeException("bad object");

        } else if (isItem(name)) {
            if (!(obj.contains("val") && obj["val"].isDouble())) {
                throw SerializeException("bad object");
            }
            float val = obj["val"].toDouble();

            if (name == typeid(Healer).name())
                return std::make_shared<Healer>(val);
            else if (name == typeid(Armor).name())
                return std::make_shared<Armor>(val);
            else if (name == typeid(Weapon).name())
                return std::make_shared<Weapon>(val);
            else
                throw SerializeException("bad object");
        } else {
            throw (SerializeException("bad type"));
        }
    }
};

#endif //ENTITYSNAPSHOT_H
