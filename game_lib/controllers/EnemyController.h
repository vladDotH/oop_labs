#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include "BaseController.h"
#include "../entities/creatures/enemies/Enemy.h"

class EnemyController : public BaseController<Enemy> {
public:
    EnemyController(std::shared_ptr<Field> field, std::shared_ptr<Enemy> obj, Vec2D pos = -one, bool put = true)
            : BaseController(field, obj, pos, put) {}

    EnemyController(std::shared_ptr<Field> field, std::shared_ptr<Entity> obj, Vec2D pos = -one, bool put = true)
            : BaseController(field, obj, pos, put) {}
};


#endif //ENEMYCONTROLLER_H
