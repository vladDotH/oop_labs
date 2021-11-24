#ifndef RULE_H
#define RULE_H

#include <memory>
#include "../../../game_lib/field/Field.h"
#include "../../../game_lib/controllers/PlayerController.h"
#include "../../../game_lib/core/Vec2D.h"

class Rule {
protected:
    std::shared_ptr<Field> field;
    std::shared_ptr<PlayerController> pc;
    Vec2D exit;

public:
    Rule(std::shared_ptr<Field> field, std::shared_ptr<PlayerController> pc, Vec2D exit)
            : field(field), pc(pc), exit(exit) {}

    bool end() {
        return condition() && pc->getPos() == exit;
    }

    virtual bool condition() = 0;
};


#endif //RULE_H
