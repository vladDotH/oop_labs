#include "Game.h"
#include "rules/init/Generator.h"
#include "rules/end/Exterminator.h"
#include "rules/end/Collector.h"
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"
#include "viewers/console/ConsoleFieldView.h"

#include <iostream>

using namespace std;

int main() {
    Game<Collector<0>, Exterminator<-1>, Predator> g(
            FieldBuilder().setSize({20, 20}).setType(FieldBuilder::Type::BOX).build(),
            make_shared<Predator>(5),
            Generator<10, LightFactory>(),
            Generator<5, HealerFactory>(20),
            Generator<5, HeavyFactory>(),
            Generator<3, WeaponFactory>(5)
    );

    ConsoleFieldView fv(g.getFld());
    cout << fv;

    g.spin();
    cout << fv;
    g.spin();
    cout << fv;
};