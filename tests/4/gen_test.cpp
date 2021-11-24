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
#include "rules/init/Creautres.h"
#include "rules/init/Items.h"

using namespace std;

int main() {
    shared_ptr<Logger> controlLogger = make_shared<FileLogger>("logic_logs.txt"),
            modelLogger = make_shared<FileLogger>("model_logs.txt");

    controlLogger->setFmt(make_shared<TimeFormat>());
    modelLogger->setFmt(make_shared<TimeFormat>());

    shared_ptr<Field> f = FieldBuilder()
            .setSize({20, 20})
            .setType(FieldBuilder::Type::BOX)
            .build();

    ConsoleFieldView fv(f);

    shared_ptr<Entity> player = make_shared<Player>();

    f->addLogger(modelLogger);
    player->addLogger(modelLogger);

    shared_ptr<EnemyFactory> ef = make_shared<LightFactory>();

    Generator<10, HealerFactory> enemies(10);
    cout << enemies.generate(f) << endl;

    cout << fv;
}
