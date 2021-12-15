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

    shared_ptr<EntityFactory> lf = make_shared<LightFactory>(), hp = make_shared<HealerFactory>(100);

    shared_ptr<Entity> e1 = lf->build(),
            i1 = hp->build();

    f->addLogger(modelLogger);
    player->addLogger(modelLogger);
    e1->addLogger(modelLogger);

    shared_ptr<PlayerController> pc = make_shared<PlayerController>(f, player, Vec2D(1, 1));
    Bot bot(f, pc,
                      make_shared<EnemyController>(f, e1, Vec2D(5, 5)),
                      make_shared<Predator>(4));
    e1.reset();

    pc->addLogger(controlLogger);
    bot.addLogger(controlLogger);

    cout << fv;

    pc->moveAbs({5, 2});

    cout << fv;

    bot.spin();
    cout << fv;

    bot.spin();
    cout << fv;

    bot.spin();
    cout << fv;

    bot.spin();
    cout << fv;
}
