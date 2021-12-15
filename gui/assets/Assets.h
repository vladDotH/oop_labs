#ifndef ASSETS_H
#define ASSETS_H

#include "memory"
#include <QString>
#include <QSharedPointer>
#include <QImage>
#include <QKeyEvent>

class Assets {
private:
    Assets() {};
    static Assets *obj;

    struct NAMES {
        const QString path = "../../gui/assets/",
                floor = path + "floor.png",
                wall = path + "wall.png",
                entrance = path + "entrance.png",
                exit = path + "exit.png",
                player = path + "player.png",
                light = path + "light.png",
                medium = path + "medium.png",
                heavy = path + "heavy.png",
                heal = path + "heal.png",
                armor = path + "armor.png",
                weapon = path + "weapon.png";
    };

    struct KEYS {
        Qt::Key
                UP = Qt::Key_W,
                DOWN = Qt::Key_S,
                LEFT = Qt::Key_A,
                RIGHT = Qt::Key_D;
    };

    struct IMAGES {
        QSharedPointer<QImage>
                floor, wall, entrance, exit, player, light, medium, heavy, heal, armor, weapon;
    };

    void load();

public:
    Assets(const Assets &root) = delete;

    Assets &operator=(const Assets &) = delete;

    static Assets &get() {
        if (!obj) {
            obj = new Assets();
            obj->load();
        }
        return *obj;
    }

    NAMES names;
    IMAGES images;
    KEYS keys;
    const int SPRITE_SIZE = 40;
    const int GAME_FREQ = 700;
};

#endif //ASSETS_H
