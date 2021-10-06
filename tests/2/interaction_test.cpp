#include <iostream>
#include <viewers/FieldView.h>
#include <viewers/ConsoleFieldView.h>
#include <field/cells/Wall.h>
#include "field/Field.h"
#include "field/FieldBuilder.h"
#include <memory>
#include "entities/Player.h"
#include "entities/items/Item.h"
#include "entities/enemies/Enemy.h"

using namespace std;

int main() {
    weak_ptr<Entity> e;
    cout << e.expired() << endl;
    shared_ptr<Entity> s = make_shared<Enemy>();
    e = s;
    cout << e.expired();
//    shared_ptr<Entity> player = make_shared<Player>();
//    shared_ptr<Entity> enemy = make_shared<Enemy>();
//    shared_ptr<Entity> item = make_shared<Item>();
//    player->interact(enemy);
//    player->interact(item);
//    item->interact(player);
}
