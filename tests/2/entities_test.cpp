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
#include "entities/creatures/CreatureFactory.h"
#include "entities/creatures/enemies/HeavyFactory.h"
#include "entities/creatures/enemies/MediumFactory.h"
#include "entities/creatures/enemies/LightFactory.h"
#include "entities/items/ItemFactory.h"
#include "entities/items/HealerFactory.h"
#include "entities/items/ArmorFactory.h"
#include "entities/items/WeaponFactory.h"

using namespace std;

int main() {
    shared_ptr<Field> f = FieldBuilder().setSize({10, 10}).setType(FieldBuilder::BOX).build();
    ConsoleFieldView fv(f);

    shared_ptr<Entity> player = make_shared<Player>();
    shared_ptr<EntityAbstractFactory> lf = make_shared<LightFactory>(), hp = make_shared<HealerFactory>(100);

    shared_ptr<Entity>
            e1 = lf->build(),
            e2 = lf->build(),
            e3 = lf->build(),
            i1 = hp->build(),
            i2 = hp->build(),
            i3 = hp->build();

    cout << fv;

    f->get({1,1}).putEntity(player);
    f->get({5,5}).putEntity(e1);
    f->get({5,6}).putEntity(e2);
    f->get({6,5}).putEntity(e3);
    f->get({3, 3}).putEntity(i1);
    f->get({6, 3}).putEntity(i2);
    f->get({3, 6}).putEntity(i3);

    cout << fv;
    cout << (dynamic_cast<Player*>(player.get()))->getHp() << endl;

    f->get({1,1}).moveTo(f->get({3,3}));

    cout << fv;
    cout << (dynamic_cast<Player*>(player.get()))->getHp() << endl;
    cout << (dynamic_cast<Enemy*>(e1.get()))->getHp() << endl;

    f->get({3,3}).moveTo(f->get({5,5}));

    cout << fv;
    cout << (dynamic_cast<Player*>(player.get()))->getHp() << endl;
    cout << (dynamic_cast<Enemy*>(e1.get()))->getHp() << endl;

    f->get({3,3}).moveTo(f->get({5,5}));

    cout << fv;
    cout << (dynamic_cast<Player*>(player.get()))->getHp() << endl;
    cout << (dynamic_cast<Enemy*>(e1.get()))->getHp() << endl;

}
