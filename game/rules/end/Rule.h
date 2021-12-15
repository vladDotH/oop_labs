#ifndef RULE_H
#define RULE_H

#include <memory>
#include "field/Field.h"
#include "controllers/PlayerController.h"
#include "core/Vec2D.h"

class Rule {
protected:
    std::shared_ptr<Field> field;
    std::shared_ptr<PlayerController> pc;
    Vec2D exit;

public:
    Rule() = default;

    virtual void init(std::shared_ptr<Field> field, std::shared_ptr<PlayerController> pc, Vec2D exit) {
        this->field = field;
        this-> pc = pc;
        this->exit = exit;
    }

    bool end() {
        return condition() && pc->getPos() == exit;
    }

    virtual bool condition() = 0;
};


#endif //RULE_H
