#include "QApplication"
#include "Window.h"
#include "Game.h"
#include "rules/init/Generator.h"
#include "entities/creatures/enemies/EnemyFactory.h"
#include "entities/items/ItemFactory.h"

#include "entities/creatures/enemies/Enemy.h"
#include "entities/creatures/Player.h"
#include "memory"
#include "serialization/GameSnapshot.h"
#include "QJsonObject"
#include <QJsonDocument>


using namespace std;


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Window mw;
    mw.show();
    return app.exec();
}
