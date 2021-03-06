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

class A : public Loggable {
public:
    void f() {
        notify(logInfo("function f called"));
    }
};

int main() {
    shared_ptr<Logger>
            l1 = make_shared<FileLogger>("log.txt"),
            l2 = make_shared<ConsoleLogger>(cout);
    A a;
    cout << a.addLogger(l1) << endl;
    cout << a.addLogger(l2) << endl;
    cout << a.addLogger(l1) << endl;
    cout << a.addLogger(l2) << endl;

    a.f();

    cout << a.removeLogger(l2) << endl;
    cout << a.removeLogger(l2) << endl;

    a.f();
}
