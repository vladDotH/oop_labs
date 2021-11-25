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
#include "bots/Bot.h"
#include "bots/logic/Predator.h"
#include "rules/end/Collector.h"

using namespace std;

int main() {
    shared_ptr<Logger> controlLogger = make_shared<FileLogger>("logic_logs.txt"),
            modelLogger = make_shared<FileLogger>("model_logs.txt");

    controlLogger->setFmt(make_shared<TimeFormat>());
    modelLogger->setFmt(make_shared<TimeFormat>());

    shared_ptr<Field> f = FieldBuilder()
            .setSize({10, 10})
            .setType(FieldBuilder::Type::BOX)
            .build();

    ConsoleFieldView fv(f);

    shared_ptr<Entity> player = make_shared<Player>();

    f->addLogger(modelLogger);
    player->addLogger(modelLogger);

    shared_ptr<EntityFactory> hp = make_shared<HealerFactory>(100);

    shared_ptr<Item> i1 = dynamic_pointer_cast<Item>(hp->build()),
            i2 = dynamic_pointer_cast<Item>(hp->build()),
            i3 = dynamic_pointer_cast<Item>(hp->build());

    f->get({3, 3}).putEntity(i1);
    f->get({6, 3}).putEntity(i2);
    f->get({3, 6}).putEntity(i3);
    Vec2D exit = {8, 8};

    shared_ptr<PlayerController> pc = make_shared<PlayerController>(f, player, Vec2D(1, 1));
    pc->addLogger(controlLogger);

    vector<weak_ptr<Item>> items = {i1, i2, i3};
    i1.reset(), i2.reset(), i3.reset();

    Collector<-1> cl;
    cl.init(f, pc, exit, items);

    cout << fv;
    cout << cl.end() << endl;

    pc->moveAbs({3, 3});
    cout << fv;
    cout << cl.end() << endl;

    pc->moveAbs({6, 3});
    cout << fv;
    cout << cl.end() << endl;

    pc->moveAbs({3, 6});
    cout << fv;
    cout << cl.end() << endl;

    pc->moveAbs(exit);
    cout << fv;
    cout << cl.end() << endl;
}
