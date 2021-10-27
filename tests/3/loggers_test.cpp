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
#include "loggers/Logger.h"
#include "loggers/ConsoleLogger.h"
#include "loggers/FileLogger.h"
#include "loggers/Loggable.h"
#include "loggers/formats/TagFormat.h"
#include "loggers/formats/TimeFormat.h"

using namespace std;

int main() {
    shared_ptr<Logger> l = make_shared<ConsoleLogger>();
    l->setFmt(make_shared<TimeFormat>());
    l->setLvl(Level::ALL);
    *l << Log(Level::WARN, "log warn");
    *l << Log(Level::DEBUG, "log debug");
    *l << error("log error");
    Level lv = Level::INFO;
    cout << lv.toString() << endl;

    *l << info("program end");
}