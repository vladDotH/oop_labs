#ifndef _BOTLOGIC_H
#define _BOTLOGIC_H

#include "../field/Field.h"
#include <memory>

class BotLogic {
protected:
    std::shared_ptr<Field> f;
public:
    virtual operator()() = 0;
};


#endif //BOTLOGIC_H
