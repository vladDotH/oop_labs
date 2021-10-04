#ifndef FIELDBUILDER_H
#define FIELDBUILDER_H

#include "cells/Cell.h"
#include "cells/Wall.h"
#include "cells/Entrance.h"
#include "cells/Exit.h"
#include "Field.h"

class FieldBuilder {
public:
    enum Type {
        DEFAULT,
        BOX
    };

protected:
    Field default_generation();

    Field box_generation();

    Vec2D size;
    Type type;

public:
    FieldBuilder() = delete;

    FieldBuilder(const Vec2D &size, Type type);

    Field build();
};

#endif //FIELDBUILDER_H
