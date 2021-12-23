#include <iostream>
#include <viewers/FieldView.h>
#include <viewers/console/ConsoleFieldView.h>
#include <field/cells/Wall.h>
#include "field/Field.h"
#include "field/FieldBuilder.h"
#include <memory>
#include "entities/creatures/Player.h"
#include "entities/items/Item.h"
#include "entities/creatures/enemies/Enemy.h"

using namespace std;

int main() {
    weak_ptr<Entity> e;
    cout << e.expired() << endl;
    shared_ptr<Entity> s = make_shared<Light>();
    e = s;
    cout << e.expired();
    shared_ptr<Entity> player = make_shared<Player>();
    shared_ptr<Entity> enemy = make_shared<Light>();
    shared_ptr<Entity> item = make_shared<Healer>(10);
    player->interact(enemy);
    player->interact(item);
    item->interact(player);
}
