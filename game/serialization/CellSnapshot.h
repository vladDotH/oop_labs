#ifndef CELLSNAPSHOT_H
#define CELLSNAPSHOT_H

#include "QJsonObject"
#include "EntitySnapshot.h"
#include "field/cells/AbstractCell.h"
#include "field/cells/Cell.h"
#include "field/cells/Exit.h"
#include "field/cells/Entrance.h"
#include "field/cells/Wall.h"
#include <memory>
#include "SerializeException.h"

class CellSnapshot : public Snapshot<AbstractCell &, std::unique_ptr<AbstractCell>> {
protected:
    EntitySnapshot es;

public:
    QJsonObject serialize(AbstractCell &c) override {
        QJsonObject obj;
        obj["name"] = typeid(c).name();
        obj["entity"] = QJsonValue::Null;
        if (c.getEntity()) {
            obj["entity"] = es.serialize(c.getEntity());
        }
        return obj;
    }

    std::unique_ptr<AbstractCell> deserialize(QJsonObject obj) override {
        if (!(obj.contains("name") && obj["name"].isString()))
            throw (SerializeException("bad cell name"));

        std::string name = obj["name"].toString().toStdString();

        if (!obj.contains("entity") || !(obj["entity"].isObject() || obj["entity"].isNull()))
            throw (SerializeException("entity not found"));

        std::unique_ptr<AbstractCell> c;

        if (name == typeid(Cell).name())
            c = std::make_unique<Cell>();
        else if (name == typeid(Exit).name())
            c = std::make_unique<Exit>();
        else if (name == typeid(Entrance).name())
            c = std::make_unique<Entrance>();
        else if (name == typeid(Wall).name())
            c = std::make_unique<Wall>();
        else
            throw SerializeException("bad object");

        if (!obj["entity"].isNull())
            c->putEntity(es.deserialize(obj["entity"].toObject()));
        return c;
    }
};

#endif //CELLSNAPSHOT_H
