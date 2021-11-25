#ifndef BOTLOGIC_H
#define BOTLOGIC_H

#include <memory>
#include "field/Field.h"
#include "controllers/EnemyController.h"
#include "controllers/PlayerController.h"

class BotLogic {
public:
    virtual Vec2D solve(
            std::shared_ptr<Field> f,
            std::shared_ptr<PlayerController> pc,
            std::shared_ptr<EnemyController> ec) = 0;
};


#endif //BOTLOGIC_H
