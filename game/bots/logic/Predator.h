#ifndef PREDATOR_H
#define PREDATOR_H

#include "core/Vec2D.h"
#include "BotLogic.h"

class Predator : public BotLogic {
protected:
    int range;
public:
    Predator(int range = 0) : range(range) {}

    Vec2D solve(std::shared_ptr<Field> f,
                     std::shared_ptr<PlayerController> pc,
                     std::shared_ptr<EnemyController> ec) override {
        Vec2D dv = pc->getPos() - ec->getPos();
        if ((int) dv.norm() <= range) {
            return dv.getDir();
        }
        return null;
    }
};


#endif //PREDATOR_H
