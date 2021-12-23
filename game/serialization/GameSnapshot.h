#ifndef GAMESNAPSHOT_H
#define GAMESNAPSHOT_H

#include "FieldSnapshot.h"
#include "../Game.h"

class GameSnapshot : public Snapshot<std::shared_ptr<Game>, std::shared_ptr<Game>> {
protected:
    FieldSnapshot fs;

public:
    QJsonObject serLogic(std::shared_ptr<BotLogic> bl) {
        QJsonObject obj;
        obj["name"] = typeid(*bl).name();

        if (typeid(*bl).name() == typeid(Predator).name()) {
            obj["range"] = std::dynamic_pointer_cast<Predator>(bl)->getRange();
        }

        return obj;
    }

    std::shared_ptr<BotLogic> deserLogic(QJsonObject obj) {
        if (!(obj.contains("name") && obj["name"].isString()))
            throw (SerializeException("bad logic name"));

        std::string name = obj["name"].toString().toStdString();
        if (name == typeid(Predator).name()) {
            if (!obj.contains("range"))
                throw (SerializeException("no range"));
            return std::make_shared<Predator>(obj["range"].toInt());
        } else {
            throw (SerializeException("bad type"));
        }
    }

    QJsonObject serRule(std::shared_ptr<ObjectsCounter> oc) {
        QJsonObject obj;
        obj["count"] = oc->getN();
        return obj;
    }

    std::shared_ptr<ObjectsCounter> deserRule(QJsonObject obj) {
        if (!(obj.contains("count")))
            throw (SerializeException("bad counter"));
        return std::make_shared<ObjectsCounter>(obj["count"].toInt());
    }

    QJsonObject serVec(Vec2D v) {
        QJsonObject obj;
        obj["x"] = v.x;
        obj["y"] = v.y;
        return obj;
    }

    Vec2D deserVec(QJsonObject obj) {
        if (!(obj.contains("x") && obj.contains("y")))
            throw (SerializeException("bad vector"));
        return Vec2D(obj["x"].toInt(), obj["y"].toInt());
    }

    QJsonObject serialize(std::shared_ptr<Game> g) override {
        QJsonObject obj;
        obj["itemRule"] = serRule(g->irule);
        obj["enemRule"] = serRule(g->erule);
        obj["logic"] = serLogic(g->logic);
        obj["field"] = fs.serialize(g->getFld());
        obj["plPos"] = serVec(g->pc->getPos());
        return obj;
    };

    std::shared_ptr<Game> deserialize(QJsonObject obj) override {
        if (!(obj.contains("field") && obj.contains("logic")
              && obj.contains("itemRule") && obj.contains("enemRule") && obj.contains("plPos")
              && obj["field"].isObject() && obj["logic"].isObject()
              && obj["itemRule"].isObject() && obj["enemRule"].isObject() && obj["plPos"].isObject()))
            throw (SerializeException("bad game"));

        auto g = std::make_shared<Game>();
        g->init(fs.deserialize(obj["field"].toObject()), deserVec(obj["plPos"].toObject()),
                deserLogic(obj["logic"].toObject()), deserRule(obj["itemRule"].toObject()),
                deserRule(obj["enemRule"].toObject()));
        return g;
    }
};

#endif //GAMESNAPSHOT_H
