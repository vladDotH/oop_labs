#ifndef BOT_H
#define BOT_H

#include "EnemyController.h"
#include "PlayerController.h"

class Bot : protected EnemyController {
protected:
    std::shared_ptr<PlayerController> player;
public:
    Bot(std::shared_ptr<Field> field, std::shared_ptr<Enemy> obj, Vec2D pos = -one) : EnemyController(
            field, obj, pos) {}

    Bot(std::shared_ptr<Field> field, std::shared_ptr<Entity> obj, Vec2D pos = -one) : EnemyController(
            field, obj, pos) {
    }


};


#endif //BOT_H
