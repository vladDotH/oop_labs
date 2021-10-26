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

using namespace std;

class A : public Loggable {
public:
    void f() {
        notify(info("function f called\n"));
    }
};

int main() {
    auto l = make_shared<FileLogger>("out.txt");
    l->setLvl(Level::INFO);
    *l << Log(Level::WARN, "log warn\n");
    *l << Log(Level::DEBUG, "log debug\n");
    *l << debug("log error\n");
    Level lv = Level::INFO;
    cout << lv.toString() << endl;

    shared_ptr<Logger>
            l1 = make_shared<FileLogger>("log.txt"),
            l2 = make_shared<ConsoleLogger>(cout);
    A a;
    cout << a.addLogger(l1) << endl;
    cout << a.addLogger(l2) << endl;
    cout << a.addLogger(l1) << endl;
    cout << a.addLogger(l2) << endl;

    a.f();
}
