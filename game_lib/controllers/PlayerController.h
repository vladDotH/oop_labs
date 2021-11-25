#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "BaseController.h"
#include "../entities/creatures/Player.h"

class PlayerController : public BaseController<Player> {
public:
    PlayerController(std::shared_ptr<Field> field, std::shared_ptr<Player> obj, Vec2D pos = -one, bool put = true)
            : BaseController(field, obj, pos, put) {}

    PlayerController(std::shared_ptr<Field> field, std::shared_ptr<Entity> obj, Vec2D pos = -one, bool put = true)
            : BaseController(field, obj, pos, put) {}
};


#endif //PLAYERCONTROLLER_H
