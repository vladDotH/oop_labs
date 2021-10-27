#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include <memory>
#include "cells/Cell.h"
#include "cells/Wall.h"
#include "cells/Entrance.h"
#include "cells/Exit.h"
#include "Field.h"
#include "../loggers/Loggable.h"

class FieldBuilder : public Loggable {
public:
    enum class Type {
        DEFAULT,
        BOX
    };

protected:
    void default_generation(Field &f);

    void box_generation(Field &f);

    Vec2D size;
    Type type;

public:
    FieldBuilder() = default;

    FieldBuilder &setSize(Vec2D size);

    FieldBuilder &setType(Type type);

    std::shared_ptr<Field> build();
};


#endif //FIELDBUILDER_H
