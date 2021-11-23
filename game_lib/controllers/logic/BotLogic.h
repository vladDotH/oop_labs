#ifndef BOTLOGIC_H
#define BOTLOGIC_H

#include <memory>
#include "Field.h"
#include "EnemyController.h"
#include "PlayerController.h"

class BotLogic {
public:
    virtual Vec2D operator()(
            std::shared_ptr<Field> f,
            std::shared_ptr<PlayerController>
            std::shared_ptr <EnemyController> ec) = 0;
};


#endif //BOTLOGIC_H
