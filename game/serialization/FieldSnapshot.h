#ifndef FIELDSNAPSHOT_H
#define FIELDSNAPSHOT_H

#include "Snapshots_declaration.h"
#include "CellSnapshot.h"
#include "field/Field.h"
#include "QJsonArray"

class FieldSnapshot : Snapshot<std::shared_ptr<Field>, std::shared_ptr<Field>> {
protected:
    CellSnapshot cs;

public:
    QJsonObject serialize(std::shared_ptr<Field> f) override {
        QJsonObject obj;
        obj["x"] = f->getSize().x;
        obj["y"] = f->getSize().y;

        QJsonArray cells;
        for (int i = 0; i < f->getSize().y; ++i) {
            for (int j = 0; j < f->getSize().x; ++j) {
                cells.append(cs.serialize(f->get({j, i})));
            }
        }
        obj["cells"] = cells;
        return obj;
    }

    std::shared_ptr<Field> deserialize(QJsonObject obj) override {
        if (!(obj.contains("x") && obj.contains("y")
              && obj.contains("cells") && obj["cells"].isArray()))
            throw (SerializeException("incorrect field"));

        int x = obj["x"].toInt(), y = obj["y"].toInt();
        std::shared_ptr<Field> f = std::make_shared<Field>(Vec2D(x, y));

        QJsonArray cells = obj["cells"].toArray();

        if (x * y != cells.size())
            throw (SerializeException("bad field size"));

        for (int i = 0; i < cells.size(); ++i) {
            f->cells[i / x][i % x] = cs.deserialize(cells[i].toObject());
        }
        return f;
    }
};

#endif //FIELDSNAPSHOT_H
