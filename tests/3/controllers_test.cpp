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
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"
#include "controllers/BaseController.h"
#include "controllers/PlayerController.h"
#include "controllers/EnemyController.h"
#include "logging/loggers/Logger.h"
#include "logging/loggers/ConsoleLogger.h"
#include "logging/loggers/FileLogger.h"
#include "logging/formats/TimeFormat.h"
#include "controllers/PlayerController.h"
#include "controllers/EnemyController.h"

using namespace std;

int main() {
    shared_ptr<Logger> lg = make_shared<FileLogger>("log.txt");
    lg->setFmt(make_shared<TimeFormat>());
    shared_ptr<Field> f = FieldBuilder()
            .setSize({10, 10})
            .setType(FieldBuilder::Type::BOX)
            .build();
    f->addLogger(lg);

    ConsoleFieldView fv(f);

    shared_ptr<Entity> player = make_shared<Player>();
    player->addLogger(lg);

    shared_ptr<EntityFactory> lf = make_shared<LightFactory>(), hp = make_shared<HealerFactory>(100);

    shared_ptr<Entity>
            e1 = lf->build(),
            e2 = lf->build(),
            e3 = lf->build(),
            i1 = hp->build(),
            i2 = hp->build(),
            i3 = hp->build();

    PlayerController pc(f, player, Vec2D(1, 1));
    pc.addLogger(lg);
    EnemyController ec1(f, e1, {5, 5}),
            ec2(f, e2, {5, 6}),
            ec3(f, e3, {6, 5});

    cout << fv;

//    pc.put();
//    ec1.put();
//    ec2.put();
//    ec3.put();

    f->get({3, 3}).putEntity(i1);
    f->get({6, 3}).putEntity(i2);
    f->get({3, 6}).putEntity(i3);

    cout << fv;
    cout << (dynamic_cast<Player *>(player.get()))->getHp() << endl;

    pc.move({2, 2});

    cout << fv;
    cout << (dynamic_cast<Player *>(player.get()))->getHp() << endl;

    pc.move({2, 2});

    cout << fv;
    cout << (dynamic_cast<Player *>(player.get()))->getHp() << endl;
    cout << (dynamic_cast<Enemy *>(e1.get()))->getHp() << endl;

    pc.move({2, 2});

    cout << fv;
    cout << (dynamic_cast<Player *>(player.get()))->getHp() << endl;
    cout << (dynamic_cast<Enemy *>(e1.get()))->getHp() << endl;

    pc.move({2, 2});

    cout << fv;
    cout << (dynamic_cast<Player *>(player.get()))->getHp() << endl;
    cout << (dynamic_cast<Enemy *>(e1.get()))->getHp() << endl;

    pc.move({-2, -2});
    cout << fv;

    pc.moveAbs({8, 8});
    cout << fv;

    cout << typeid((f->get({8, 8}).getEntity())).name();
}
