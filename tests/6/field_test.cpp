#include "serialization/EntitySnapshot.h"
#include <iostream>
#include "QJsonDocument"
#include "Game.h"
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"
#include "serialization/FieldSnapshot.h"

using namespace std;

int main() {
    Game g(
            FieldBuilder().setSize({3, 3}).setType(FieldBuilder::Type::DEFAULT).build(),
            make_shared<Predator>(5), make_shared<ObjectsCounter>(0), make_shared<ObjectsCounter>(-1),
            Generator(make_shared<LightFactory>(), 1),
            Generator(make_shared<HealerFactory>(50), 1),
            Generator(make_shared<WeaponFactory>(5), 1),
            Generator(make_shared<HeavyFactory>(), 1)
    );
    FieldSnapshot fs;
    QJsonObject o = fs.serialize(g.getFld());
    QJsonDocument doc(o);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    cout << strJson.toStdString() << endl;
    shared_ptr<Field> f = fs.deserialize(o);
};