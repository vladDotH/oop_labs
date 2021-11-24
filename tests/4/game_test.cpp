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
    Game<Collector<0>, Exterminator<-1>> g(
            FieldBuilder().setSize({20, 20}).setType(FieldBuilder::Type::BOX).build(),
            Generator<10, LightFactory>(), Generator<5, HealerFactory>(2)
    );

    ConsoleFieldView fv(g.f);
    cout << fv;

    cout << g.entrance << ' ' << g.exit;
    cout << g.enemies.size();
};