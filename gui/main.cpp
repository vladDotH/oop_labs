#include "QApplication"
#include "Window.h"
#include "Game.h"
#include "rules/init/Generator.h"
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"

#include "entities/creatures/enemies/Enemy.h"
#include "entities/creatures/Player.h"
#include "memory"
#include "serialization/GameSnapshot.h"
#include "QJsonObject"
#include <QJsonDocument>


using namespace std;


int main(int argc, char *argv[]) {
//    QApplication app(argc, argv);
//    Window mw(
//            make_shared<Game>(
//                    FieldBuilder().setSize({30, 30}).setType(FieldBuilder::Type::BOX).build(),
//                    make_shared<Predator>(5),
//                    make_shared<ObjectsCounter>(3), make_shared<ObjectsCounter>(3),
//                    Generator(make_shared<LightFactory>(), 10),
//                    Generator(make_shared<HealerFactory>(50), 5),
//                    Generator(make_shared<WeaponFactory>(2), 5),
//                    Generator(make_shared<ArmorFactory>(2), 5),
//                    Generator(make_shared<MediumFactory>(), 6),
//                    Generator(make_shared<HeavyFactory>(), 5)
//            )
//    );
//    mw.show();
//    return app.exec();

    auto g = make_shared<Game>(
            FieldBuilder().setSize({20, 20}).setType(FieldBuilder::Type::DEFAULT).build(),
            make_shared<Predator>(5), make_shared<ObjectsCounter>(0), make_shared<ObjectsCounter>(-1),
            Generator(make_shared<LightFactory>(), 1),
            Generator(make_shared<HealerFactory>(50), 1),
            Generator(make_shared<WeaponFactory>(5), 1),
            Generator(make_shared<HeavyFactory>(), 1)
    );

    GameSnapshot gs;
    QJsonObject o = gs.serialize(g);
    QJsonDocument doc(o);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    shared_ptr<Game> g2 = gs.deserialize(o);
    cout << strJson.toStdString() << endl;

    QApplication app(argc, argv);
    Window mw;
    mw.show();
    return app.exec();
}
