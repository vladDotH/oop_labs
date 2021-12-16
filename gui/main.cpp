#include "QApplication"
#include "Window.h"
#include "Game.h"
#include "rules/init/Generator.h"
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"
#include "viewers/console/ConsoleFieldView.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window mw(
            make_shared<Game>(
                    FieldBuilder().setSize({30, 30}).setType(FieldBuilder::Type::BOX).build(),
                    make_shared<Predator>(5),
                    make_shared<ObjectsCounter>(3), make_shared<ObjectsCounter>(3),
                    Generator(make_shared<LightFactory>(), 10),
                    Generator(make_shared<HealerFactory>(50), 5),
                    Generator(make_shared<WeaponFactory>(2), 5),
                    Generator(make_shared<ArmorFactory>(2), 5),
                    Generator(make_shared<MediumFactory>(), 6),
                    Generator(make_shared<HeavyFactory>(), 5)
            )
    );
    mw.show();
    return app.exec();
}
