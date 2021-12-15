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
#include "logging/Loggable.h"
#include "logging/formats/TagFormat.h"
#include "logging/formats/TimeFormat.h"

using namespace std;

int main() {
    shared_ptr<Logger> l = make_shared<ConsoleLogger>();
    l->setFmt(make_shared<TimeFormat>());
    l->setLvl(LogLevel::ALL);
    *l << Log(LogLevel::WARN, "log logWarn");
    *l << Log(LogLevel::DEBUG, "log logDebug");
    *l << logErr("log logErr");
    LogLevel lv = LogLevel::INFO;
    cout << lv.toString() << endl;

    *l << logInfo("program end");
}
