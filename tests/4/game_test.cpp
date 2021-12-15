#include "Game.h"
#include "rules/init/Generator.h"
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"
#include "viewers/console/ConsoleFieldView.h"

#include <iostream>

using namespace std;

int main() {
    Game g(
            FieldBuilder().setSize({20, 20}).setType(FieldBuilder::Type::BOX).build(),
            make_shared<Predator>(5), make_shared<ObjectsCounter>(0), make_shared<ObjectsCounter>(-1),
            Generator(make_shared<LightFactory>(), 10),
            Generator(make_shared<HealerFactory>(50), 5),
            Generator(make_shared<WeaponFactory>(5), 3),
            Generator(make_shared<HeavyFactory>(), 10)
    );

    ConsoleFieldView fv(g.getFld());
    cout << fv;

    g.spin();
    cout << fv;
    g.spin();
    cout << fv;

//    cout << "walls: \n";
//    for (auto i : g.getWalls()) {
//        cout << i << endl;
//    }
//
//    cout << "tiles: \n";
//    for (auto i : g.getTiles()) {
//        cout << i << endl;
//    }

    cout << "enemies: \n";
    for (auto i : g.getEnemyinfo()) {
        cout << i->getPos() << endl;
    }

    cout << "items: \n";
    for (auto i : g.getIteminfo()) {
        cout << i->getPos() << endl;
    }
};