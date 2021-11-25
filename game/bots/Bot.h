#ifndef BOT_H
#define BOT_H

#include "controllers/EnemyController.h"
#include "controllers/PlayerController.h"
#include "logic/BotLogic.h"

template<class BL, typename std::enable_if<std::is_base_of<BotLogic, BL>::value, void *>::type * = nullptr>
class Bot : public Loggable {
protected:
    std::shared_ptr<Field> field;
    std::shared_ptr<PlayerController> pc;
    std::shared_ptr<EnemyController> ec;
    std::shared_ptr<BL> logic;

public:
    Bot(std::shared_ptr<Field> field, std::shared_ptr<PlayerController> pc,
        std::shared_ptr<EnemyController> ec, std::shared_ptr<BL> logic)
            : field(field), pc(pc), ec(ec), logic(logic) {}


    void spin() {
        Vec2D p = logic->solve(field, pc, ec);
        if (p != null) {
            if (p + ec->getPos() >= null && p + ec->getPos() < field->getSize()) {
                notify(info("bot has tried to move from: " + ec->getPos().toString() + " to: " +
                            (ec->getPos() + p).toString()));
                ec->move(p);
            } else notify(warn("bot has tried to move outside the field"));
        } else notify(info("bot has not moved"));
    }

    bool addLogger(std::shared_ptr<Logger> logger) override {
        return Loggable::addLogger(logger) && ec->addLogger(logger);
    }

    bool removeLogger(std::shared_ptr<Logger> logger) override {
        return Loggable::removeLogger(logger) && ec->removeLogger(logger);
    }

    std::shared_ptr<EnemyController> getController() {
        return ec;
    }
};


#endif //BOT_H
